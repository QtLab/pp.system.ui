/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Control/Msw/MswControl.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"

#include "PP/System/UI/Point.hpp"
#include "PP/System/UI/Rectangle.hpp"
#include "PP/System/UI/Size.hpp"

#include "PP/System/UI/Events/EventArgs.hpp"
#include "PP/System/UI/Events/MouseEventArgs.hpp"
#include "PP/System/UI/Events/PaintEventArgs.hpp"
#include "PP/System/UI/Events/SizeEventArgs.hpp"

#include "PP/System/UI/Graphics/Color.hpp"
#include "PP/System/UI/Graphics/Graphics.hpp"

#include "PP/System/UI/Controls/Control/Control.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            long MswControl::ms_IdCounter = 0;
            
            MswControl::MswControl()
                : m_id(++ms_IdCounter), m_handle(NULL), m_Parent(NULL), m_Position(CW_USEDEFAULT), m_size(CW_USEDEFAULT), m_BackgroundBrush(NULL), m_IsSubclassed(false)
            {
            }

            MswControl::~MswControl()
            {
                destroy();
            }
            
            void MswControl::create(BaseControl* parent)
            {
                m_Parent = (MswControl*)parent;
                if (m_Parent)
                {
                    m_Parent->addControl(this);
                }

                // Reset the window class:
                m_WindowClass.cbSize = sizeof(WNDCLASSEX);
                m_WindowClass.cbClsExtra = 0;
                m_WindowClass.cbWndExtra = 0;
                m_WindowClass.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH);
                m_WindowClass.hCursor = ::LoadCursor(NULL, IDC_ARROW);
                m_WindowClass.hIcon = NULL;
                m_WindowClass.hIconSm = NULL;
                m_WindowClass.hInstance = ::GetModuleHandleA(NULL);
                m_WindowClass.lpfnWndProc = MswStaticWindowProcedure;
                m_WindowClass.lpszClassName = NULL;
                m_WindowClass.lpszMenuName = NULL;
                m_WindowClass.style = 0;

                // Let the control initialize the window class:
                mswInitializeWindowClass(&m_WindowClass);

                bool shouldSubclass = false;
                if (m_WindowClass.lpszClassName)
                {
                    WNDCLASSEX existingClass;
                    if (!::GetClassInfoEx(m_WindowClass.hInstance, m_WindowClass.lpszClassName, &existingClass))
                    {
                        ::RegisterClassEx(&m_WindowClass);
                    }
                    else
                    {
                        shouldSubclass = existingClass.lpfnWndProc != m_WindowClass.lpfnWndProc;
                        m_WindowClass = existingClass;
                    }
                }

                CREATESTRUCT cs;
                cs.cx = m_size.getWidth();
                cs.cy = m_size.getHeight();
                cs.dwExStyle = 0;
                cs.hInstance = m_WindowClass.hInstance;
                cs.hMenu = (HMENU)m_id;
                cs.hwndParent = m_Parent ? (HWND)m_Parent->getHandle() : NULL;
                cs.lpCreateParams = this;
                cs.lpszClass = m_WindowClass.lpszClassName;
                cs.lpszName = m_Caption.c_str();
                cs.style = WS_VISIBLE;
                cs.x = m_Position.getX();
                cs.y = m_Position.getY();

                mswInitializeCreateStruct(&cs);

                if (m_Parent)
                {
                    cs.style |= WS_CHILD;
                }

                RECT rc;
                ::SetRect(&rc, 0, 0, cs.cx, cs.cy);
                ::AdjustWindowRectEx(&rc, cs.style, FALSE, cs.dwExStyle);

                cs.cx = rc.right - rc.left;
                cs.cy = rc.bottom - rc.top;

                m_handle = ::CreateWindowEx(cs.dwExStyle, cs.lpszClass, cs.lpszName, cs.style, 
                    cs.x, cs.y, cs.cx, cs.cy, cs.hwndParent, cs.hMenu, cs.hInstance, cs.lpCreateParams);

                if (m_handle && shouldSubclass)
                {
                    ::SetWindowSubclass(m_handle, MswStaticSubclassProcedure, NULL, (DWORD_PTR)this);
                    m_IsSubclassed = true;
                }
            }

            void MswControl::destroy()
            {
                if (m_BackgroundBrush)
                {
                    ::DeleteObject(m_BackgroundBrush);
                }

                ::DestroyWindow(m_handle);
                
                ::UnregisterClass(m_WindowClass.lpszClassName, m_WindowClass.hInstance);
            }

            void MswControl::update()
            {
                ::UpdateWindow(m_handle);
            }

            void MswControl::invalidate()
            {
                if (m_handle != NULL)
                {
                    ::InvalidateRect(m_handle, NULL, TRUE);
                }
            }

            void MswControl::addControl(BaseControl* child)
            {
                ControlList::iterator it = std::find(m_Childs.begin(), m_Childs.end(), child);
                if (it == m_Childs.end())
                {
                    child->setParent(this);
                    m_Childs.push_back(child);
                }
            }

            BaseControl* MswControl::findControl(long id) const
            {
                for (ControlList::const_iterator it = m_Childs.begin(); it != m_Childs.end(); ++it)
                {
                    BaseControl* control = *it;
                    if (control->getId() == id)
                    {
                        return control;
                    }
                }
                return NULL;
            }

            BaseControl* MswControl::findControl(Handle handle) const
            {
                for (ControlList::const_iterator it = m_Childs.begin(); it != m_Childs.end(); ++it)
                {
                    BaseControl* control = *it;
                    if (control->getHandle() == handle)
                    {
                        return control;
                    }
                }
                return NULL;
            }

            void MswControl::removeControl(BaseControl* child)
            {
                ControlList::iterator it = std::find(m_Childs.begin(), m_Childs.end(), child);
                if (it == m_Childs.end())
                {
                    m_Childs.erase(it);
                }
            }

            long MswControl::getId() const
            {
                return m_id;
            }

            void* MswControl::getHandle() const
            {
                return m_handle;
            }

            BaseControl* MswControl::getParent() const
            {
                return m_Parent;
            }
            
            void MswControl::setParent(BaseControl* parent)
            {
                if (m_Parent != parent)
                {
                    if (m_Parent)
                    {
                        m_Parent->removeControl(this);
                    }

                    m_Parent = (MswControl*)parent;
                    if (m_handle)
                    {
                        if (m_Parent)
                        {
                            ::SetParent(m_handle, (HWND)m_Parent->getHandle());
                            MswSetStyle(WS_CHILD, true);
                            MswSetStyle(WS_POPUP, false);
                        }
                        else
                        {
                            ::SetParent(m_handle, NULL);
                            MswSetStyle(WS_CHILD, false);
                            MswSetStyle(WS_POPUP, true);
                        }
                        
                        UINT flags = SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED;
                        ::SetWindowPos(m_handle, 0, 0, 0, 0, 0, flags);
                    }

                    if (m_Parent)
                    {
                        m_Parent->addControl(this);
                    }
                }
            }

            std::wstring MswControl::getCaption() const
            {
                return m_Caption;
            }
            
            void MswControl::setCaption(const std::wstring& caption)
            {
                m_Caption = caption;
                if (m_handle)
                {
                    ::SetWindowText(m_handle, caption.c_str());
                }
            }

            bool MswControl::isEnabled() const
            {
                return ::IsWindowEnabled(m_handle) == TRUE;
            }

            void MswControl::setEnabled(bool enabled)
            {
                if (m_handle)
                {
                    ::EnableWindow(m_handle, enabled ? TRUE : FALSE);
                }
            }

            Size MswControl::getSize() const
            {
                return m_size;
            }

            void MswControl::setSize(int width, int height)
            {
                setSize(Size(width, height));
            }

            void MswControl::setSize(const Size& size)
            {
                // We only set m_size when there is no handle yet, else the size is set when listening
                // to the WM_SIZE message.

                if (m_handle)
                {
                    ::SetWindowPos(m_handle, NULL, 0, 0, size.getWidth(), size.getHeight(), SWP_NOMOVE);
                }
                else
                {
                    m_size = size;
                }
            }

            Point MswControl::getPosition() const
            {
                return m_Position;
            }
            
            void MswControl::setPosition(int x, int y)
            {
                setPosition(Point(x, y));
            }

            void MswControl::setPosition(const Point& position)
            {
                // We only set m_Position when there is no handle yet, else the position is set when listening
                // to the WM_MOVE message.

                if (m_handle)
                {
                    ::SetWindowPos(m_handle, NULL, m_Position.getX(), m_Position.getY(), 0, 0, SWP_NOSIZE);
                }
                else
                {
                    m_Position = position;
                }
            }
            
            void MswControl::hide()
            {
                ::ShowWindow(m_handle, SW_HIDE);
            }
            
            void MswControl::show()
            {
                ::ShowWindow(m_handle, SW_SHOW);
                ::UpdateWindow(m_handle);
            }

            Color MswControl::getBackgroundColor() const
            {
                return m_BackgroundColor;
            }

            void MswControl::setBackgroundColor(const Color& color)
            {
                m_BackgroundColor = color;
                if (m_BackgroundBrush)
                {
                    ::DeleteObject(m_BackgroundBrush);
                }
                m_BackgroundBrush = ::CreateSolidBrush(RGB(color.getRed(), color.getGreen(), color.getBlue()));
            }

            Color MswControl::getForegroundColor() const
            {
                return m_ForegroundColor;
            }

            void MswControl::setForegroundColor(const Color& color)
            {
                m_ForegroundColor = color;
            }

            void MswControl::mswInitializeWindowClass(WNDCLASSEX* windowClass)
            {
            }

            void MswControl::mswInitializeCreateStruct(CREATESTRUCT* createStruct)
            {
            }

            void MswControl::MswSetStyle(DWORD flag, bool state)
            {
                if (m_handle != NULL)
                {
                    LONG_PTR field = ::GetWindowLongPtr((HWND)m_handle, GWL_STYLE);
                    if (state)
                    {
                        field |= flag;
                    }
                    else
                    {
                        field &= ~flag;
                    }
                    ::SetWindowLongPtr((HWND)m_handle, GWL_STYLE, field);
                }
            }

            void MswControl::MswSetExtendedStyle(DWORD flag, bool state)
            {
                if (m_handle != NULL)
                {
                    LONG_PTR field = ::GetWindowLongPtr((HWND)m_handle, GWL_EXSTYLE);
                    if (state)
                    {
                        field |= flag;
                    }
                    else
                    {
                        field &= ~flag;
                    }
                    ::SetWindowLongPtr((HWND)m_handle, GWL_EXSTYLE, field);
                }
            }

            void MswControl::mswHandleCommandMessage(WPARAM wParam, LPARAM lParam)
            {
                if (lParam)
                {
                    MswControl* control = (MswControl*)findControl((HWND)lParam);
                    if (control)
                    {
                        control->mswHandleCommand(wParam);
                    }
                }
            }

            void MswControl::mswHandleCommand(WPARAM wParam)
            {
            }

            bool MswControl::MswHandleNotification(NMHDR* notificationMsg)
            {
                // @todo
                // http://msdn.microsoft.com/en-us/library/windows/desktop/bb775497(v=vs.85).aspx#messages

                if (notificationMsg->code == NM_SETFOCUS)
                {
                }
                else if (notificationMsg->code == NM_KILLFOCUS)
                {
                }

                return true;
            }

            LRESULT CALLBACK MswControl::mswHandleSystemMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
            {
                switch (uMsg)
                {
                case WM_CREATE:
                    {
                        EventArgs eventArgs;
                        onCreate(eventArgs);
                        break;
                    }
                case WM_DESTROY:
                    {
                        EventArgs eventArgs;
                        onDestroy(eventArgs);
                        break;
                    }
                case WM_NOTIFY:
                    {
                        NMHDR* notificationMsg = (NMHDR*)lParam;
                        MswControl* control = (MswControl*)findControl(notificationMsg->hwndFrom);
                        if (control)
                        {
                            return control->MswHandleNotification(notificationMsg) ? TRUE : FALSE;
                        }
                        break;
                    }
                case WM_COMMAND:
                    {
                        mswHandleCommandMessage(wParam, lParam);
                        break;
                    }
                case WM_MOVE:
                    {
                        m_Position = Point(LOWORD(lParam), HIWORD(lParam));
                        update();
                        break;
                    }
                case WM_SIZE:
                    {
                        m_previousSize = m_size;
                        m_size = Size(LOWORD(lParam), HIWORD(lParam));

                        SizeEventArgs eventArgs(m_size, m_previousSize);

                        onSize(eventArgs);

                        updateAnchors();
                        update();
                        break;
                    }
                case WM_UPDATEUISTATE:
                    {
                        UINT flags = RDW_INVALIDATE | RDW_ALLCHILDREN;
                        ::RedrawWindow(m_handle, NULL, NULL, flags);
                        break;
                    }
                case WM_DRAWITEM:
                    {
                        LPDRAWITEMSTRUCT drawItemStruct = (LPDRAWITEMSTRUCT)lParam;
                        if (drawItemStruct->CtlType != ODT_MENU)
                        {
                            MswControl* child = (MswControl*)findControl(drawItemStruct->CtlID);
                            if (child)
                            {
                                Rectangle clipRectangle;
                                clipRectangle.setBottom(drawItemStruct->rcItem.bottom);
                                clipRectangle.setLeft(drawItemStruct->rcItem.left);
                                clipRectangle.setRight(drawItemStruct->rcItem.right);
                                clipRectangle.setTop(drawItemStruct->rcItem.top);
                                
                                Graphics graphics(drawItemStruct->hDC);
                                PaintEventArgs eventArgs(clipRectangle, graphics);

                                child->onPaint(eventArgs);
                            }
                        }
                        break;
                    }
                case WM_ERASEBKGND:
                    {
                        if (!m_WindowClass.hbrBackground)
                        {
                            Rectangle clipRectangle;
                            //clipRectangle.setBottom(drawItemStruct->rcItem.bottom);
                            //clipRectangle.setLeft(drawItemStruct->rcItem.left);
                            //clipRectangle.setRight(drawItemStruct->rcItem.right);
                            //clipRectangle.setTop(drawItemStruct->rcItem.top);
                                
                            Graphics graphics((HDC)wParam);
                            PaintEventArgs eventArgs(clipRectangle, graphics);

                            onPaintBackground(eventArgs);
                            return FALSE;
                        }
                        break;
                    }
                case WM_PAINT:
                    {
                        // When this control is subclassed, painting will be done by the control it self:
                        if (m_IsSubclassed)
                        {
                            break;
                        }

                        PAINTSTRUCT ps;
                        HDC hdc = BeginPaint(m_handle, &ps);

                        Rectangle clipRectangle;
                        clipRectangle.setBottom(ps.rcPaint.bottom);
                        clipRectangle.setLeft(ps.rcPaint.left);
                        clipRectangle.setRight(ps.rcPaint.right);
                        clipRectangle.setTop(ps.rcPaint.top);

                        Graphics graphics(hdc);
                        PaintEventArgs eventArgs(clipRectangle, graphics);
                        onPaint(eventArgs);

                        EndPaint(m_handle, &ps); 
                        return 0;
                    }
                case WM_CTLCOLORMSGBOX:
                case WM_CTLCOLOREDIT:
                case WM_CTLCOLORLISTBOX:
                case WM_CTLCOLORBTN:
                case WM_CTLCOLORDLG:
                case WM_CTLCOLORSCROLLBAR:
                case WM_CTLCOLORSTATIC:
                    {
                        MswControl* child = (MswControl*)findControl((HWND)lParam);
                        if (child)
                        {
                            HDC hdcStatic = (HDC)wParam;

                            SetTextColor(hdcStatic, RGB(
                                child->m_ForegroundColor.getRed(),
                                child->m_ForegroundColor.getGreen(),
                                child->m_ForegroundColor.getBlue()));

                            SetBkColor(hdcStatic, RGB(
                                child->m_BackgroundColor.getRed(),
                                child->m_BackgroundColor.getGreen(),
                                child->m_BackgroundColor.getBlue()));

                            return (LRESULT)child->m_BackgroundBrush;
                        }
                        break;
                    }
                case WM_MOUSELEAVE:
                    {
                        EventArgs eventArgs;
                        onMouseLeave(eventArgs);
                        break;
                    }
                case WM_MOUSEWHEEL:
                    {
                        MouseEventArgs eventArgs;
                        eventArgs.setDelta(HIWORD(wParam));
                        eventArgs.setX(GET_X_LPARAM(lParam));
                        eventArgs.setY(GET_Y_LPARAM(lParam));
                        onMouseWheel(eventArgs);
                        break;
                    }
                case WM_MOUSEHWHEEL:
                    {
                        MouseEventArgs eventArgs;
                        eventArgs.setDelta(HIWORD(wParam));
                        eventArgs.setX(GET_X_LPARAM(lParam));
                        eventArgs.setY(GET_Y_LPARAM(lParam));
                        onMouseHWheel(eventArgs);
                        break;
                    }
                case WM_MOUSEMOVE:
                    {
                        MouseEventArgs eventArgs;
                        eventArgs.setX(GET_X_LPARAM(lParam));
                        eventArgs.setY(GET_Y_LPARAM(lParam));
                        eventArgs.setLeftDown((wParam & MK_LBUTTON) == MK_LBUTTON);
                        eventArgs.setMiddleDown((wParam & MK_MBUTTON) == MK_MBUTTON);
                        eventArgs.setRightDown((wParam & MK_RBUTTON) == MK_RBUTTON);
                        eventArgs.setXButton1Down((wParam & MK_RBUTTON) == MK_XBUTTON1);
                        eventArgs.setXButton2Down((wParam & MK_RBUTTON) == MK_XBUTTON2);
                        onMouseMove(eventArgs);
                        break;
                    }
                case WM_LBUTTONDOWN:
                case WM_MBUTTONDOWN:
                case WM_RBUTTONDOWN:
                case WM_XBUTTONDOWN:
                    {
                        MouseEventArgs eventArgs;
                        eventArgs.setX(GET_X_LPARAM(lParam));
                        eventArgs.setY(GET_Y_LPARAM(lParam));
                        eventArgs.setLeftDown((wParam & MK_LBUTTON) == MK_LBUTTON);
                        eventArgs.setMiddleDown((wParam & MK_MBUTTON) == MK_MBUTTON);
                        eventArgs.setRightDown((wParam & MK_RBUTTON) == MK_RBUTTON);
                        eventArgs.setXButton1Down((wParam & MK_RBUTTON) == MK_XBUTTON1);
                        eventArgs.setXButton2Down((wParam & MK_RBUTTON) == MK_XBUTTON2);
                        onMouseDown(eventArgs);
                        break;
                    }
                case WM_LBUTTONUP:
                case WM_MBUTTONUP:
                case WM_RBUTTONUP:
                case WM_XBUTTONUP:
                    {
                        MouseEventArgs eventArgs;
                        eventArgs.setX(GET_X_LPARAM(lParam));
                        eventArgs.setY(GET_Y_LPARAM(lParam));
                        eventArgs.setLeftDown((wParam & MK_LBUTTON) == MK_LBUTTON);
                        eventArgs.setMiddleDown((wParam & MK_MBUTTON) == MK_MBUTTON);
                        eventArgs.setRightDown((wParam & MK_RBUTTON) == MK_RBUTTON);
                        eventArgs.setXButton1Down((wParam & MK_RBUTTON) == MK_XBUTTON1);
                        eventArgs.setXButton2Down((wParam & MK_RBUTTON) == MK_XBUTTON2);
                        onMouseUp(eventArgs);
                        break;
                    }
                case WM_LBUTTONDBLCLK:
                case WM_MBUTTONDBLCLK:
                case WM_RBUTTONDBLCLK:
                case WM_XBUTTONDBLCLK:
                    {
                        MouseEventArgs eventArgs;
                        eventArgs.setX(GET_X_LPARAM(lParam));
                        eventArgs.setY(GET_Y_LPARAM(lParam));
                        eventArgs.setLeftDown((wParam & MK_LBUTTON) == MK_LBUTTON);
                        eventArgs.setMiddleDown((wParam & MK_MBUTTON) == MK_MBUTTON);
                        eventArgs.setRightDown((wParam & MK_RBUTTON) == MK_RBUTTON);
                        eventArgs.setXButton1Down((wParam & MK_RBUTTON) == MK_XBUTTON1);
                        eventArgs.setXButton2Down((wParam & MK_RBUTTON) == MK_XBUTTON2);
                        onMouseDoubleClick(eventArgs);
                        break;
                    }
                }

                return 0;
            }

            LRESULT CALLBACK MswControl::MswStaticWindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
            {
                Control* control = NULL;

                if (uMsg == WM_NCCREATE)
                {
                    control = (Control*)(LPCREATESTRUCT(lParam))->lpCreateParams;
                    control->m_handle = hWnd;

                    ::SetWindowLong(hWnd, GWL_USERDATA, (long)control);
                }
                else
                {
                    control = (Control*)::GetWindowLong(hWnd, GWL_USERDATA);
                }

                if (control)
                {
                    LRESULT result = control->mswHandleSystemMessage(uMsg, wParam, lParam);
                    if (result)
                    {
                        return result;
                    }
                }

                return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
            }

            LRESULT CALLBACK MswControl::MswStaticSubclassProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
            {
                if (uMsg == WM_NCDESTROY)
                {
                    ::RemoveWindowSubclass(hWnd, MswStaticSubclassProcedure, uIdSubclass);
                }
                else
                {
                    Control* control = (Control*)dwRefData;
                    if (control)
                    {
                        LRESULT result = control->mswHandleSystemMessage(uMsg, wParam, lParam);
                        if (result)
                        {
                            return result;
                        }
                    }
                }

                return ::DefSubclassProc(hWnd, uMsg, wParam, lParam);
            }

            void MswControl::updateAnchors()
            {
                const bool wChanged = m_size.getWidth() != m_previousSize.getWidth();
                const bool hChanged = m_size.getHeight() != m_previousSize.getHeight();
                
                if (wChanged || hChanged)
                {
                    for (size_t i = 0; i < m_Childs.size(); ++i)
                    {
                        BaseControl* control = m_Childs[i];
                        
                        Point oldPosition = control->getPosition();
                        Point newPosition = oldPosition;

                        Size oldSize = control->getSize();
                        Size newSize = oldSize;

                        // When the control is not anchored at the top but the height changed, we need to 
                        // reposition the control:
                        if (!control->hasAnchor(AnchorTop) && hChanged)
                        {
                            int step = m_size.getHeight() - m_previousSize.getHeight();
                            int value = oldPosition.getY() + step;

                            newPosition.setY(value);
                        }

                        // When the control is not anchored at the left but the width changed, we need to 
                        // reposition the control:
                        if (!control->hasAnchor(AnchorLeft) && wChanged)
                        {
                        }

                        // When the control is anchored at the bottom and the height changed, we need to 
                        // stretch the control:
                        if (control->hasAnchor(AnchorBottom) && hChanged)
                        {
                            int margin = m_previousSize.getHeight() - oldPosition.getY() - oldSize.getHeight();
                            int value = m_size.getHeight() - newPosition.getY() - margin;
                            
                            newSize.setHeight(value);
                        }

                        // When the control is anchored at the right and the width changed, we need to 
                        // stretch the control:
                        if (control->hasAnchor(AnchorRight) && wChanged)
                        {
                            int margin = m_previousSize.getWidth() - oldPosition.getX() - oldSize.getWidth();
                            int value = m_size.getWidth() - newPosition.getX() - margin;

                            newSize.setWidth(value);
                        }

                        if (newSize != oldSize)
                        {
                            control->setSize(newSize);
                        }

                        if (newPosition != oldPosition)
                        {
                            control->setPosition(newPosition);
                        }
                    }
                }
            }
        }
    }
}

/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Window/Msw/MswWindow.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Rectangle.hpp"
#include "PP/System/UI/Point.hpp"
#include "PP/System/UI/Size.hpp"
#include "PP/System/UI/Events/EventArgs.hpp"
#include "PP/System/UI/Events/SizeEventArgs.hpp"
#include "PP/System/UI/Graphics/Color.hpp"
#include "PP/System/UI/Graphics/Graphics.hpp"
#include "PP/System/UI/Application/Application.hpp"
#include "PP/System/UI/Controls/Control/Control.hpp"
#include "PP/System/UI/Controls/Menu/MenuBar.hpp"
#include "PP/System/UI/Controls/Menu/MenuItem.hpp"
#include "PP/System/UI/Controls/Window/Window.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            MswWindow::MswWindow()
                : m_active(false), /*m_statusBar(NULL),*/ m_menuBar(NULL), m_IsToolWindow(false), m_fileAcceptanceEnabled(false),
                m_closeButtonEnabled(true), m_helpButtonEnabled(false), m_maximizeButtonEnabled(true), m_minimizeButtonEnabled(true)
            {
            }

            MswWindow::~MswWindow()
            {
            }

            void MswWindow::close()
            {
                ::PostMessage(m_handle, WM_CLOSE, 0, 0);
            }
            
            StatusBar* MswWindow::getStatusBar() const
            {
                return m_statusBar;
            }

            void MswWindow::setStatusBar(StatusBar* statusBar)
            {
                m_statusBar = statusBar;
            }

            MenuBar* MswWindow::getMenuBar() const
            {
                return m_menuBar;
            }
            
            void MswWindow::setMenuBar(MenuBar* menuBar)
            {
                m_menuBar = menuBar;
                if (m_handle)
                {
                    ::SetMenu(m_handle, (HMENU)menuBar->getHandle());
                }
            }
            
            void MswWindow::onActivate(EventArgs& eventArgs)
            {
                ActivateEvent.Invoke(eventArgs);
            }

            void MswWindow::onDeactivate(EventArgs& eventArgs)
            {
                DeactivateEvent.Invoke(eventArgs);
            }

            void MswWindow::onclose(EventArgs& eventArgs)
            {
                CloseEvent.Invoke(eventArgs);
            }

            void MswWindow::onMaximized(SizeEventArgs& eventArgs)
            {
                MaximizedEvent.Invoke(eventArgs);
            }

            void MswWindow::onMinimized(SizeEventArgs& eventArgs)
            {
                MinimizedEvent.Invoke(eventArgs);
            }

            bool MswWindow::getFileAcceptanceEnabled() const
            {
                return m_fileAcceptanceEnabled;
            }

            void MswWindow::setFileAcceptanceEnabled(bool flag)
            {
                m_fileAcceptanceEnabled = flag;
                MswSetExtendedStyle(WS_EX_ACCEPTFILES, flag);
            }

            bool MswWindow::getCloseButtonEnabled() const
            {
                return m_closeButtonEnabled;
            }

            void MswWindow::setCloseButtonEnabled(bool state)
            {
                m_closeButtonEnabled = state;
                if (m_handle)
                {
                    if (state)
                    {
                        ::EnableMenuItem(GetSystemMenu(m_handle, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_ENABLED);
                    }
                    else
                    {
                        ::EnableMenuItem(GetSystemMenu(m_handle, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
                    }
                }
            }

            bool MswWindow::getHelpButtonEnabled() const
            {
                return m_helpButtonEnabled;
            }

            void MswWindow::setHelpButtonEnabled(bool state)
            {
                m_helpButtonEnabled = state;
            }

            bool MswWindow::getMaximizeButtonEnabled() const
            {
                return m_maximizeButtonEnabled;
            }

            void MswWindow::setMaximizeButtonEnabled(bool state)
            {
                m_maximizeButtonEnabled = state;
                MswSetStyle(WS_MAXIMIZEBOX, state);
            }

            bool MswWindow::getMinimizeButtonEnabled() const
            {
                return m_minimizeButtonEnabled;
            }

            void MswWindow::setMinimizeButtonEnabled(bool state)
            {
                m_minimizeButtonEnabled = state;
                MswSetStyle(WS_MINIMIZEBOX, state);
            }

            bool MswWindow::IsToolWindow() const
            {
                return m_IsToolWindow;
            }

            void MswWindow::SetToolWindow(bool flag)
            {
                m_IsToolWindow = flag;
                MswSetExtendedStyle(WS_EX_TOOLWINDOW, flag);
            }

            void MswWindow::mswInitializeWindowClass(WNDCLASSEX* windowClass)
            {
                windowClass->lpszClassName = TEXT("PP_SYSTEM_UI_WINDOW");
                windowClass->hCursor = ::LoadCursor(windowClass->hInstance, IDC_ARROW);
            }
            
            void MswWindow::mswInitializeCreateStruct(CREATESTRUCT* createStruct)
            {
                createStruct->hMenu = NULL;

                createStruct->style |= WS_OVERLAPPED;
                createStruct->style |= WS_CAPTION;
                createStruct->style |= WS_SYSMENU;
                createStruct->style |= WS_THICKFRAME;
                createStruct->style |= WS_CLIPCHILDREN;

                if (getFileAcceptanceEnabled())
                {
                    createStruct->dwExStyle |= WS_EX_ACCEPTFILES;
                }

                if (getHelpButtonEnabled())
                {
                    createStruct->dwExStyle |= WS_EX_CONTEXTHELP;
                }

                if (IsToolWindow())
                {
                    createStruct->dwExStyle |= WS_EX_TOOLWINDOW | WS_EX_WINDOWEDGE;
                }

                if (getMaximizeButtonEnabled())
                {
                    createStruct->style |= WS_MAXIMIZEBOX;
                }

                if (getMinimizeButtonEnabled())
                {
                    createStruct->style |= WS_MINIMIZEBOX;
                }
            }

            LRESULT CALLBACK MswWindow::mswHandleSystemMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
            {
                LRESULT result = MswControl::mswHandleSystemMessage(uMsg, wParam, lParam);

                switch (uMsg)
                {
                case WM_CREATE:
                    {
                        update();
                        break;
                    }
                case WM_ACTIVATE:
                    {
                        m_active = !(LOWORD(wParam) == WA_INACTIVE);
                        if (m_active)
                        {
                            EventArgs eventArgs;
                            onActivate(eventArgs);
                        }
                        else
                        {
                            EventArgs eventArgs;
                            onDeactivate(eventArgs);
                        }
                        break;
                    }
                case WM_CLOSE:
                    {
                        EventArgs eventArgs;
                        onclose(eventArgs);

                        if (GetApplication()->isMainWindow(this))
                        {
                            GetApplication()->exit();
                        }
                        break;
                    }
                case WM_SIZE:
                    {
                        if (wParam == SIZE_MAXIMIZED)
                        {
                            SizeEventArgs eventArgs(m_size, m_previousSize);
                            onMaximized(eventArgs);
                        }
                        else if (wParam == SIZE_MINIMIZED)
                        {
                            SizeEventArgs eventArgs(m_size, m_previousSize);
                            onMinimized(eventArgs);
                        }

                        break;
                    }
                }

                return result;
            }
            
            void MswWindow::mswHandleCommandMessage(WPARAM wParam, LPARAM lParam)
            {
                if (!lParam)
                {
                    WORD id = LOWORD(wParam);
                    WORD msgType = HIWORD(wParam);

                    if (msgType == 0)
                    {
                        // This is a menu message:
                        MenuItem* menuItem = m_menuBar->findItem(id);
                        if (menuItem != NULL)
                        {
                            menuItem->performClick();
                        }
                    }
                    else if (msgType == 1)
                    {
                        // This is an accelerator:
                    }
                }

                return Control::mswHandleCommandMessage(wParam, lParam);
            }
            
            void MswWindow::mswHandleCommand(WPARAM wParam)
            {
            }

            void MswWindow::update()
            {
                MswControl::update();

                //if (m_statusBar)
                //{
                //    HWND handle = (HWND)m_statusBar->getHandle();
                //    ::SetWindowPos(handle, NULL, 0, 0, 0, 0, SWP_SHOWWINDOW);
                //
                //    invalidate();
                //    m_statusBar->invalidate();
                //}
            }
        }
    }
}

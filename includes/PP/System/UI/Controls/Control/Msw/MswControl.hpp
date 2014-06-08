/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Control/Msw/MswControl.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_CONTROL_MSW_MSWCONTROL_HPP
#define PP_SYSTEM_UI_CONTROLS_CONTROL_MSW_MSWCONTROL_HPP

#include "PP/System/UI/Point.hpp"
#include "PP/System/UI/Rectangle.hpp"
#include "PP/System/UI/Size.hpp"
#include "PP/System/UI/Graphics/Color.hpp"

#include <vector>

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class Color;
            class PaintEventArgs;
            class Point;
            class Size;

            /**
             * The Windows implementation of a control.
             */
            class MswControl: public BaseControl
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 */
                MswControl();
                
                /**
                 * Cleans up all the resources used by this class.
                 */
                virtual ~MswControl();
                
                /**
                 * Creates the control.
                 *
                 * @param[in] parent An optional parent control.
                 */
                virtual void create(BaseControl* parent = NULL);
                
                /**
                 * Destroyes the control.
                 */
                virtual void destroy();

                /**
                 * Updates the control.
                 */
                virtual void update();

                /**
                 * Redraws the control.
                 */
                virtual void invalidate();
                
                /**
                 * Adds a child to this control.
                 *
                 * @param[in] child The control to add.
                 */
                virtual void addControl(BaseControl* child);
                
                /**
                 * Tries to find a control with the given id.
                 *
                 * @param[in] id The id of the control to find.
                 * @return Returns NULL when no control is found; else the control is returned.
                 */
                virtual BaseControl* findControl(long id) const;
                
                /**
                 * Tries to find a control with the given system handle.
                 *
                 * @param[in] handle The system handle of the control to find.
                 * @return Returns NULL when no control is found; else the control is returned.
                 */
                virtual BaseControl* findControl(void* handle) const;

                /**
                 * Removes the given control.
                 *
                 * @param[in] child The child control to remove.
                 */
                virtual void removeControl(BaseControl* child);
                
                /**
                 * Gets the id of the control.
                 *
                 * @return Returns a long value representing the id of the control.
                 */
                virtual long getId() const;
                
                /**
                 * Gets the system handle of the control.
                 *
                 * @return Returns the system handle of the control.
                 */
                virtual Handle getHandle() const;
                
                /**
                 * Gets the parent control of this control.
                 *
                 * @return Returns the parent control.
                 */
                virtual BaseControl* getParent() const;
                
                /**
                 * Gets the parent control of this control.
                 *
                 * @param[in] parent The parent to set.
                 */
                virtual void setParent(BaseControl* parent);

                /**
                 * Gets the caption of the control.
                 *
                 * @return Returns a string representing the caption of this control.
                 */
                virtual std::wstring getCaption() const;
                
                /**
                 * Sets the caption of the control.
                 *
                 * @param[in] caption The caption to set.
                 */
                virtual void setCaption(const std::wstring& caption);

                /**
                 * Checks if the control is enabled or disabled.
                 *
                 * @return Returns true when the control is enabled; false otherwise.
                 */
                virtual bool isEnabled() const;

                /**
                 * Enables or disables the control.
                 *
                 * @param[in] enabled The flag to set.
                 */
                virtual void setEnabled(bool enabled);
                
                /**
                 * Gets the size of the control.
                 *
                 * @return Returns the size of the control.
                 */
                virtual Size getSize() const;

                /**
                 * Sets the size of the control.
                 *
                 * @param[in] width The width to set.
                 * @param[in] height The height to set.
                 */
                virtual void setSize(int width, int height);

                /**
                 * Sets the size of the control.
                 *
                 * @param[in] size The size to set.
                 */
                virtual void setSize(const Size& size);

                /**
                 * Gets the position of the control.
                 *
                 * @return Returns the position of the control.
                 */
                virtual Point getPosition() const;

                /**
                 * Sets the position of the control.
                 *
                 * @param[in] x The X-position of the control.
                 * @param[in] y The Y-position of the control.
                 */
                virtual void setPosition(int x, int y);

                /**
                 * Sets the position of the control.
                 *
                 * @param[in] position The position to set.
                 */
                virtual void setPosition(const Point& position);

                /**
                 * Hides the control when it's shown.
                 */
                virtual void hide();

                /**
                 * Shows the control when it's hidden.
                 */
                virtual void show();
                
                /**
                 * Gets the background color of the control.
                 *
                 * @return Returns the background color of the control.
                 */
                virtual Color getBackgroundColor() const;

                /**
                 * Sets the background color of the control.
                 *
                 * @param[in] color The color to set.
                 */
                virtual void setBackgroundColor(const Color& color);
                
                /**
                 * Gets the foreground color of the control.
                 *
                 * @return Returns the foreground color of the control.
                 */
                virtual Color getForegroundColor() const;

                /**
                 * Sets the foreground color of the control.
                 *
                 * @param[in] color The color to set.
                 */
                virtual void setForegroundColor(const Color& color);

            protected:
                /**
                 * Updates all anchored child controls.
                 */
                virtual void updateAnchors();

                /**
                 * Initializes the MSW window class.
                 *
                 * @param[in] windowClass The window class to initialize.
                 */
                virtual void mswInitializeWindowClass(WNDCLASSEX* windowClass);
                
                /**
                 * Initializes the MSW creation struct.
                 *
                 * @param[in] createStruct The struct to initialize.
                 */
                virtual void mswInitializeCreateStruct(CREATESTRUCT* createStruct);

                void MswSetStyle(DWORD flag, bool state);
                void MswSetExtendedStyle(DWORD flag, bool state);

                /**
                 * Handles a system message for this control.
                 *
                 * @param[in] uMsg The message to handle.
                 * @param[in] wParam The first argument.
                 * @param[in] lParam The second argument.
                 * @return Returns the result of the handled message.
                 */
                virtual LRESULT CALLBACK mswHandleSystemMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

                /**
                 * A helper function that handles a command message.
                 *
                 * @param[in] wParam The first argument.
                 * @param[in] lParam The second argument.
                 */
                virtual void mswHandleCommandMessage(WPARAM wParam, LPARAM lParam);

                /**
                 * A helper function used to handle a command.
                 *
                 * @param[in] wParam The first argument.
                 */
                virtual void mswHandleCommand(WPARAM wParam);

                /**
                 * Handles a notification message.
                 *
                 * @param[in] notificationMsg The notification message.
                 * @return Returns true if the message is handled; false otherwise.
                 */
                virtual bool MswHandleNotification(NMHDR* notificationMsg);

                /**
                 * The static window procedure that handles all global messages.
                 *
                 * @param[in] hWnd The handle of the control to handle the message for.
                 * @param[in] uMsg The message to handle.
                 * @param[in] wParam The first argument.
                 * @param[in] lParam The second argument.
                 * @return Returns the result of the handled message.
                 */
                static LRESULT CALLBACK MswStaticWindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

                /**
                 * The static window procedure that is used when a window is subclassed.
                 *
                 * @param[in] hWnd The handle of the control to handle the message for.
                 * @param[in] uMsg The message to handle.
                 * @param[in] wParam The first argument.
                 * @param[in] lParam The second argument.
                 * @param[in] uIdSubclass The id of the subclass.
                 * @param[in] dwRefData Optional data.
                 * @return Returns the result of the handled message.
                 */
                static LRESULT CALLBACK MswStaticSubclassProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);

                /** The window class for this control. */
                WNDCLASSEX m_WindowClass;
                
                /** The handle of this control. */
                HWND m_handle;
                
                /** The foreground color of the control. */
                Color m_ForegroundColor;
                
                /** The background color of the control. */
                Color m_BackgroundColor;

                /** The background brush used to draw the background. */
                HBRUSH m_BackgroundBrush;

                /** A flag indicating whether or not the control is subclassed. */
                bool m_IsSubclassed;

                /** The id of the control. */
                long m_id;

                /** A static id counter used to increase the id number accross controls. */
                static long ms_IdCounter;

                /** The parent control */
                MswControl* m_Parent;

                /** The child controls of this control. */
                ControlList m_Childs;

                /** The caption of this control. */
                std::wstring m_Caption;

                /** The current position of the control. */
                Point m_Position;

                /** The size of the control. */
                Size m_size;

                /** The previous size, used to resize controls and keeping the ratio. */
                Size m_previousSize;
            };

            /** The type definition that represents a Control. */
            typedef MswControl Control;
        }
    }
}

#endif

/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Window/Msw/MswWindow.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_WINDOW_MSW_MSWWINDOW_HPP
#define PP_SYSTEM_UI_CONTROLS_WINDOW_MSW_MSWWINDOW_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class BaseWindow;
            class MenuBar;
            class MenuItem;
            class StatusBar;

            class MswWindow: public BaseWindow
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] parent The parent of the button.
                 */
                MswWindow();
                
                /**
                 * Cleans up all the resources used by this class.
                 */
                virtual ~MswWindow();

                /**
                 * Updates the control.
                 */
                virtual void update();
                
                /**
                 * Closes the window.
                 */
                virtual void close();
                
                /**
                 * Gets the status bar of the window.
                 *
                 * @return Returns the instance of the status bar.
                 */
                virtual StatusBar* getStatusBar() const;

                /**
                 * Sets the status bar of the window.
                 *
                 * @param[in] statusBar The status bar to set.
                 */
                virtual void setStatusBar(StatusBar* statusBar);
                
                /**
                 * Gets the menu bar of the window.
                 *
                 * @return Returns the instance of the menu bar.
                 */
                virtual MenuBar* getMenuBar() const;

                /**
                 * Sets the menu bar of the window.
                 *
                 * @param[in] menuBar The menu bar to set.
                 */
                virtual void setMenuBar(MenuBar* menuBar);
                
                virtual bool getFileAcceptanceEnabled() const;
                virtual void setFileAcceptanceEnabled(bool state);

                virtual bool getCloseButtonEnabled() const;
                virtual void setCloseButtonEnabled(bool state);

                virtual bool getHelpButtonEnabled() const;
                virtual void setHelpButtonEnabled(bool state);

                virtual bool getMaximizeButtonEnabled() const;
                virtual void setMaximizeButtonEnabled(bool state);

                virtual bool getMinimizeButtonEnabled() const;
                virtual void setMinimizeButtonEnabled(bool state);

                virtual bool IsToolWindow() const;
                virtual void SetToolWindow(bool state);

            protected:
                /**
                 * Called when the window is activated.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onActivate(EventArgs& eventArgs);
                
                /**
                 * Called when the window is deactivated.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onDeactivate(EventArgs& eventArgs);

                /**
                 * Called when the window is closed.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onclose(EventArgs& eventArgs);
                
                /**
                 * Called when the window is maximized.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMaximized(SizeEventArgs& eventArgs);
                
                /**
                 * Called when the window is minimized.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMinimized(SizeEventArgs& eventArgs);
                
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

            private:
                /** The menu bar of the window. */
                MenuBar* m_menuBar;
                
                /** The status bar of the window. */
                StatusBar* m_statusBar;

                /** Whether or not the window is active. */
                bool m_active;

                /** Whether or not this window is a tool window. */
                bool m_IsToolWindow;

                bool m_fileAcceptanceEnabled;
                bool m_closeButtonEnabled;
                bool m_helpButtonEnabled;
                bool m_maximizeButtonEnabled;
                bool m_minimizeButtonEnabled;
            };

            typedef MswWindow Window;
        }
    }
}

#endif

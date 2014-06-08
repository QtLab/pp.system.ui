/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Window/BaseWindow.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_WINDOW_BASEWINDOW_HPP
#define PP_SYSTEM_UI_CONTROLS_WINDOW_BASEWINDOW_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class MenuBar;
            class MenuItem;
            class StatusBar;

            /**
             * The base class for all windows.
             */
            class BaseWindow: public Control
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] parent The parent of the button.
                 */
                BaseWindow();
                
                /**
                 * Cleans up all the resources used by this class.
                 */
                virtual ~BaseWindow();
                
                /**
                 * Closes the window.
                 */
                virtual void close() = 0;
                
                /**
                 * Gets the status bar of the window.
                 *
                 * @return Returns the instance of the status bar.
                 */
                virtual StatusBar* getStatusBar() const = 0;

                /**
                 * Sets the status bar of the window.
                 *
                 * @param[in] statusBar The status bar to set.
                 */
                virtual void setStatusBar(StatusBar* statusBar) = 0;
                
                /**
                 * Gets the menu bar of the window.
                 *
                 * @return Returns the instance of the menu bar.
                 */
                virtual MenuBar* getMenuBar() const = 0;

                /**
                 * Sets the menu bar of the window.
                 *
                 * @param[in] menuBar The menu bar to set.
                 */
                virtual void setMenuBar(MenuBar* menuBar) = 0;
                
                virtual bool getFileAcceptanceEnabled() const = 0;
                virtual void setFileAcceptanceEnabled(bool state) = 0;

                virtual bool getCloseButtonEnabled() const = 0;
                virtual void setCloseButtonEnabled(bool state) = 0;

                virtual bool getHelpButtonEnabled() const = 0;
                virtual void setHelpButtonEnabled(bool state) = 0;

                virtual bool getMaximizeButtonEnabled() const = 0;
                virtual void setMaximizeButtonEnabled(bool state) = 0;

                virtual bool getMinimizeButtonEnabled() const = 0;
                virtual void setMinimizeButtonEnabled(bool state) = 0;

                virtual bool IsToolWindow() const = 0;
                virtual void SetToolWindow(bool state) = 0;

            protected:
                /**
                 * Called when the window is activated.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onActivate(EventArgs& eventArgs) = 0;
                
                /**
                 * Called when the window is deactivated.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onDeactivate(EventArgs& eventArgs) = 0;
                
                /**
                 * Called when the window is closed.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onclose(EventArgs& eventArgs) = 0;
                
                /**
                 * Called when the window is maximized.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMaximized(SizeEventArgs& eventArgs) = 0;
                
                /**
                 * Called when the window is minimized.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMinimized(SizeEventArgs& eventArgs) = 0;

            public:
                Event<EventArgs&> ActivateEvent;
                Event<EventArgs&> CloseEvent;
                Event<EventArgs&> DeactivateEvent;
                Event<SizeEventArgs&> MaximizedEvent;
                Event<SizeEventArgs&> MinimizedEvent;
            };
        }
    }
}

#endif

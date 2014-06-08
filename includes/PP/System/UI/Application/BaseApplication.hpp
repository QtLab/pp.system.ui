/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Application/BaseApplication.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_APPLICATION_BASEAPPLICATION_HPP
#define PP_SYSTEM_UI_APPLICATION_BASEAPPLICATION_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class BaseWindow;

            /**
             * The application class should be inherited in order to create a new application.
             */
            class BaseApplication
            {
                friend class BaseWindow;

            public:
                /**
                 * Initializes a new instance of this class.
                 */
                BaseApplication();

                /**
                 * Cleans up all the resources used by this class.
                 */
                virtual ~BaseApplication();
                
                /**
                 * Exits the application.
                 */
                virtual void exit() = 0;
                
                /**
                 * Exits the application.
                 *
                 * @param[in] code The exit code of the application.
                 */
                virtual void exit(int code) = 0;

                /**
                 * Runs the application.
                 *
                 * @return Returns the exit code of the application.
                 */
                virtual int run() = 0;

                /**
                 * Checks if the given window is the main window.
                 *
                 * @param[in] window The window to check.
                 * @return Returns true when the given window is the main window; false otherwise.
                 */
                bool isMainWindow(BaseWindow* window) const;

            protected:
                /**
                 * Called when the application should be initialized.
                 *
                 * @return Returns true when initializing succeeded; false otherwise.
                 */
                virtual bool onInitialize() = 0;
                
                /**
                 * Called when the application should be terminated.
                 *
                 * @return Returns true when terminating succeeded; false otherwise.
                 */
                virtual bool onTerminate() = 0;

                /** The main window of the application which is the first window that is created. */
                static BaseWindow* ms_mainWindow;
            };

            /**
             * Gets the instance of the application.
             *
             * @return Returns the instance of the application.
             */
            BaseApplication* GetApplication();
        }
    }
}

#endif

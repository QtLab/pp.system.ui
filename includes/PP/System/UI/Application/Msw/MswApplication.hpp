/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Application/Msw/MswApplication.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_APPLICATION_MSW_MSWAPPLICATION_HPP
#define PP_SYSTEM_UI_APPLICATION_MSW_MSWAPPLICATION_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class BaseApplication;

            /**
             * The windows version of the application.
             */
            class MswApplication: public BaseApplication
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 */
                MswApplication();

                /**
                 * Cleans up all the resources used by this class.
                 */
                virtual ~MswApplication();
                
                /**
                 * Exits the application.
                 */
                virtual void exit();
                
                /**
                 * Exits the application.
                 *
                 * @param[in] code The exit code of the application.
                 */
                virtual void exit(int code);

                /**
                 * Runs the application.
                 *
                 * @return Returns the exit code of the application.
                 */
                virtual int run();

            protected:
                /**
                 * Called when the application should be initialized.
                 *
                 * @return Returns true when initializing succeeded; false otherwise.
                 */
                virtual bool onInitialize();
                
                /**
                 * Called when the application should be terminated.
                 *
                 * @return Returns true when terminating succeeded; false otherwise.
                 */
                virtual bool onTerminate();
            };
            
            typedef MswApplication Application;
        }
    }
}

#endif

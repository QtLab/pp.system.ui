/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Application/Application.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_APPLICATION_APPLICATION_HPP
#define PP_SYSTEM_UI_APPLICATION_APPLICATION_HPP

#include "PP/System/UI/Application/BaseApplication.hpp"

#ifdef PP_SYSTEM_WINDOWS
    #include "PP/System/UI/Application/Msw/MswApplication.hpp"

    #define PP_SYSTEM_UI_MAIN(AppClass) \
        namespace PP { namespace System { namespace UI { \
            PP::System::UI::BaseApplication* GetApplication() { \
                static AppClass application; \
                return &application; \
            } \
        } } } \
        int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) { \
            PP::System::UI::BaseApplication* application = PP::System::UI::GetApplication(); \
            return application->run(); \
        }
#endif

#endif

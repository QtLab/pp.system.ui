/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Application/Application.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Rectangle.hpp"
#include "PP/System/UI/Point.hpp"
#include "PP/System/UI/Size.hpp"
#include "PP/System/UI/Graphics/Color.hpp"
#include "PP/System/UI/Graphics/Graphics.hpp"
#include "PP/System/UI/Controls/Control/Control.hpp"
#include "PP/System/UI/Controls/Window/Window.hpp"
#include "PP/System/UI/Application/Application.hpp"

#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

namespace PP
{
    namespace System
    {
        namespace UI
        {
            MswApplication::MswApplication()
            {
            }

            MswApplication::~MswApplication()
            {
            }

            void MswApplication::exit()
            {
                exit(0);
            }

            void MswApplication::exit(int code)
            {
                ::PostQuitMessage(code);
            }

            int MswApplication::run()
            {
                int exitCode = 1;
                if (onInitialize())
                {
                    HWND handle = BaseApplication::ms_mainWindow ? (HWND)BaseApplication::ms_mainWindow->getHandle() : NULL;

                    MSG msg;
                    while (::GetMessage(&msg, NULL, 0, 0) > 0)
                    {
                        ::TranslateMessage(&msg);
                        ::DispatchMessage(&msg);
                    }
                    exitCode = (int)msg.wParam;

                    onTerminate();
                }
                return exitCode;
            }

            bool MswApplication::onInitialize()
            {
                return true;
            }

            bool MswApplication::onTerminate()
            {
                return true;
            }
        }
    }
}

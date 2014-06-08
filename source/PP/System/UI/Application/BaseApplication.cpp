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

namespace PP
{
    namespace System
    {
        namespace UI
        {
            BaseWindow* BaseApplication::ms_mainWindow = NULL;

            BaseApplication::BaseApplication()
            {
            }

            BaseApplication::~BaseApplication()
            {
            }

            bool BaseApplication::isMainWindow(BaseWindow* window) const
            {
                return ms_mainWindow == window;
            }
        }
    }
}

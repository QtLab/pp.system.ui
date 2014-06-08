/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Window/Window.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Rectangle.hpp"
#include "PP/System/UI/Point.hpp"
#include "PP/System/UI/Size.hpp"
#include "PP/System/UI/Graphics/Color.hpp"
#include "PP/System/UI/Graphics/Graphics.hpp"
#include "PP/System/UI/Application/Application.hpp"
#include "PP/System/UI/Controls/Control/Control.hpp"
#include "PP/System/UI/Controls/Menu/MenuBar.hpp"
#include "PP/System/UI/Controls/Window/Window.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            BaseWindow::BaseWindow()
            {
                if (!BaseApplication::ms_mainWindow)
                {
                    BaseApplication::ms_mainWindow = this;
                }
            }

            BaseWindow::~BaseWindow()
            {
            }
        }
    }
}

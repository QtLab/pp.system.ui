/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Events/PaintEventArgs.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Rectangle.hpp"
#include "PP/System/UI/Graphics/Graphics.hpp"
#include "PP/System/UI/Events/EventArgs.hpp"
#include "PP/System/UI/Events/PaintEventArgs.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            PaintEventArgs::PaintEventArgs(const Rectangle& clipRectangle, const Graphics& graphics)
                : m_clipRectangle(clipRectangle), m_graphics(graphics)
            {
            }

            PaintEventArgs::~PaintEventArgs()
            {
            }

            Rectangle PaintEventArgs::getClipRectangle() const
            {
                return m_clipRectangle;
            }

            Graphics PaintEventArgs::getGraphics() const
            {
                return m_graphics;
            }
        }
    }
}

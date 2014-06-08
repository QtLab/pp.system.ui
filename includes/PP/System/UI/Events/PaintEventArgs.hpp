/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Events/PaintEventArgs.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_EVENTS_PAINTEVENTARGS_HPP
#define PP_SYSTEM_UI_EVENTS_PAINTEVENTARGS_HPP

#include "PP/System/UI/Rectangle.hpp"
#include "PP/System/UI/Graphics/Graphics.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class Rectangle;
            class Graphics;

            class PaintEventArgs
            {
            public:
                PaintEventArgs(const Rectangle& clipRectangle, const Graphics& graphics);
                ~PaintEventArgs();
                
                Rectangle getClipRectangle() const;
                Graphics getGraphics() const;

            private:
                Rectangle m_clipRectangle;
                Graphics m_graphics;
            };
        }
    }
}

#endif

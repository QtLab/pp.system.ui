/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Graphics/Graphics.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_GRAPHICS_GRAPHICS_HPP
#define PP_SYSTEM_UI_GRAPHICS_GRAPHICS_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class Rectangle;
            class Color;

            class Graphics
            {
            public:
                Graphics(HDC hdc);
                virtual ~Graphics();

                virtual Color getPixel(int x, int y) const;
                virtual void setPixel(int x, int y, const Color& color);

                virtual void drawLine(int x1, int y1, int x2, int y2);
                
                virtual void drawRect(int x, int y, int width, int height, const Color& color);
                virtual void drawRect(const Rectangle& rectangle, const Color& color);

                virtual void drawString(int x, int y, const LPCTSTR text);

                virtual void drawXorBar(int x, int y, int width, int height);
                
                virtual void fillCircle(int x, int y, int radius, const Color& color);
                virtual void fillCircle(const Point& point, int radius, const Color& color);
                virtual void fillCircle(const Rectangle& rectangle, const Color& color);
                
                virtual void fillRect(int x, int y, int width, int height, const Color& color);
                virtual void fillRect(const Rectangle& rectangle, const Color& color);

            private:
                HDC m_HDC;
            };
        }
    }
}

#endif

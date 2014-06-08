/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Graphics/Graphics.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Point.hpp"
#include "PP/System/UI/Rectangle.hpp"
#include "PP/System/UI/Size.hpp"
#include "PP/System/UI/Graphics/Color.hpp"
#include "PP/System/UI/Graphics/Graphics.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            Graphics::Graphics(HDC hdc)
                : m_HDC(hdc)
            {
            }

            Graphics::~Graphics()
            {
            }
            

            Color Graphics::getPixel(int x, int y) const
            {
                COLORREF color = ::GetPixel(m_HDC, x, y);

                return Color(GetRValue(color), GetGValue(color), GetBValue(color));
            }

            void Graphics::setPixel(int x, int y, const Color& color)
            {
                ::SetPixel(m_HDC, x, y, RGB(color.getRed(), color.getGreen(), color.getBlue()));
            }

            void Graphics::drawLine(int x1, int y1, int x2, int y2)
            {
                ::MoveToEx(m_HDC, x1, y1, NULL);
                ::LineTo(m_HDC, x2, y2);
            }

            void Graphics::drawRect(int x, int y, int width, int height, const Color& color)
            {
                drawRect(Rectangle(x, y, width, height), color);
            }

            void Graphics::drawRect(const Rectangle& rectangle, const Color& color)
            {
                RECT rect;
                rect.bottom = rectangle.getBottom();
                rect.left = rectangle.getLeft();
                rect.right = rectangle.getRight();
                rect.top = rectangle.getTop();
                
                HBRUSH brush = ::CreateSolidBrush(RGB(color.getRed(), color.getGreen(), color.getBlue()));
                ::FrameRect(m_HDC, &rect, brush);
                ::DeleteObject(brush);
            }

            void Graphics::drawString(int x, int y, const LPCTSTR text)
            {
                const TCHAR* ptr = text;
                int length = 0;
                while (ptr && *ptr)
                {
                    length++;
                    ptr++;
                }
                ::TextOut(m_HDC, x, y, text, length);
            }
            
            void Graphics::drawXorBar(int x, int y, int width, int height)
            {
                static WORD _dotPatternBmp[8] = 
                { 
                    0x00aa, 0x0055, 0x00aa, 0x0055, 
                    0x00aa, 0x0055, 0x00aa, 0x0055
                };

                HBITMAP hbm = CreateBitmap(8, 8, 1, 1, _dotPatternBmp);
                HBRUSH  hbr, hbrushOld;

                hbr = CreatePatternBrush(hbm);
    
                SetBrushOrgEx(m_HDC, x, y, 0);
                hbrushOld = (HBRUSH)SelectObject(m_HDC, hbr);
    
                PatBlt(m_HDC, x, y, width, height, PATINVERT);
    
                SelectObject(m_HDC, hbrushOld);
    
                DeleteObject(hbr);
                DeleteObject(hbm);
            }

            void Graphics::fillCircle(int x, int y, int radius, const Color& color)
            {
                fillCircle(Point(x, y), radius, color);
            }

            void Graphics::fillCircle(const Point& point, int radius, const Color& color)
            {
                int x = point.getX() - radius;
                int y = point.getY() - radius;
                int width = radius + radius;
                int height = radius + radius;

                fillCircle(Rectangle(x, y, width, height), color);
            }

            void Graphics::fillCircle(const Rectangle& rectangle, const Color& color)
            {
                HBRUSH brush = ::CreateSolidBrush(RGB(color.getRed(), color.getGreen(), color.getBlue()));
                ::SelectObject(m_HDC, brush);
                ::Ellipse(m_HDC, rectangle.getLeft(), rectangle.getTop(), rectangle.getRight(), rectangle.getBottom());
                ::DeleteObject(brush);
            }

            void Graphics::fillRect(int x, int y, int width, int height, const Color& color)
            {
                fillRect(Rectangle(x, y, width, height), color);
            }

            void Graphics::fillRect(const Rectangle& rectangle, const Color& color)
            {
                RECT rect;
                rect.bottom = rectangle.getBottom();
                rect.left = rectangle.getLeft();
                rect.right = rectangle.getRight();
                rect.top = rectangle.getTop();

                HBRUSH brush = ::CreateSolidBrush(RGB(color.getRed(), color.getGreen(), color.getBlue()));
                ::FillRect(m_HDC, &rect, brush);
                ::DeleteObject(brush);
            }
        }
    }
}

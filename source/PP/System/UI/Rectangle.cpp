/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Rectangle.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Size.hpp"
#include "PP/System/UI/Point.hpp"
#include "PP/System/UI/Rectangle.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            Rectangle::Rectangle()
                : m_bottom(0), m_left(0), m_right(0), m_top(0)
            {
            }

            Rectangle::Rectangle(const Rectangle& rectangle)
                : m_bottom(0), m_left(0), m_right(0), m_top(0)
            {
                *this = rectangle;
            }

            Rectangle::Rectangle(int x, int y, int width, int height)
                : m_bottom(y + height), m_left(x), m_right(x + width), m_top(y)
            {
            }

            Rectangle::~Rectangle()
            {
            }

            Rectangle& Rectangle::operator =(const Rectangle& rectangle)
            {
                if (&rectangle != this)
                {
                    m_bottom = rectangle.m_bottom;
                    m_left = rectangle.m_left;
                    m_right = rectangle.m_right;
                    m_top = rectangle.m_top;
                }
                return *this;
            }

            Point Rectangle::getLocation() const
            {
                return Point(m_left, m_top);
            }

            Size Rectangle::getSize() const
            {
                return Size(m_right - m_left, m_bottom - m_top);
            }

            int Rectangle::getWidth() const
            {
                return m_right - m_left;
            }

            int Rectangle::getHeight() const
            {
                return m_bottom - m_top;
            }

            int Rectangle::getBottom() const
            {
                return m_bottom;
            }

            int Rectangle::getLeft() const
            {
                return m_left;
            }

            int Rectangle::getRight() const
            {
                return m_right;
            }

            int Rectangle::getTop() const
            {
                return m_top;
            }

            void Rectangle::setBottom(int bottom)
            {
                m_bottom = bottom;
            }

            void Rectangle::setLeft(int left)
            {
                m_left = left;
            }

            void Rectangle::setRight(int right)
            {
                m_right = right;
            }

            void Rectangle::setTop(int top)
            {
                m_top = top;
            }
        }
    }
}

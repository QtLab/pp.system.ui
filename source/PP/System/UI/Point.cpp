/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Point.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Point.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            Point::Point()
                : m_x(0), m_y(0)
            {
            }

            Point::Point(const Point& point)
                : m_x(0), m_y(0)
            {
                *this = point;
            }

            Point::Point(int value)
                : m_x(value), m_y(value)
            {
            }

            Point::Point(int x, int y)
                : m_x(x), m_y(y)
            {
            }

            Point::~Point()
            {
            }

            Point& Point::operator =(const Point& point)
            {
                if (&point != this)
                {
                    m_x = point.m_x;
                    m_y = point.m_y;
                }
                return *this;
            }

            int Point::getX() const
            {
                return m_x;
            }

            void Point::setX(int x)
            {
                m_x = x;
            }

            int Point::getY() const
            {
                return m_y;
            }

            void Point::setY(int y)
            {
                m_y = y;
            }

            bool operator ==(const Point& left, const Point& right)
            {
                return left.getX() == right.getX() && left.getY() == right.getY();
            }

            bool operator !=(const Point& left, const Point& right)
            {
                return left.getX() != right.getX() || left.getY() != right.getY();
            }
        }
    }
}

/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Size.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Size.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            Size::Size()
                : m_Width(0), m_Height(0)
            {
            }

            Size::Size(const Size& size)
                : m_Width(0), m_Height(0)
            {
                *this = size;
            }

            Size::Size(int value)
                : m_Width(value), m_Height(value)
            {
            }

            Size::Size(int width, int height)
                : m_Width(width), m_Height(height)
            {
            }

            Size::~Size()
            {
            }

            Size& Size::operator =(const Size& size)
            {
                if (&size != this)
                {
                    m_Width = size.m_Width;
                    m_Height = size.m_Height;
                }
                return *this;
            }

            int Size::getWidth() const
            {
                return m_Width;
            }

            void Size::setWidth(int width)
            {
                m_Width = width;
            }

            int Size::getHeight() const
            {
                return m_Height;
            }

            void Size::setHeight(int height)
            {
                m_Height = height;
            }

            bool operator ==(const Size& left, const Size& right)
            {
                return left.getHeight() == right.getHeight() && left.getWidth() == right.getWidth();
            }

            bool operator !=(const Size& left, const Size& right)
            {
                return left.getHeight() != right.getHeight() || left.getWidth() != right.getWidth();
            }
        }
    }
}

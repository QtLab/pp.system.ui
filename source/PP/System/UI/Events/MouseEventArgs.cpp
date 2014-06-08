/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Events/MouseEventArgs.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Events/MouseEventArgs.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            MouseEventArgs::MouseEventArgs()
                : m_delta(0), m_x(0), m_y(0), m_leftDown(false), m_middleDown(false), 
                m_rightDown(false), m_xButton1Down(false), m_xButton2Down(false)
            {
            }

            MouseEventArgs::~MouseEventArgs()
            {
            }
            

            int MouseEventArgs::getDelta() const
            {
                return m_delta;
            }

            void MouseEventArgs::setDelta(int delta)
            {
                m_delta = delta;
            }

            int MouseEventArgs::getX() const
            {
                return m_x;
            }

            void MouseEventArgs::setX(int x)
            {
                m_x = x;
            }

            int MouseEventArgs::getY() const
            {
                return m_y;
            }

            void MouseEventArgs::setY(int y)
            {
                m_y = y;
            }

            bool MouseEventArgs::isLeftDown() const
            {
                return m_leftDown;
            }

            void MouseEventArgs::setLeftDown(bool value)
            {
                m_leftDown = value;
            }

            bool MouseEventArgs::isRightDown() const
            {
                return m_leftDown;
            }

            void MouseEventArgs::setRightDown(bool value)
            {
                m_rightDown = value;
            }

            bool MouseEventArgs::isMiddleDown() const
            {
                return m_middleDown;
            }

            void MouseEventArgs::setMiddleDown(bool value)
            {
                m_middleDown = value;
            }
            
            bool MouseEventArgs::isXButton1Down() const
            {
                return m_xButton1Down;
            }

            void MouseEventArgs::setXButton1Down(bool value)
            {
                m_xButton1Down = value;
            }

            bool MouseEventArgs::isXButton2Down() const
            {
                return m_xButton2Down;
            }

            void MouseEventArgs::setXButton2Down(bool value)
            {
                m_xButton2Down = value;
            }
        }
    }
}

/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Events/MouseEventArgs.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_EVENTS_MOUSEEVENTARGS_HPP
#define PP_SYSTEM_UI_EVENTS_MOUSEEVENTARGS_HPP

#include <string>

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class MouseEventArgs
            {
            public:
                MouseEventArgs();
                ~MouseEventArgs();

                int getDelta() const;
                void setDelta(int delta);

                int getX() const;
                int getY() const;

                void setX(int x);
                void setY(int y);
                
                bool isLeftDown() const;
                bool isMiddleDown() const;
                bool isRightDown() const;
                bool isXButton1Down() const;
                bool isXButton2Down() const;
                
                void setLeftDown(bool value);
                void setMiddleDown(bool value);
                void setRightDown(bool value);
                void setXButton1Down(bool value);
                void setXButton2Down(bool value);

            private:
                int m_delta;

                int m_x;
                int m_y;
                
                bool m_leftDown;
                bool m_middleDown;
                bool m_rightDown;
                bool m_xButton1Down;
                bool m_xButton2Down;
            };
        }
    }
}

#endif

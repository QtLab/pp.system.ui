/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Point.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_POINT_HPP
#define PP_SYSTEM_UI_POINT_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            /**
             * The representation of a 2D point in space.
             */
            class Point
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 */
                Point();

                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] point The point to copy.
                 */
                Point(const Point& point);

                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] value The value to initialize with.
                 */
                Point(int value);

                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] x The X-position of the point.
                 * @param[in] y The Y-position of the point.
                 */
                Point(int x, int y);

                /**
                 * Cleans up all the resources used by this class.
                 */
                ~Point();

                /**
                 * Copies the given point.
                 *
                 * @param[in] point The point to copy.
                 * @return Returns the updated instance of this class.
                 */
                Point& operator =(const Point& point);

                /**
                 * Gets the X-position of this point.
                 *
                 * @return Returns the X-position as an integer.
                 */
                int getX() const;

                /**
                 * Sets the X-position of this point.
                 *
                 * @param[in] x The X-position to set.
                 */
                void setX(int x);

                /**
                 * Gets the Y-position of this point.
                 *
                 * @return Returns the Y-position as an integer.
                 */
                int getY() const;

                /**
                 * Sets the Y-position of this point.
                 *
                 * @param[in] y The Y-position to set.
                 */
                void setY(int y);

            private:
                /** The X-position of the point. */
                int m_x;

                /** The Y-position of the point. */
                int m_y;
            };

            bool operator ==(const Point& left, const Point& right);
            bool operator !=(const Point& left, const Point& right);
        }
    }
}

#endif

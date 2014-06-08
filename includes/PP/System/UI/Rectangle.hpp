/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Rectangle.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_RECTANGLE_HPP
#define PP_SYSTEM_UI_RECTANGLE_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class Point;
            class Size;

            /**
             * The representation of a rectangle.
             */
            class Rectangle
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 */
                Rectangle();

                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] rectangle The rectangle to copy.
                 */
                Rectangle(const Rectangle& rectangle);

                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] x The X-position of the rectangle.
                 * @param[in] y The Y-position of the rectangle.
                 * @param[in] width The width of the rectangle.
                 * @param[in] height The height of the rectangle.
                 */
                Rectangle(int x, int y, int width, int height);

                /**
                 * Cleans up all the resources used by this class.
                 */
                ~Rectangle();

                /**
                 * Copies the given rectangle.
                 *
                 * @param[in] rectangle The rectangle to copy.
                 * @return Returns the updated instance of this class.
                 */
                Rectangle& operator =(const Rectangle& rectangle);

                /**
                * Converts the X- and Y-position to a Point.
                *
                * @return Returns a Point.
                */
                Point getLocation() const;

                /**
                 * Converts the width and height to a Size.
                 *
                 * @return Returns a Size.
                 */
                Size getSize() const;

                /**
                 * Gets the width of the rectangle.
                 *
                 * @return Gets the width of the rectangle as an integer.
                 */
                int getWidth() const;

                /**
                 * Gets the height of the rectangle.
                 *
                 * @return Gets the height of the rectangle as an integer.
                 */
                int getHeight() const;

                /**
                 * Gets the bottom position of the rectangle.
                 *
                 * @return Returns the bottom position of rectangle as an integer.
                 */
                int getBottom() const;

                /**
                 * Gets the left position of the rectangle.
                 *
                 * @return Returns the left position of rectangle as an integer.
                 */
                int getLeft() const;

                /**
                 * Gets the right position of the rectangle.
                 *
                 * @return Returns the right position of rectangle as an integer.
                 */
                int getRight() const;

                /**
                 * Gets the top position of the rectangle.
                 *
                 * @return Returns the top position of rectangle as an integer.
                 */
                int getTop() const;

                /**
                 * Sets the bottom position of the rectangle.
                 *
                 * @param[in] bottom The position to set.
                 */
                void setBottom(int bottom);

                /**
                 * Sets the left position of the rectangle.
                 *
                 * @param[in] left The position to set.
                 */
                void setLeft(int left);

                /**
                 * Sets the right position of the rectangle.
                 *
                 * @param[in] right The position to set.
                 */
                void setRight(int right);

                /**
                 * Sets the top position of the rectangle.
                 *
                 * @param[in] top The position to set.
                 */
                void setTop(int top);

            private:
                /** The bottom position of the rectangle. */
                int m_bottom;

                /** The left position of the rectangle. */
                int m_left;

                /** The right position of the rectangle. */
                int m_right;

                /** The top position of the rectangle. */
                int m_top;
            };
        }
    }
}

#endif

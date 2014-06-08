/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Size.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_SIZE_HPP
#define PP_SYSTEM_UI_SIZE_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            /**
             * The representation of a size.
             */
            class Size
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 */
                Size();

                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] size The size to copy.
                 */
                Size(const Size& size);

                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] value The width and height of the size.
                 */
                Size(int value);

                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] width The width to set.
                 * @param[in] height The height to set.
                 */
                Size(int width, int height);

                /**
                 * Cleans up all resources used by this class.
                 */
                ~Size();

                /**
                 * Copies the given size.
                 *
                 * @param[in] size The size to copy.
                 * @return Returns the updated instance of this class.
                 */
                Size& operator =(const Size& size);

                /**
                 * Gets the width of the size.
                 *
                 * @return Returns the width as an integer.
                 */
                int getWidth() const;

                /**
                 * Sets the width of the size.
                 *
                 * @param[in] width The width to set.
                 */
                void setWidth(int width);

                /**
                 * Gets the Y-position of the size.
                 *
                 * @return Returns the height as an integer.
                 */
                int getHeight() const;

                /**
                 * Sets the height of the size.
                 *
                 * @param[in] height The height to set.
                 */
                void setHeight(int height);

            private:
                /** The width. */
                int m_Width;

                /** The height. */
                int m_Height;
            };

            bool operator ==(const Size& left, const Size& right);
            bool operator !=(const Size& left, const Size& right);
        }
    }
}

#endif

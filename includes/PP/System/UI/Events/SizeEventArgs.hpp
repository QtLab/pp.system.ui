/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Events/SizeEventArgs.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_EVENTS_SIZEEVENTARGS_HPP
#define PP_SYSTEM_UI_EVENTS_SIZEEVENTARGS_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class EventArgs;

            class SizeEventArgs: public EventArgs
            {
            public:
                /**
                 * Initialzies a new instance of this class.
                 *
                 * @param[in] size The size.
                 * @param[in] prevSize The previous size.
                 */
                SizeEventArgs(const Size& size, const Size& prevSize);
                
                /**
                 * Cleans up all the resources used by this class.
                 */
                virtual ~SizeEventArgs();

                /**
                 * Gets the size.
                 *
                 * @return Returns an instance of Size.
                 */
                Size getSize() const;

                /**
                 * Gets the previous size.
                 *
                 * @return Returns an instance of Size.
                 */
                Size getPreviousSize() const;

            private:
                /** The size. */
                Size m_size;
                
                /** The previous size. */
                Size m_previousSize;
            };
        }
    }
}

#endif

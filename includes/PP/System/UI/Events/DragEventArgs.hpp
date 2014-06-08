/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Events/DragEventArgs.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_EVENTS_DRAGEVENTARGS_HPP
#define PP_SYSTEM_UI_EVENTS_DRAGEVENTARGS_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class EventArgs;

            class DragEventArgs: public EventArgs
            {
            public:
                DragEventArgs();
                virtual ~DragEventArgs();
            };
        }
    }
}

#endif

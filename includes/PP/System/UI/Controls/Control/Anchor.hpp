/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Control/Anchor.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_CONTROL_ANCHOR_HPP
#define PP_SYSTEM_UI_CONTROLS_CONTROL_ANCHOR_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            enum Anchor
            {
                /** The control is not anchored at all. */
                AnchorNone = 1,
                
                /** The control is anchored at the left. */
                AnchorLeft = 2,
                
                /** The control is anchored at the right. */
                AnchorRight = 4,
                
                /** The control is anchored at the top. */
                AnchorTop = 8,
                
                /** The control is anchored at the bottom. */
                AnchorBottom = 16
            };
        }
    }
}

#endif

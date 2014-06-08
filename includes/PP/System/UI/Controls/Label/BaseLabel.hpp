/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Label/BaseLabel.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_LABEL_BASELABEL_HPP
#define PP_SYSTEM_UI_CONTROLS_LABEL_BASELABEL_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            /**
             * The base class for all labels.
             */
            class BaseLabel: public Control
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 */
                BaseLabel();
                
                /**
                 * Cleans up all the resources used by this class.
                 */
                virtual ~BaseLabel();
            };
        }
    }
}

#endif

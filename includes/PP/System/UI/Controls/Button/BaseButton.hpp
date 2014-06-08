/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Button/BaseButton.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_BUTTON_BASEBUTTON_HPP
#define PP_SYSTEM_UI_CONTROLS_BUTTON_BASEBUTTON_HPP

#include "PP/System/UI/Events/Event.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            /**
             * The base class for all buttons.
             */
            class BaseButton: public Control
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 */
                BaseButton();

                /**
                 * Cleans up all the resources used by this class.
                 */
                virtual ~BaseButton();

            protected:
                /**
                 * Called when the button is clicked.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onButtonClicked(const EventArgs& eventArgs) = 0;

                /**
                 * Called when the button is double clicked.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onButtonDoubleClicked(const EventArgs& eventArgs) = 0;
            };
        }
    }
}

#endif

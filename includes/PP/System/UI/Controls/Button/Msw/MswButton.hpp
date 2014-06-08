/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Button/Msw/MswButton.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_BUTTON_MSW_MSWBUTTON_HPP
#define PP_SYSTEM_UI_CONTROLS_BUTTON_MSW_MSWBUTTON_HPP

#include "PP/System/UI/Events/Event.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            /**
             * The Windows implementation of a button.
             */
            class MswButton: public BaseButton
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 */
                MswButton();

                /**
                 * Cleans up all the resources used by this class.
                 */
                virtual ~MswButton();

            protected:
                /**
                 * Called when the button is clicked.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onButtonClicked(const EventArgs& eventArgs);

                /**
                 * Called when the button is double clicked.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onButtonDoubleClicked(const EventArgs& eventArgs);
                
                /**
                 * Initializes the MSW window class.
                 *
                 * @param[in] windowClass The window class to initialize.
                 */
                virtual void mswInitializeWindowClass(WNDCLASSEX* windowClass);
                
                /**
                 * Initializes the MSW creation struct.
                 *
                 * @param[in] createStruct The struct to initialize.
                 */
                virtual void mswInitializeCreateStruct(CREATESTRUCT* createStruct);
                
                /**
                 * A helper function used to handle a command.
                 *
                 * @param[in] wParam The first argument.
                 */
                virtual void mswHandleCommand(WPARAM wParam);

            public:
                /** The event that is invoked once the button is clicked. */
                System::UI::Event<const EventArgs&> ButtonClickedEvent;
                
                /** The event that is invoked once the button is double clicked. */
                System::UI::Event<const EventArgs&> ButtonDoubleClickedEvent;
            };
            
            /** The type definition that represents a Button. */
            typedef MswButton Button;
        }
    }
}

#endif

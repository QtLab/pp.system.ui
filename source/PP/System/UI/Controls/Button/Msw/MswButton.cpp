/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Button/Msw/MswButton.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Events/EventArgs.hpp"
#include "PP/System/UI/Graphics/Color.hpp"
#include "PP/System/UI/Controls/Control/Control.hpp"
#include "PP/System/UI/Controls/Button/Button.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            MswButton::MswButton()
            {
            }

            MswButton::~MswButton()
            {
            }

            void MswButton::onButtonClicked(const EventArgs& eventArgs)
            {
                ButtonClickedEvent.Invoke(eventArgs);
            }

            void MswButton::onButtonDoubleClicked(const EventArgs& eventArgs)
            {
                ButtonDoubleClickedEvent.Invoke(eventArgs);
            }

            void MswButton::mswInitializeWindowClass(WNDCLASSEX* windowClass)
            {
                windowClass->lpszClassName = WC_BUTTON;
            }

            void MswButton::mswInitializeCreateStruct(CREATESTRUCT* createStruct)
            {
                createStruct->style |= WS_CLIPSIBLINGS | BS_FLAT | BS_PUSHBUTTON;
            }

            void MswButton::mswHandleCommand(WPARAM wParam)
            {
                switch (HIWORD(wParam))
                {
                case BN_CLICKED:
                    {
                        EventArgs eventArgs;
                        onButtonClicked(eventArgs);
                        break;
                    }
                case BN_DOUBLECLICKED:
                    {
                        EventArgs eventArgs;
                        onButtonDoubleClicked(eventArgs);
                        break;
                    }
                case BN_DISABLE:
                    {
                        break;
                    }
                case BN_HILITE:
                    {
                        break;
                    }
                case BN_PAINT:
                    {
                        break;
                    }
                }
            }
        }
    }
}

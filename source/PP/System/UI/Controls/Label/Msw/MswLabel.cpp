/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Label/Msw/MswLabel.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Controls/Control/Control.hpp"
#include "PP/System/UI/Controls/Label/Label.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            MswLabel::MswLabel()
            {
            }

            MswLabel::~MswLabel()
            {
            }

            void MswLabel::mswInitializeWindowClass(WNDCLASSEX* windowClass)
            {
                windowClass->lpszClassName = WC_STATIC;
            }

            void MswLabel::mswInitializeCreateStruct(CREATESTRUCT* createStruct)
            {
            }
        }
    }
}

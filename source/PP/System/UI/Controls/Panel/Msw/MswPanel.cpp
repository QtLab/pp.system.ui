/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Panel/Msw/MswPanel.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Controls/Control/Control.hpp"
#include "PP/System/UI/Controls/Panel/Panel.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            MswPanel::MswPanel()
            {
            }

            MswPanel::~MswPanel()
            {
            }

            void MswPanel::mswInitializeWindowClass(WNDCLASSEX* windowClass)
            {
                windowClass->lpszClassName = WC_STATIC;
            }

            void MswPanel::mswInitializeCreateStruct(CREATESTRUCT* createStruct)
            {
                createStruct->style |= SS_NOTIFY /* | SS_OWNERDRAW */;
            }
        }
    }
}

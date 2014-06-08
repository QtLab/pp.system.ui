/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/MessageDialog/MessageDialog.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_MESSAGEDIALOG_MESSAGEDIALOG_HPP
#define PP_SYSTEM_UI_DIALOGS_MESSAGEDIALOG_MESSAGEDIALOG_HPP

#include "PP/System/UI/Controls/Control/Control.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            
        }
    }
}

#ifdef PP_SYSTEM_WINDOWS
    #include "PP/System/UI/Dialogs/MessageDialog/Msw/MswMessageDialog.hpp"
    #define MessageDialog MswMessageDialog
#endif

#endif

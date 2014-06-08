/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/MessageDialog/Msw/MswMessageDialog.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_MESSAGEDIALOG_MSW_MSWMESSAGEDIALOG_HPP
#define PP_SYSTEM_UI_DIALOGS_MESSAGEDIALOG_MSW_MSWMESSAGEDIALOG_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            void MswMessageDialog(const std::wstring& title, const std::wstring& content);
            void MswMessageDialog(BaseControl* owner, const std::wstring& title, const std::wstring& content);
        }
    }
}

#endif

/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/MessageDialog/Msw/MswMessageDialog.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Dialogs/MessageDialog/MessageDialog.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            void MswMessageDialog(const std::wstring& title, const std::wstring& content)
            {
                return MswMessageDialog(NULL, title, content);
            }

            void MswMessageDialog(BaseControl* owner, const std::wstring& title, const std::wstring& content)
            {
                HWND handle = owner ? (HWND)owner->getHandle() : NULL;
                ::MessageBox(handle, content.c_str(), title.c_str(), MB_OK);
            }
        }
    }
}

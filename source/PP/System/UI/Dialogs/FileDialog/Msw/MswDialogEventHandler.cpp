/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/FileDialog/Msw/MswFileDialog.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Dialogs/FileDialog/FileDialog.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            HRESULT MswDialogEventHandler::OnTypeChange(IFileDialog *pfd)
            {
                IFileSaveDialog *pfsd;
                return pfd->QueryInterface(&pfsd);
            }

            HRESULT MswDialogEventHandler::OnItemSelected(IFileDialogCustomize *pfdc, DWORD dwIDCtl, DWORD dwIDItem)
            {
                IFileDialog *pfd = NULL;
                return pfdc->QueryInterface(&pfd);
            }
        }
    }
}

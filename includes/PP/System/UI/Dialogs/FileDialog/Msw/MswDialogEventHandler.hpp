/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/FileDialog/Msw/MswDialogEventHandler.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_FILEDIALOG_MSW_MSWDIALOGEVENTHANDLER_HPP
#define PP_SYSTEM_UI_DIALOGS_FILEDIALOG_MSW_MSWDIALOGEVENTHANDLER_HPP

#define STRICT_TYPED_ITEMIDS
#include <shlobj.h>
#include <objbase.h>      // For COM headers
#include <shobjidl.h>     // for IFileDialogEvents and IFileDialogControlEvents
#include <shlwapi.h>
#include <knownfolders.h> // for KnownFolder APIs/datatypes/function headers
#include <propvarutil.h>  // for PROPVAR-related functions
#include <propkey.h>      // for the Property key APIs/datatypes
#include <propidl.h>      // for the Property System APIs
#include <strsafe.h>      // for StringCchPrintfW
#include <shtypes.h>      // for COMDLG_FILTERSPEC

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class MswDialogEventHandler: public IFileDialogEvents, public IFileDialogControlEvents
            {
            public:
                // IUnknown methods
                IFACEMETHODIMP QueryInterface(REFIID riid, void** ppv)
                {
                    static const QITAB qit[] = {
                        QITABENT(MswDialogEventHandler, IFileDialogEvents),
                        QITABENT(MswDialogEventHandler, IFileDialogControlEvents),
                        { 0 },
                    };
                    return QISearch(this, qit, riid, ppv);
                }

                IFACEMETHODIMP_(ULONG) AddRef()
                {
                    return InterlockedIncrement(&_cRef);
                }

                IFACEMETHODIMP_(ULONG) Release()
                {
                    long cRef = InterlockedDecrement(&_cRef);
                    if (!cRef)
                        delete this;
                    return cRef;
                }

                // IFileDialogEvents methods
                IFACEMETHODIMP OnFileOk(IFileDialog *) { return S_OK; };
                IFACEMETHODIMP OnFolderChange(IFileDialog *) { return S_OK; };
                IFACEMETHODIMP OnFolderChanging(IFileDialog *, IShellItem *) { return S_OK; };
                IFACEMETHODIMP OnHelp(IFileDialog *) { return S_OK; };
                IFACEMETHODIMP OnSelectionChange(IFileDialog *) { return S_OK; };
                IFACEMETHODIMP OnShareViolation(IFileDialog *, IShellItem *, FDE_SHAREVIOLATION_RESPONSE *) { return S_OK; };
                IFACEMETHODIMP OnTypeChange(IFileDialog *pfd);
                IFACEMETHODIMP OnOverwrite(IFileDialog *, IShellItem *, FDE_OVERWRITE_RESPONSE *) { return S_OK; };

                // IFileDialogControlEvents methods
                IFACEMETHODIMP OnItemSelected(IFileDialogCustomize *pfdc, DWORD dwIDCtl, DWORD dwIDItem);
                IFACEMETHODIMP OnButtonClicked(IFileDialogCustomize *, DWORD) { return S_OK; };
                IFACEMETHODIMP OnCheckButtonToggled(IFileDialogCustomize *, DWORD, BOOL) { return S_OK; };
                IFACEMETHODIMP OnControlActivating(IFileDialogCustomize *, DWORD) { return S_OK; };

                MswDialogEventHandler() : _cRef(1) { };
            private:
                ~MswDialogEventHandler() { };
                long _cRef;
            };
        }
    }
}

#endif

/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/SaveFileDialog/Msw/MswSaveFileDialog.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Dialogs/SaveFileDialog/SaveFileDialog.hpp"
#include "PP/System/UI/Dialogs/SaveFileDialog/Msw/MswSaveFileDialog.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            MswSaveFileDialog::MswSaveFileDialog()
                : m_handle(NULL)
            {
            }

            MswSaveFileDialog::~MswSaveFileDialog()
            {
                if (m_handle != NULL)
                {
                    m_handle->Unadvise(m_adviseCookie);
                    m_handle->Release();
                    m_handle = NULL;
                }
            }

            std::wstring MswSaveFileDialog::getFileName() const
            {
                std::wstring result;
                if (m_handle != NULL)
                {
                    IShellItem* shellItem = NULL;
                    m_handle->GetResult(&shellItem);
                    
                    PWSTR path = NULL;
                    HRESULT hr = shellItem->GetDisplayName(SIGDN_FILESYSPATH, &path);
                    if (SUCCEEDED(hr))
                    {
                        result.assign(path);
                        CoTaskMemFree(path);
                    }

                    shellItem->Release();
                    shellItem = NULL;
                }
                return result;
            }

            DialogResult MswSaveFileDialog::showDialog()
            {
                return showDialog(NULL);
            }

            DialogResult MswSaveFileDialog::showDialog(BaseControl* owner)
            {
                HRESULT hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_handle));
                if (FAILED(hr))
                {
                    return DialogResultAbort;
                }
                
                hr = mswCreateDialogEventHandler(IID_PPV_ARGS(&m_dialogEvents));
                if (FAILED(hr))
                {
                    return DialogResultAbort;
                }

                hr = m_handle->Advise(m_dialogEvents, &m_adviseCookie);
                if (FAILED(hr))
                {
                    return DialogResultAbort;
                }
                
                DWORD dwFlags;
                hr = m_handle->GetOptions(&dwFlags);
                if (FAILED(hr))
                {
                    return DialogResultAbort;
                }

                hr = mswInitOptions(m_handle, dwFlags);
                if (FAILED(hr))
                {
                    return DialogResultAbort;
                }

                hr = mswInitFileExtensions(m_handle);
                if (FAILED(hr))
                {
                    return DialogResultAbort;
                }

                HWND parentHandle = owner ? (HWND)owner->getHandle() : NULL;
                hr = m_handle->Show(NULL);

                return SUCCEEDED(hr) ? DialogResultOK : DialogResultCancel;
            }
        }
    }
}

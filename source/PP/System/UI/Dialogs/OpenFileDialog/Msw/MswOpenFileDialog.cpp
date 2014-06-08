/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/OpenFileDialog/Msw/MswOpenFileDialog.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Dialogs/OpenFileDialog/OpenFileDialog.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            MswOpenFileDialog::MswOpenFileDialog()
                : m_handle(NULL), m_adviseCookie(0)
            {
            }

            MswOpenFileDialog::~MswOpenFileDialog()
            {
                if (m_handle != NULL)
                {
                    m_handle->Unadvise(m_adviseCookie);
                    m_handle->Release();
                    m_handle = NULL;
                }
            }

            std::wstring MswOpenFileDialog::getFileName() const
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

            std::vector<std::wstring> MswOpenFileDialog::getFileNames() const
            {
                std::vector<std::wstring> result;
                if (m_handle != NULL)
                {
                    IShellItemArray* shellItemArray = NULL;
                    HRESULT hr = m_handle->GetResults(&shellItemArray);
                    if (SUCCEEDED(hr))
                    {
                        DWORD count = 0;
                        shellItemArray->GetCount(&count);

                        for (DWORD i = 0; i < count; ++i)
                        {
                            IShellItem* shellItem = NULL;
                            shellItemArray->GetItemAt(i, &shellItem);
                    
                            PWSTR path = NULL;
                            HRESULT hr = shellItem->GetDisplayName(SIGDN_FILESYSPATH, &path);
                            if (SUCCEEDED(hr))
                            {
                                result.push_back(path);
                                CoTaskMemFree(path);
                            }

                            shellItem->Release();
                            shellItem = NULL;
                        }

                        shellItemArray->Release();
                    }
                }
                return result;
            }

            DialogResult MswOpenFileDialog::showDialog()
            {
                return showDialog(NULL);
            }

            DialogResult MswOpenFileDialog::showDialog(BaseControl* owner)
            {
                HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_handle));
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

                if (getPickFolders())
                {
                    dwFlags |= FOS_PICKFOLDERS;
                    clearExtensions();
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

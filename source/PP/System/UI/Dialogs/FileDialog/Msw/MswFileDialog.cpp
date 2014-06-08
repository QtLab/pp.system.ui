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
            MswFileDialog::MswFileDialog()
                : m_dialogEvents(NULL)
            {
            }

            MswFileDialog::~MswFileDialog()
            {
                if (m_dialogEvents != NULL)
                {
                    m_dialogEvents->Release();
                    m_dialogEvents = NULL;
                }
            }

            HRESULT MswFileDialog::mswCreateDialogEventHandler(REFIID riid, void **ppv)
            {
                *ppv = NULL;
                MswDialogEventHandler *pDialogEventHandler = new (std::nothrow)MswDialogEventHandler();
                HRESULT hr = pDialogEventHandler ? S_OK : E_OUTOFMEMORY;
                if (SUCCEEDED(hr))
                {
                    hr = pDialogEventHandler->QueryInterface(riid, ppv);
                    pDialogEventHandler->Release();
                }
                return hr;
            }

            HRESULT MswFileDialog::mswInitOptions(IFileDialog* dialog, DWORD flags)
            {
                if (getForceFileSystem())
                {
                    flags |= FOS_FORCEFILESYSTEM;
                }

                if (getPathMustExist())
                {
                    flags |= FOS_PATHMUSTEXIST;
                }

                return dialog->SetOptions(flags);
            }

            HRESULT MswFileDialog::mswInitFileExtensions(IFileDialog* dialog)
            {
                HRESULT hr = S_OK;
                if (!m_extensions.empty())
                {
                    UINT defaultIndex = 0;
                    COMDLG_FILTERSPEC* specList = new COMDLG_FILTERSPEC[m_extensions.size()];

                    for (size_t i = 0; i < m_extensions.size(); ++i)
                    {
                        COMDLG_FILTERSPEC spec;
                        spec.pszName = m_extensions[i].Label.c_str();
                        spec.pszSpec = m_extensions[i].Extension.c_str();
                        specList[i] = spec;

                        if (m_extensions[i].Extension == m_defaultExtension)
                        {
                            defaultIndex = i;
                        }
                    }

                    hr = dialog->SetFileTypes(m_extensions.size(), (const COMDLG_FILTERSPEC*)specList);
                    if (SUCCEEDED(hr))
                    {
                        hr = dialog->SetFileTypeIndex(defaultIndex);
                    }
                    delete[] specList;
                }
                return hr;
            }
        }
    }
}

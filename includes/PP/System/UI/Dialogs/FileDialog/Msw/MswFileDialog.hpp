/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/FileDialog/Msw/MswFileDialog.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_FILEDIALOG_MSW_MSWFILEDIALOG_HPP
#define PP_SYSTEM_UI_DIALOGS_FILEDIALOG_MSW_MSWFILEDIALOG_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class MswFileDialog: public BaseFileDialog
            {
            public:
                MswFileDialog();
                virtual ~MswFileDialog();

            protected:
                HRESULT mswCreateDialogEventHandler(REFIID riid, void **ppv);
                HRESULT mswInitFileExtensions(IFileDialog* dialog);
                HRESULT mswInitOptions(IFileDialog* dialog, DWORD flags);

                IFileDialogEvents* m_dialogEvents;
            };
            
            /** The type definition that represents a FileDialog. */
            typedef MswFileDialog FileDialog;
        }
    }
}

#endif

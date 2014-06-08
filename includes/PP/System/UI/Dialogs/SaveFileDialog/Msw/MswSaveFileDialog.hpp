/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/SaveFileDialog/Msw/MswSaveFileDialog.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_SAVEFILEDIALOG_MSW_MSWSAVEFILEDIALOG_HPP
#define PP_SYSTEM_UI_DIALOGS_SAVEFILEDIALOG_MSW_MSWSAVEFILEDIALOG_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class BaseControl;

            class MswSaveFileDialog: public BaseSaveFileDialog
            {
            public:
                MswSaveFileDialog();
                virtual ~MswSaveFileDialog();

                virtual std::wstring getFileName() const;

                virtual DialogResult showDialog();
                virtual DialogResult showDialog(BaseControl* owner);

            protected:
                IFileSaveDialog* m_handle;
                DWORD m_adviseCookie;
            };

            typedef MswSaveFileDialog SaveFileDialog;
        }
    }
}

#endif

/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/OpenFileDialog/Msw/MswOpenFileDialog.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_OPENFILEDIALOG_HPP
#define PP_SYSTEM_UI_DIALOGS_OPENFILEDIALOG_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class BaseControl;

            class MswOpenFileDialog: public BaseOpenFileDialog
            {
            public:
                MswOpenFileDialog();
                virtual ~MswOpenFileDialog();

                virtual std::wstring getFileName() const;
                virtual std::vector<std::wstring> getFileNames() const;

                virtual DialogResult showDialog();
                virtual DialogResult showDialog(BaseControl* owner);

            protected:
                IFileOpenDialog* m_handle;
                DWORD m_adviseCookie;
            };

            typedef MswOpenFileDialog OpenFileDialog;
        }
    }
}

#endif

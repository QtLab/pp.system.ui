/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/OpenFileDialog/BaseOpenFileDialog.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_OPENFILEDIALOG_BASEOPENFILEDIALOG_HPP
#define PP_SYSTEM_UI_DIALOGS_OPENFILEDIALOG_BASEOPENFILEDIALOG_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class BaseOpenFileDialog: public FileDialog
            {
            public:
                BaseOpenFileDialog();
                virtual ~BaseOpenFileDialog();

                virtual std::vector<std::wstring> getFileNames() const = 0;
                
                bool getPickFolders() const;
                void setPickFolders(bool pickFolders);

            private:
                bool m_pickFolders;
            };
        }
    }
}

#endif

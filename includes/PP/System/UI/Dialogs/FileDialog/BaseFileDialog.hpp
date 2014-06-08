/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/FileDialog/BaseFileDialog.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_FILEDIALOG_BASEFILEDIALOG_HPP
#define PP_SYSTEM_UI_DIALOGS_FILEDIALOG_BASEFILEDIALOG_HPP

#include <vector>

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class BaseControl;

            class BaseFileDialog
            {
                typedef std::vector<FileDialogExtension> ExtensionList;

            public:
                BaseFileDialog();
                virtual ~BaseFileDialog();

                void addExtension(const std::wstring& extension, const std::wstring& label);
                void addExtension(const FileDialogExtension& extension);
                void clearExtensions();

                void setDefaultExtension(const std::wstring& extension);

                bool getForceFileSystem() const;
                void setForceFileSystem(bool forceFileSystem);

                bool getFileMustExist() const;
                void setFileMustExist(bool fileMustExist);
                
                bool getPathMustExist() const;
                void setPathMustExist(bool pathMustExist);

                virtual std::wstring getFileName() const = 0;
                
                virtual DialogResult showDialog() = 0;
                virtual DialogResult showDialog(BaseControl* owner) = 0;

            protected:
                /** A list with all extensions. */
                ExtensionList m_extensions;

                /** The default extension of the dialog. */
                std::wstring m_defaultExtension;

                bool m_forceFileSystem;
                bool m_fileMustExist;
                bool m_pathMustExist;
            };
        }
    }
}

#endif

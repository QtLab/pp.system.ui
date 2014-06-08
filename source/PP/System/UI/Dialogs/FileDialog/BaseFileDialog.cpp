/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/FileDialog/BaseFileDialog.cpp
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
            BaseFileDialog::BaseFileDialog()
                : m_forceFileSystem(false), m_fileMustExist(false), m_pathMustExist(false)
            {
            }

            BaseFileDialog::~BaseFileDialog()
            {
            }

            void BaseFileDialog::addExtension(const std::wstring& extension, const std::wstring& label)
            {
                FileDialogExtension fileExtension;
                fileExtension.Extension = extension;
                fileExtension.Label = label;

                addExtension(fileExtension);
            }

            void BaseFileDialog::addExtension(const FileDialogExtension& extension)
            {
                m_extensions.push_back(extension);
            }

            void BaseFileDialog::clearExtensions()
            {
                m_extensions.clear();
            }

            void BaseFileDialog::setDefaultExtension(const std::wstring& extension)
            {
                m_defaultExtension = extension;
            }

            bool BaseFileDialog::getForceFileSystem() const
            {
                return m_forceFileSystem;
            }

            void BaseFileDialog::setForceFileSystem(bool forceFileSystem)
            {
                m_forceFileSystem = forceFileSystem;
            }

            bool BaseFileDialog::getFileMustExist() const
            {
                return m_fileMustExist;
            }

            void BaseFileDialog::setFileMustExist(bool fileMustExist)
            {
                m_fileMustExist = fileMustExist;
            }

            bool BaseFileDialog::getPathMustExist() const
            {
                return m_pathMustExist;
            }

            void BaseFileDialog::setPathMustExist(bool pathMustExist)
            {
                m_pathMustExist = pathMustExist;
            }
        }
    }
}

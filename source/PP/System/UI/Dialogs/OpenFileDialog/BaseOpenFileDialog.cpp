/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/OpenFileDialog/BaseOpenFileDialog.cpp
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
            BaseOpenFileDialog::BaseOpenFileDialog()
                : m_pickFolders(false)
            {
            }

            BaseOpenFileDialog::~BaseOpenFileDialog()
            {
            }

            bool BaseOpenFileDialog::getPickFolders() const
            {
                return m_pickFolders;
            }

            void BaseOpenFileDialog::setPickFolders(bool pickFolders)
            {
                m_pickFolders = pickFolders;
            }
        }
    }
}

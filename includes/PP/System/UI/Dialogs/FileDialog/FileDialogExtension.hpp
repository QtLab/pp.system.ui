/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/FileDialog/FileDialogExtension.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_FILEDIALOG_FILEDIALOGEXTENSION_HPP
#define PP_SYSTEM_UI_DIALOGS_FILEDIALOG_FILEDIALOGEXTENSION_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            /**
             * The representation of a file dialog extension.
             */
            struct FileDialogExtension
            {
                /** The label of the extension. */
                std::wstring Label;
                
                /** The actual extension code. */
                std::wstring Extension;
            };
        }
    }
}

#endif

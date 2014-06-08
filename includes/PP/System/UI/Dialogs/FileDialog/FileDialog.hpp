/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/FileDialog/FileDialog.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_FILEDIALOG_FILEDIALOG_HPP
#define PP_SYSTEM_UI_DIALOGS_FILEDIALOG_FILEDIALOG_HPP

#include "PP/System/UI/Controls/Control/Control.hpp"
#include "PP/System/UI/Dialogs/DialogResult.hpp"
#include "PP/System/UI/Dialogs/FileDialog/FileDialogExtension.hpp"
#include "PP/System/UI/Dialogs/FileDialog/BaseFileDialog.hpp"

#ifdef PP_SYSTEM_WINDOWS
    #include "PP/System/UI/Dialogs/FileDialog/Msw/MswDialogEventHandler.hpp"
    #include "PP/System/UI/Dialogs/FileDialog/Msw/MswFileDialog.hpp"
#endif

#endif

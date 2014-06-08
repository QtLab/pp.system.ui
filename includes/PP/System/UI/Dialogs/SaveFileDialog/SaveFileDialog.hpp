/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/SaveFileDialog/SaveFileDialog.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_SAVEFILEDIALOG_SAVEFILEDIALOG_HPP
#define PP_SYSTEM_UI_DIALOGS_SAVEFILEDIALOG_SAVEFILEDIALOG_HPP

#include "PP/System/UI/Dialogs/FileDialog/FileDialog.hpp"
#include "PP/System/UI/Dialogs/SaveFileDialog/BaseSaveFileDialog.hpp"

#ifdef PP_SYSTEM_WINDOWS
    #include "PP/System/UI/Dialogs/SaveFileDialog/Msw/MswSaveFileDialog.hpp"
#endif

#endif

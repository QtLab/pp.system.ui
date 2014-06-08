/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/OpenFileDialog/OpenFileDialog.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_OPENFILEDIALOG_OPENFILEDIALOG_HPP
#define PP_SYSTEM_UI_DIALOGS_OPENFILEDIALOG_OPENFILEDIALOG_HPP

#include "PP/System/UI/Dialogs/FileDialog/FileDialog.hpp"
#include "PP/System/UI/Dialogs/OpenFileDialog/BaseOpenFileDialog.hpp"

#ifdef PP_SYSTEM_WINDOWS
    #include "PP/System/UI/Dialogs/OpenFileDialog/Msw/MswOpenFileDialog.hpp"
#endif

#endif

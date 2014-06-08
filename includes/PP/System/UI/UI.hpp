/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/UI.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_UI_HPP
#define PP_SYSTEM_UI_UI_HPP

#include <Windows.h>

#include <PP/System/System.hpp>

#include "PP/System/UI/Rectangle.hpp"
#include "PP/System/UI/Point.hpp"
#include "PP/System/UI/Size.hpp"

#include "PP/System/UI/Graphics/Color.hpp"
#include "PP/System/UI/Graphics/Graphics.hpp"

#include "PP/System/UI/Events/Event.hpp"
#include "PP/System/UI/Events/EventArgs.hpp"
#include "PP/System/UI/Events/CloseEventArgs.hpp"
#include "PP/System/UI/Events/DragEventArgs.hpp"
#include "PP/System/UI/Events/KeyEventArgs.hpp"
#include "PP/System/UI/Events/MouseEventArgs.hpp"
#include "PP/System/UI/Events/PaintEventArgs.hpp"
#include "PP/System/UI/Events/SizeEventArgs.hpp"

#include "PP/System/UI/Dialogs/MessageDialog/MessageDialog.hpp"
#include "PP/System/UI/Dialogs/FileDialog/FileDialog.hpp"
#include "PP/System/UI/Dialogs/OpenFileDialog/OpenFileDialog.hpp"
#include "PP/System/UI/Dialogs/SaveFileDialog/SaveFileDialog.hpp"

#include "PP/System/UI/Application/BaseApplication.hpp"
#include "PP/System/UI/Application/Application.hpp"

#include "PP/System/UI/Controls/Control/Control.hpp"
#include "PP/System/UI/Controls/Button/Button.hpp"
#include "PP/System/UI/Controls/Docking/Docking.hpp"
#include "PP/System/UI/Controls/Label/Label.hpp"
#include "PP/System/UI/Controls/Menu/MenuItem.hpp"
#include "PP/System/UI/Controls/Menu/Menu.hpp"
#include "PP/System/UI/Controls/Menu/MenuBar.hpp"
#include "PP/System/UI/Controls/Panel/Panel.hpp"
#include "PP/System/UI/Controls/StatusBar/StatusBar.hpp"
#include "PP/System/UI/Controls/Splitter/Splitter.hpp"
#include "PP/System/UI/Controls/Tabs/Tabs.hpp"
#include "PP/System/UI/Controls/Window/Window.hpp"

#endif

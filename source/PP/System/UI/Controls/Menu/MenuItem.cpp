/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Menu/MenuItem.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Events/EventArgs.hpp"
#include "PP/System/UI/Controls/Menu/Menu.hpp"
#include "PP/System/UI/Controls/Menu/MenuItem.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            MenuItem::MenuItem(Menu* menu, long id, const std::wstring& label, const std::wstring& tooltip)
                : m_menu(menu), m_id(id), m_label(label), m_tooltip(tooltip)
            {
            }
            
            long MenuItem::getId() const
            {
                return m_id;
            }

            void MenuItem::performClick()
            {
                EventArgs eventArgs;
                ClickEvent.Invoke(eventArgs);
            }
        }
    }
}

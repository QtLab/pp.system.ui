/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Menu/MenuItem.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_MENU_MENUITEM_HPP
#define PP_SYSTEM_UI_CONTROLS_MENU_MENUITEM_HPP

#include "PP/System/UI/Events/Event.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class EventArgs;
            class Menu;

            class MenuItem
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 *
                 * @param menu The menu to which the menu item belongs.
                 */
                MenuItem(Menu* menu, long id, const std::wstring& label, const std::wstring& tooltip);

                /**
                 * Gets the id of the menu item.
                 *
                 * @return Returns the id of the menu item.
                 */
                long getId() const;
                
                /**
                 * Simulates a click event.
                 */
                void performClick();

            private:
                /** The menu to which the menu item belongs. */
                Menu* m_menu;
                
                /** The id of the menu item. */
                long m_id;

                /** The label of the menu item. */
                std::wstring m_label;

                /** The tooltip of the menu item. */
                std::wstring m_tooltip;

            public:
                Event<EventArgs&> ClickEvent;
            };
        }
    }
}

#endif

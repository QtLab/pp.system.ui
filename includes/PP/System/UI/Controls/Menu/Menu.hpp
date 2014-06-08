/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Menu/Menu.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_MENU_MENU_HPP
#define PP_SYSTEM_UI_CONTROLS_MENU_MENU_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class MenuItem;

            class Menu
            {
                typedef std::vector<MenuItem*> MenuItemList;

            public:
                Menu();
                Menu(const std::wstring& label);
                ~Menu();
                void* getHandle() const;
                std::wstring getLabel() const;
                void append();
                MenuItem* append(long id, const std::wstring& label, const std::wstring& tooltip);
                void appendSeparator();
                MenuItem* findItem(long id) const;

            private:
                HMENU m_handle;
                std::wstring m_label;
                MenuItemList m_menuItemList;
            };
        }
    }
}

#endif

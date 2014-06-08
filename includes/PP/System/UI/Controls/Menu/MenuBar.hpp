/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Menu/MenuBar.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_MENU_MENUBAR_HPP
#define PP_SYSTEM_UI_CONTROLS_MENU_MENUBAR_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class Menu;
            class MenuItem;

            class MenuBar
            {
            public:
                MenuBar();
                virtual ~MenuBar();
                void* getHandle() const;
                void append(Menu* menu);
                
                MenuItem* findItem(long id) const;

            private:
                HMENU m_handle;
                typedef std::vector<Menu*> MenuList;
                MenuList m_menuList;
            };
        }
    }
}

#endif

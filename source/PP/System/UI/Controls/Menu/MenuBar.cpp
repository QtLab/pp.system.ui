/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Menu/MenuBar.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Controls/Menu/MenuItem.hpp"
#include "PP/System/UI/Controls/Menu/Menu.hpp"
#include "PP/System/UI/Controls/Menu/MenuBar.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            MenuBar::MenuBar()
            {
                m_handle = ::CreateMenu();
            }

            MenuBar::~MenuBar()
            {
                ::DestroyMenu(m_handle);
            }

            void* MenuBar::getHandle() const
            {
                return m_handle;
            }

            void MenuBar::append(Menu* menu)
            {
                ::AppendMenu(m_handle, MF_POPUP, (UINT_PTR)menu->getHandle(), menu->getLabel().c_str());

                m_menuList.push_back(menu);
            }
            
            MenuItem* MenuBar::findItem(long id) const
            {
                MenuItem* result = NULL;

                for (MenuList::const_iterator it = m_menuList.begin(); it != m_menuList.end(); ++it)
                {
                    const Menu* menu = *it;

                    result = menu->findItem(id);
                    if (result != NULL)
                    {
                        break;
                    }
                }

                return result;
            }
        }
    }
}

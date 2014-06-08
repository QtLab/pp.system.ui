/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Menu/Menu.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Controls/Menu/MenuItem.hpp"
#include "PP/System/UI/Controls/Menu/Menu.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            Menu::Menu()
                : m_handle(NULL)
            {
                m_handle = ::CreatePopupMenu();
            }
            
            Menu::Menu(const std::wstring& label)
                : m_handle(NULL), m_label(label)
            {
                m_handle = ::CreatePopupMenu();
            }
            
            Menu::~Menu()
            {
                ::DestroyMenu(m_handle);
            }
            
            void* Menu::getHandle() const
            {
                return m_handle;
            }

            std::wstring Menu::getLabel() const
            {
                return m_label;
            }

            void Menu::append()
            {
            }

            MenuItem* Menu::append(long id, const std::wstring& label, const std::wstring& tooltip)
            {
                MenuItem* item = new MenuItem(this, id, label, tooltip);
                
                ::AppendMenuW(m_handle, MF_STRING, id, label.c_str());
                m_menuItemList.push_back(item);

                return item;
            }
            
            void Menu::appendSeparator()
            {
                ::AppendMenu(m_handle, MF_SEPARATOR, 0, NULL);
            }
            
            MenuItem* Menu::findItem(long id) const
            {
                MenuItem* result = NULL;

                for (MenuItemList::const_iterator it = m_menuItemList.begin(); it != m_menuItemList.end(); ++it)
                {
                    MenuItem* menuItem = *it;
                    if (menuItem->getId() == id)
                    {
                        result = menuItem;
                        break;
                    }
                }

                return result;
            }
        }
    }
}


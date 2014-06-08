/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Tabs/BaseTabContainer.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Controls/Control/Control.hpp"
#include "PP/System/UI/Controls/Tabs/Tabs.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            BaseTabContainer::BaseTabContainer()
                : m_activeTab(0)
            {
            }

            BaseTabContainer::~BaseTabContainer()
            {
                for (TabPageList::iterator it = m_Pages.begin(); it != m_Pages.end(); ++it)
                {
                    delete *it;
                }
                m_Pages.clear();
            }

            int BaseTabContainer::GetPageCount() const
            {
                return m_Pages.size();
            }
        }
    }
}

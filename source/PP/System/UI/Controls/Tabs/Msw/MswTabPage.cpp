/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Tabs/Msw/MswTabPage.cpp
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
            MswTabPage::MswTabPage(BaseTabContainer* tabContainer, const std::wstring& title)
                : m_TabContainer(tabContainer), m_Title(title)
            {
                TCITEM tie;
                tie.mask = TCIF_TEXT;
                tie.pszText = (LPWSTR)title.c_str();
                TabCtrl_InsertItem((HWND)tabContainer->getHandle(), tabContainer->GetPageCount(), &tie);
            }

            MswTabPage::~MswTabPage()
            {
            }
        }
    }
}

/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Tabs/TabContainer.cpp
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
            MswTabContainer::MswTabContainer()
            {
            }

            MswTabContainer::~MswTabContainer()
            {
            }

            void MswTabContainer::mswInitializeWindowClass(WNDCLASSEX* windowClass)
            {
                windowClass->lpszClassName = WC_TABCONTROL;
            }

            void MswTabContainer::mswInitializeCreateStruct(CREATESTRUCT* createStruct)
            {
                createStruct->dwExStyle |= WS_EX_COMPOSITED;
                createStruct->style |= WS_CLIPSIBLINGS;
            }

            bool MswTabContainer::MswHandleNotification(NMHDR* notificationMsg)
            {
                switch (notificationMsg->code)
                {
                case TCN_SELCHANGING:
                    return false;

                case TCN_SELCHANGE:
                    {
                        m_Pages[m_activeTab]->Deactivate();

                        m_activeTab = TabCtrl_GetCurSel(m_handle);

                        m_Pages[m_activeTab]->Activate();
                        break;
                    }
                    break;
                }

                return true;
            }

            BaseTabPage* MswTabContainer::AppendPage(const std::wstring& title)
            {
                MswTabPage* page = new MswTabPage(this, title);

                m_Pages.push_back(page);

                return page;
            }

            BaseTabPage* MswTabContainer::GetCurrentPage() const
            {
                int page = TabCtrl_GetCurSel(m_handle);

                return m_Pages[page];
            }
        }
    }
}

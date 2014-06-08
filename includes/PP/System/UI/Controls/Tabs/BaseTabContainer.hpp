/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Tabs/BaseTabContainer.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_TABS_BASETABCONTAINER_HPP
#define PP_SYSTEM_UI_CONTROLS_TABS_BASETABCONTAINER_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class BaseTabPage;

            class BaseTabContainer: public Control
            {
                typedef std::vector<BaseTabPage*> TabPageList;

            public:
                BaseTabContainer();
                virtual ~BaseTabContainer();

                virtual BaseTabPage* AppendPage(const std::wstring& title) = 0;
                virtual BaseTabPage* GetCurrentPage() const = 0;
                int GetPageCount() const;

            protected:
                TabPageList m_Pages;
                int m_activeTab;
            };
        }
    }
}

#endif

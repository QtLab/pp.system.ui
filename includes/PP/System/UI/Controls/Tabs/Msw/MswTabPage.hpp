/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Tabs/Msw/MswTabPage.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_TABS_MSW_MSWTABPAGE_HPP
#define PP_SYSTEM_UI_CONTROLS_TABS_MSW_MSWTABPAGE_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class MswTabPage: public BaseTabPage
            {
            public:
                MswTabPage(BaseTabContainer* tabContainer, const std::wstring& title);
                virtual ~MswTabPage();

            private:
                BaseTabContainer* m_TabContainer;
                std::wstring m_Title;
            };

            typedef MswTabPage TabPage;
        }
    }
}

#endif

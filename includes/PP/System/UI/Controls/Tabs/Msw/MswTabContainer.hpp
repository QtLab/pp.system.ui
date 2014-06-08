/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Tabs/Msw/MswTabContainer.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_TABS_MSW_MSWTABCONTAINER_HPP
#define PP_SYSTEM_UI_CONTROLS_TABS_MSW_MSWTABCONTAINER_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class BaseTabPage;

            class MswTabContainer: public BaseTabContainer
            {
            public:
                MswTabContainer();
                virtual ~MswTabContainer();

                virtual BaseTabPage* AppendPage(const std::wstring& title);
                virtual BaseTabPage* GetCurrentPage() const;
                
            protected:
                virtual void mswInitializeWindowClass(WNDCLASSEX* windowClass);
                virtual void mswInitializeCreateStruct(CREATESTRUCT* createStruct);
                virtual bool MswHandleNotification(NMHDR* notificationMsg);
            };

            typedef MswTabContainer TabContainer;
        }
    }
}

#endif

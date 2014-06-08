/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Tabs/TabContainer.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_TABS_TABCONTAINER_HPP
#define PP_SYSTEM_UI_CONTROLS_TABS_TABCONTAINER_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class BaseTabPage
            {
                typedef std::vector<Control*> ControlList;

            public:
                void Activate();
                void Deactivate();

                void addControl(Control* control);

            private:
                ControlList m_Controls;
            };
        }
    }
}

#endif

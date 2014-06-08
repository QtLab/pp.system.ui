/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Tabs/BaseTabPage.cpp
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
            void BaseTabPage::Activate()
            {
                for (ControlList::iterator it = m_Controls.begin(); it != m_Controls.end(); ++it)
                {
                    (*it)->show();
                }
            }

            void BaseTabPage::Deactivate()
            {
                for (ControlList::iterator it = m_Controls.begin(); it != m_Controls.end(); ++it)
                {
                    (*it)->hide();
                }
            }

            void BaseTabPage::addControl(Control* control)
            {
                control->hide();
                m_Controls.push_back(control);
            }
        }
    }
}

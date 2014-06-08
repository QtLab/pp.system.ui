/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Panel/BasePanel.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_PANEL_BASEPANEL_HPP
#define PP_SYSTEM_UI_CONTROLS_PANEL_BASEPANEL_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            /**
             * The base class for all panels.
             */
            class BasePanel: public Control
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 */
                BasePanel();

                /**
                 * Cleans up all the resources used by this class.
                 */
                virtual ~BasePanel();
            };
        }
    }
}

#endif

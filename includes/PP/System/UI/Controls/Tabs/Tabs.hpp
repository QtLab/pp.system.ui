/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Tabs/Tabs.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_TABS_TABS_HPP
#define PP_SYSTEM_UI_CONTROLS_TABS_TABS_HPP

#include "PP/System/UI/Controls/Tabs/BaseTabContainer.hpp"
#include "PP/System/UI/Controls/Tabs/BaseTabPage.hpp"

#ifdef PP_SYSTEM_WINDOWS
    #include "PP/System/UI/Controls/Tabs/Msw/MswTabPage.hpp"
    #include "PP/System/UI/Controls/Tabs/Msw/MswTabContainer.hpp"
#endif

#endif

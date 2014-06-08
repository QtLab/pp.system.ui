/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Label/Msw/MswLabel.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_LABEL_MSW_MSWLABEL_HPP
#define PP_SYSTEM_UI_CONTROLS_LABEL_MSW_MSWLABEL_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            /**
             * The windows implementation of a label.
             */
            class MswLabel: public BaseLabel
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 */
                MswLabel();
                
                /**
                 * Cleans up all the resources used by this class.
                 */
                virtual ~MswLabel();

            protected:
                /**
                 * Initializes the MSW window class.
                 *
                 * @param[in] windowClass The window class to initialize.
                 */
                virtual void mswInitializeWindowClass(WNDCLASSEX* windowClass);
                
                /**
                 * Initializes the MSW creation struct.
                 *
                 * @param[in] createStruct The struct to initialize.
                 */
                virtual void mswInitializeCreateStruct(CREATESTRUCT* createStruct);
            };
            
            /** The type definition that represents a Label. */
            typedef MswLabel Label;
        }
    }
}

#endif

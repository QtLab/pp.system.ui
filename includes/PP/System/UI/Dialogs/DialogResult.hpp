/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Dialogs/FileDialog/FileDialogExtension.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_DIALOGS_DIALOGRESULT_HPP
#define PP_SYSTEM_UI_DIALOGS_DIALOGRESULT_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            enum DialogResult
            {
                /** The dialog box return value is Abort (usually sent from a button labeled Abort). */
                DialogResultAbort,
                
                /** The dialog box return value is Cancel (usually sent from a button labeled Cancel). */
                DialogResultCancel,

                /** The dialog box return value is Ignore (usually sent from a button labeled Ignore). */
                DialogResultIgnore,

                /** The dialog box return value is No (usually sent from a button labeled No). */
                DialogResultNo,

                /** Nothing is returned from the dialog box. This means that the modal dialog continues running. */
                DialogResultNone,

                /** The dialog box return value is OK (usually sent from a button labeled OK). */
                DialogResultOK,
                
                /** The dialog box return value is Retry (usually sent from a button labeled Retry). */
                DialogResultRetry,

                /** The dialog box return value is Yes (usually sent from a button labeled Yes). */
                DialogResultYes
            };
        }
    }
}

#endif

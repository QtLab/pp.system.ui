/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Control/BaseControl.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_CONTROLS_CONTROL_BASECONTROL_HPP
#define PP_SYSTEM_UI_CONTROLS_CONTROL_BASECONTROL_HPP

#include "PP/System/UI/Point.hpp"
#include "PP/System/UI/Rectangle.hpp"
#include "PP/System/UI/Size.hpp"
#include "PP/System/UI/Graphics/Color.hpp"
#include "PP/System/UI/Events/Event.hpp"

#include <vector>

#ifdef CreateEvent
#undef CreateEvent
#endif

namespace PP
{
    namespace System
    {
        namespace UI
        {
            class Color;
            class DragEventArgs;
            class EventArgs;
            class KeyEventArgs;
            class MouseEventArgs;
            class MoveEventArgs;
            class PaintEventArgs;
            class SizeEventArgs;
            class Point;
            class Size;

            /**
             * The base control which should be implemented by all controls.
             */
            class BaseControl
            {
            public:
                /** The handle of the control. */
                typedef void* Handle;

                /** A type definition that defines a list of controls. */
                typedef std::vector<BaseControl*> ControlList;
                
                /**
                 * Initializes a new instance of this class.
                 */
                BaseControl();

                /**
                 * Cleans up all the resources used by this class.
                 */
                virtual ~BaseControl();
                
                /**
                 * Creates the control.
                 *
                 * @param[in] parent An optional parent control.
                 */
                virtual void create(BaseControl* parent = NULL) = 0;
                
                /**
                 * Destroyes the control.
                 */
                virtual void destroy() = 0;

                /**
                 * Updates the control.
                 */
                virtual void update() = 0;

                /**
                 * Redraws the control.
                 */
                virtual void invalidate() = 0;
                
                /**
                 * Adds a child to this control.
                 *
                 * @param[in] child The control to add.
                 */
                virtual void addControl(BaseControl* child) = 0;
                
                /**
                 * Tries to find a control with the given id.
                 *
                 * @param[in] id The id of the control to find.
                 * @return Returns NULL when no control is found; else the control is returned.
                 */
                virtual BaseControl* findControl(long id) const = 0;
                
                /**
                 * Tries to find a control with the given system handle.
                 *
                 * @param[in] handle The system handle of the control to find.
                 * @return Returns NULL when no control is found; else the control is returned.
                 */
                virtual BaseControl* findControl(void* handle) const = 0;

                /**
                 * Removes the given control.
                 *
                 * @param[in] child The child control to remove.
                 */
                virtual void removeControl(BaseControl* child) = 0;
                
                /**
                 * Gets the id of the control.
                 *
                 * @return Returns a long value representing the id of the control.
                 */
                virtual long getId() const = 0;
                
                /**
                 * Gets the system handle of the control.
                 *
                 * @return Returns the system handle of the control.
                 */
                virtual Handle getHandle() const = 0;
                
                /**
                 * Gets the parent control of this control.
                 *
                 * @return Returns the parent control.
                 */
                virtual BaseControl* getParent() const = 0;
                
                /**
                 * Gets the parent control of this control.
                 *
                 * @param[in] parent The parent to set.
                 */
                virtual void setParent(BaseControl* parent) = 0;

                /**
                 * Gets the caption of the control.
                 *
                 * @return Returns a string representing the caption of this control.
                 */
                virtual std::wstring getCaption() const = 0;
                
                /**
                 * Sets the caption of the control.
                 *
                 * @param[in] caption The caption to set.
                 */
                virtual void setCaption(const std::wstring& caption) = 0;

                /**
                 * Checks if the control is enabled or disabled.
                 *
                 * @return Returns true when the control is enabled; false otherwise.
                 */
                virtual bool isEnabled() const = 0;

                /**
                 * Enables or disables the control.
                 *
                 * @param[in] enabled The flag to set.
                 */
                virtual void setEnabled(bool enabled) = 0;
                
                /**
                 * Gets the size of the control.
                 *
                 * @return Returns the size of the control.
                 */
                virtual Size getSize() const = 0;

                /**
                 * Sets the size of the control.
                 *
                 * @param[in] width The width to set.
                 * @param[in] height The height to set.
                 */
                virtual void setSize(int width, int height) = 0;

                /**
                 * Sets the size of the control.
                 *
                 * @param[in] size The size to set.
                 */
                virtual void setSize(const Size& size) = 0;

                /**
                 * Gets the position of the control.
                 *
                 * @return Returns the position of the control.
                 */
                virtual Point getPosition() const = 0;

                /**
                 * Sets the position of the control.
                 *
                 * @param[in] x The X-position of the control.
                 * @param[in] y The Y-position of the control.
                 */
                virtual void setPosition(int x, int y) = 0;

                /**
                 * Sets the position of the control.
                 *
                 * @param[in] position The position to set.
                 */
                virtual void setPosition(const Point& position) = 0;

                /**
                 * Hides the control when it's shown.
                 */
                virtual void hide() = 0;

                /**
                 * Shows the control when it's hidden.
                 */
                virtual void show() = 0;
                
                /**
                 * Gets the background color of the control.
                 *
                 * @return Returns the background color of the control.
                 */
                virtual Color getBackgroundColor() const = 0;

                /**
                 * Sets the background color of the control.
                 *
                 * @param[in] color The color to set.
                 */
                virtual void setBackgroundColor(const Color& color) = 0;
                
                /**
                 * Gets the foreground color of the control.
                 *
                 * @return Returns the foreground color of the control.
                 */
                virtual Color getForegroundColor() const = 0;

                /**
                 * Sets the foreground color of the control.
                 *
                 * @param[in] color The color to set.
                 */
                virtual void setForegroundColor(const Color& color) = 0;

                /**
                 * Gets the flags of this control.
                 *
                 * @return Returns an unsigned long containing the flags.
                 */
                virtual unsigned long getFlags() const;

                /**
                 * Sets the flags of the control.
                 *
                 * @param[in] flags The flags to set.
                 */
                virtual void setFlags(unsigned long flags);

                /**
                 * Gets the anchor of this control.
                 *
                 * @return Returns the anchor of this control.
                 */
                unsigned long getAnchor() const;

                /**
                 * Checks if this control has the given anchor.
                 *
                 * @param[in] anchor The anchor to check.
                 * @return Returns true when the control has the given anchor; false otherwise.
                 */
                bool hasAnchor(Anchor anchor) const;

                /**
                 * Sets the anchor of this control.
                 *
                 * @param[in] anchor The anchor to set.
                 */
                void setAnchor(unsigned long anchor);

            protected:
                /**
                 * Updates all anchored child controls.
                 */
                virtual void updateAnchors() = 0;

                /**
                 * Called when the control is created.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onCreate(EventArgs& eventArgs);
                
                /**
                 * Called when the control is destroyed.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onDestroy(EventArgs& eventArgs);
                
                /**
                 * Called when a drag and drop operation is completed.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onDragDrop(DragEventArgs& eventArgs);
                
                /**
                 * Called when an object is dragged into the control.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onDragEnter(DragEventArgs& eventArgs);

                /**
                 * Called when an object is dragged out of the control.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onDragLeave(DragEventArgs& eventArgs);

                /**
                 * Called when an object is dragged over the control.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onDragOver(DragEventArgs& eventArgs);
                
                /**
                 * Called when a key is pressed down.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onKeyDown(KeyEventArgs& eventArgs);
                
                /**
                 * Called when a key is pressed.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onKeyPress(KeyEventArgs& eventArgs);
                
                /**
                 * Called when a key is released.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onKeyUp(KeyEventArgs& eventArgs);

                /**
                 * Called when the control is double clicked by the mouse.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMouseDoubleClick(MouseEventArgs& eventArgs);
                
                /**
                 * Called when a mouse button is pressed down.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMouseDown(MouseEventArgs& eventArgs);
                
                /**
                 * Called when the mouse entered the control.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMouseEnter(EventArgs& eventArgs);
                
                /**
                 * Called when the mouse left the control.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMouseLeave(EventArgs& eventArgs);
                
                /**
                 * Called when the mouse is moved over the control.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMouseMove(MouseEventArgs& eventArgs);
                
                /**
                 * Called when a mouse button is released.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMouseUp(MouseEventArgs& eventArgs);
                
                /**
                 * Called when the mouse wheel is used on the control.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMouseWheel(MouseEventArgs& eventArgs);
                
                /**
                 * Called when the horizontal mouse wheel is used on the control.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMouseHWheel(MouseEventArgs& eventArgs);

                /**
                 * Called when the position of the control changed.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onMove(MoveEventArgs& eventArgs);

                /**
                 * Called when the control should be painted.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onPaint(PaintEventArgs& eventArgs);

                /**
                 * Called when the background should be painted.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onPaintBackground(PaintEventArgs& eventArgs);
                
                /**
                 * Called when the size of the control changed.
                 *
                 * @param[in] eventArgs The event arguments.
                 */
                virtual void onSize(SizeEventArgs& eventArgs);

            public:
                Event<EventArgs&> CreateEvent;
                Event<EventArgs&> DestroyEvent;
                Event<DragEventArgs&> DragDropEvent;
                Event<DragEventArgs&> DragEnterEvent;
                Event<DragEventArgs&> DragLeaveEvent;
                Event<DragEventArgs&> DragOverEvent;
                Event<KeyEventArgs&> KeyDownEvent;
                Event<KeyEventArgs&> KeyPressEvent;
                Event<KeyEventArgs&> KeyUpEvent;
                Event<MouseEventArgs&> MouseDoubleClickEvent;
                Event<MouseEventArgs&> MouseDownEvent;
                Event<EventArgs&> MouseEnterEvent;
                Event<EventArgs&> MouseLeaveEvent;
                Event<MouseEventArgs&> MouseMoveEvent;
                Event<MouseEventArgs&> MouseUpEvent;
                Event<MouseEventArgs&> MouseWheelEvent;
                Event<MouseEventArgs&> MouseHWheelEvent;
                Event<MoveEventArgs&> MoveEvent;
                Event<PaintEventArgs&> PaintEvent;
                Event<PaintEventArgs&> PaintBackgroundEvent;
                Event<SizeEventArgs&> SizeEvent;

            private:
                unsigned long m_flags;
                unsigned long m_anchor;
            };
        }
    }
}

#endif

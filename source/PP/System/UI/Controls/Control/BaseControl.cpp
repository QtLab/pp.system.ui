/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Controls/Control/BaseControl.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"

#include "PP/System/UI/Point.hpp"
#include "PP/System/UI/Rectangle.hpp"
#include "PP/System/UI/Size.hpp"

#include "PP/System/UI/Events/EventArgs.hpp"
#include "PP/System/UI/Events/PaintEventArgs.hpp"

#include "PP/System/UI/Graphics/Color.hpp"
#include "PP/System/UI/Graphics/Graphics.hpp"

#include "PP/System/UI/Controls/Control/Control.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            BaseControl::BaseControl()
                : m_flags(0), m_anchor(AnchorNone)
            {
            }

            BaseControl::~BaseControl()
            {
            }

            unsigned long BaseControl::getFlags() const
            {
                return m_flags;
            }

            void BaseControl::setFlags(unsigned long flags)
            {
                m_flags = flags;
            }

            unsigned long BaseControl::getAnchor() const
            {
                return m_anchor;
            }

            bool BaseControl::hasAnchor(Anchor anchor) const
            {
                return (m_anchor & anchor) == anchor;
            }

            void BaseControl::setAnchor(unsigned long anchor)
            {
                m_anchor = anchor;
            }
            
            void BaseControl::onCreate(EventArgs& eventArgs)
            {
                CreateEvent.Invoke(eventArgs);
            }

            void BaseControl::onDestroy(EventArgs& eventArgs)
            {
                DestroyEvent.Invoke(eventArgs);
            }

            void BaseControl::onDragDrop(DragEventArgs& eventArgs)
            {
                DragDropEvent.Invoke(eventArgs);
            }

            void BaseControl::onDragEnter(DragEventArgs& eventArgs)
            {
                DragEnterEvent.Invoke(eventArgs);
            }

            void BaseControl::onDragLeave(DragEventArgs& eventArgs)
            {
                DragLeaveEvent.Invoke(eventArgs);
            }

            void BaseControl::onDragOver(DragEventArgs& eventArgs)
            {
                DragOverEvent.Invoke(eventArgs);
            }

            void BaseControl::onKeyDown(KeyEventArgs& eventArgs)
            {
                KeyDownEvent.Invoke(eventArgs);
            }

            void BaseControl::onKeyPress(KeyEventArgs& eventArgs)
            {
                KeyPressEvent.Invoke(eventArgs);
            }

            void BaseControl::onKeyUp(KeyEventArgs& eventArgs)
            {
                KeyUpEvent.Invoke(eventArgs);
            }

            void BaseControl::onMouseDoubleClick(MouseEventArgs& eventArgs)
            {
                MouseDoubleClickEvent.Invoke(eventArgs);
            }

            void BaseControl::onMouseDown(MouseEventArgs& eventArgs)
            {
                MouseDownEvent.Invoke(eventArgs);
            }

            void BaseControl::onMouseEnter(EventArgs& eventArgs)
            {
                MouseEnterEvent.Invoke(eventArgs);
            }

            void BaseControl::onMouseLeave(EventArgs& eventArgs)
            {
                MouseLeaveEvent.Invoke(eventArgs);
            }

            void BaseControl::onMouseMove(MouseEventArgs& eventArgs)
            {
                MouseMoveEvent.Invoke(eventArgs);
            }

            void BaseControl::onMouseUp(MouseEventArgs& eventArgs)
            {
                MouseUpEvent.Invoke(eventArgs);
            }

            void BaseControl::onMouseWheel(MouseEventArgs& eventArgs)
            {
                MouseWheelEvent.Invoke(eventArgs);
            }

            void BaseControl::onMouseHWheel(MouseEventArgs& eventArgs)
            {
                MouseHWheelEvent.Invoke(eventArgs);
            }

            void BaseControl::onMove(MoveEventArgs& eventArgs)
            {
                MoveEvent.Invoke(eventArgs);
            }

            void BaseControl::onPaint(PaintEventArgs& eventArgs)
            {
                PaintEvent.Invoke(eventArgs);
            }

            void BaseControl::onPaintBackground(PaintEventArgs& eventArgs)
            {
                PaintBackgroundEvent.Invoke(eventArgs);
            }

            void BaseControl::onSize(SizeEventArgs& eventArgs)
            {
                SizeEvent.Invoke(eventArgs);
            }
        }
    }
}

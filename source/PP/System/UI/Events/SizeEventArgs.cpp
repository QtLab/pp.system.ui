/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Events/SizeEventArgs.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Size.hpp"
#include "PP/System/UI/Events/EventArgs.hpp"
#include "PP/System/UI/Events/SizeEventArgs.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            SizeEventArgs::SizeEventArgs(const Size& size, const Size& previousSize)
                : m_size(size), m_previousSize(previousSize)
            {
            }

            SizeEventArgs::~SizeEventArgs()
            {
            }

            Size SizeEventArgs::getSize() const
            {
                return m_size;
            }

            Size SizeEventArgs::getPreviousSize() const
            {
                return m_previousSize;
            }
        }
    }
}

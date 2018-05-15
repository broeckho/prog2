/*
 *  This file is part of the gobelijn software.
 *  Gobelijn is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or any later
 *  version. Gobelijn is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for details. You should have received
 *  a copy of the GNU General Public License along with the software. If not,
 *  see <http://www.gnu.org/licenses/>.
 *
 *  Copyright 2016, Jan Broeckhove.
 */
/**
 * @file.
 * RAII Buffer class.
 */

#include "buffer.h"

namespace Raii {

Buffer::Buffer(const Buffer& other) : m_bufSize(other.m_bufSize)
{
        // Allocate a new (uninitialized) block of memory.
        m_data = new char[m_bufSize];
        // Copies the given buffer's memory block.
        for (size_t i = 0; i < m_bufSize; i++)
                m_data[i] = other.m_data[i];
}

Buffer::Buffer(Buffer&& other) noexcept
{
        // Set this buffer's size.
        m_bufSize = other.m_bufSize;
        // Move the given buffer's block of memory.
        m_data = other.m_data;

        // Turn the moved buffer into an empty buffer, because we must leave
        // the argument in a valid (but otherwise indeterminate) state.
        other.m_bufSize = 0;
        other.m_data = nullptr;
}

Buffer& Buffer::operator=(const Buffer& other)
{
        if (this == &other)
                // Never perform self-assignment.
                return *this;

        // Delete this buffer's old block of memory. If we were to simply
        // overwrite this pointer, then we'd get a memory leak.
        delete[] m_data;

        // Set this buffer's size.
        m_bufSize = other.m_bufSize;
        // Allocate a new (uninitialized) block of memory.
        for (size_t i = 0; i < m_bufSize; i++)
                // Copies the given buffer's memory block contents to this
                // buffer's memory block.
                m_data[i] = other.m_data[i];

        // Return a reference to the '*this' value, to support
        // chaining assignments, i.e. 'a = b = c;'
        return *this;
}

Buffer& Buffer::operator=(Buffer&& other) noexcept
{
        if (this == &other)
                // Never perform self-assignment.
                return *this;

        // Delete this buffer's old block of memory. If we were to simply
        // overwrite this pointer, then we'd get a memory leak.
        delete[] m_data;

        // Set this buffer's size.
        m_bufSize = other.m_bufSize;
        // Sets this buffer's data pointer to the moved buffer's data pointer.
        m_data = other.m_data;

        // Turn the moved buffer into an empty buffer, because we must leave
        // the argument in a valid (but otherwise indeterminate) state.
        other.m_bufSize = 0;
        other.m_data = nullptr;

        // Return a reference to the '*this' value, to support
        // chaining assignments, i.e. 'a = b = c;'
        return *this;
}
} // namespace Raii

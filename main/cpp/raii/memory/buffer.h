#pragma once
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

#include <cstddef>

namespace Raii {

/**
* A buffer of bytes, with a fixed size. Buffers manage a block of memory,
* which can be copied and moved. A Buffer's memory block is automatically
* released when it goes out of scope.
*/
class Buffer
{
public:
        /// Creates a buffer class that manages an empty block of memory.
        Buffer() : m_bufSize(0), m_data(nullptr) {}

        /// Allocates a new buffer, which is the given number of bytes in size.
        explicit Buffer(size_t bufferSize) : m_bufSize(bufferSize)
        {
                // Allocate a new block of memory, and initializes with all-zeroes.
                m_data = new char[bufferSize]();
        }

        /// Creates a copy of the given buffer.
        Buffer(const Buffer& other);

        /// Moves the given buffer.
        Buffer(Buffer&& other) noexcept;

        /// Creates a copy of the given buffer, and assigns that to this buffer.
        Buffer& operator=(const Buffer& other);

        /// Moves the given buffer's data to this buffer.
        Buffer& operator=(Buffer&& other) noexcept;

        /// Destructor.
        ~Buffer() { delete[] m_data; }

        /// Gets the buffer's size, in bytes.
        size_t GetSize() const { return m_bufSize; }

        /// Indexes this byte buffer with the given value. AReturns reference to
        /// mutable char.
        char& operator[](size_t i) { return m_data[i]; }

        /// Indexes this byte buffer with the given value. Returns reference to a
        /// constant char.
        const char& operator[](size_t i) const { return m_data[i]; }

private:
        /// Stores the size of this buffer's memory block.
        size_t m_bufSize;

        /// Stores a pointer to this buffer's memory block.
        char* m_data;
};

} // end of namespace

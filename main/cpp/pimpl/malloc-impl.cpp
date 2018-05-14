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
 * Pimpl implementation with malloc.
 */

#include "memory-pool.h"
#include <cstdlib>
#include <vector>

namespace Pimpl {
/**
 * A MemoryPool::MemoryPoolImpl implementation that uses 'std::malloc'.
 */
struct MemoryPool::MemoryPoolImpl
{
        // Remembers all pointers that have been allocated, so we can
        // deallocate them when the MemoryPool is destroyed.
        std::vector<void*> pointers;
};

/**
 * Creates a memory pool that has at least the given capacity.
 */
MemoryPool::MemoryPool(size_t) : m_impl(new MemoryPoolImpl()) {}

/**
 * Frees this memory pool's resources, if any.
 */
MemoryPool::~MemoryPool()
{
        // Deallocate all pointers.
        for (auto ptr : m_impl->pointers)
                std::free(ptr);
}

/**
 * Allocates a region of memory that is the given number of bytes
 * in size.
 */
char* MemoryPool::AllocateMemory(size_t size)
{
        void* ptr = std::malloc(size);
        m_impl->pointers.push_back(ptr);
        return reinterpret_cast<char*>(ptr);
}
} // namespace Pimpl

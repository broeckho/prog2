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
 * Pimpl implementation with array.
 */

#include "memory-pool.h"

#include <cstdlib>
#include <memory>

namespace Pimpl {
/**
 * The 'MemoryPool::MemoryPoolImpl' POD that uses a dynamically allocated array.
 */
struct MemoryPool::MemoryPoolImpl
{
	char* pointer;
	size_t allocatedCount;
};

/**
 * Creates a memory pool that has at least the given capacity.
 */
MemoryPool::MemoryPool(size_t capacity) : m_impl(new MemoryPoolImpl({new char[capacity], 0})) {}

/**
 * Frees this memory pool's resources, if any.
 */
MemoryPool::~MemoryPool()
{
	// Erase the entire memory pool in one fell swoop.
	delete[] m_impl->pointer;
}

/**
 * Allocates a region of memory that is the given number of bytes
 * in size.
 */
char* MemoryPool::AllocateMemory(size_t size)
{
	// Allocate memory by incrementing a pointer.
	char* result = m_impl->pointer + m_impl->allocatedCount;
	m_impl->allocatedCount += size;
	return result;
}
}

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
 * Pimpl demo with memory pool.
 */

#include <cstddef>
#include <memory>

namespace Pimpl {
/**
 * A memory pool that uses the pointer-to-implementation idiom under the
 * hood. This allows developers to switch MemoryPool implementation without
 * re-compiling any other files.
 */
class MemoryPool
{
public:
	// Delete the usual constructors/assignment operators.
	MemoryPool() = delete;
	MemoryPool(const MemoryPool&) = delete;
	MemoryPool(MemoryPool&&) = delete;
	MemoryPool& operator=(const MemoryPool&) = delete;
	MemoryPool& operator=(MemoryPool&&) = delete;

	/**
	 * Creates a memory pool that can allocate at least as many bytes
	 * as specified by the given capacity.
	 */
	MemoryPool(size_t capacity);

	/**
	 * Frees this memory pool's resources, if any.
	 */
	~MemoryPool();

	/**
	 * Allocates a region of memory that is 'size * sizeof(T)' of bytes
	 * in size. It fits exactly 'size' instances of 'T'.
	 */
	template <typename T>
	T* Allocate(size_t size = 1)
	{
		return reinterpret_cast<T*>(AllocateMemory(size * sizeof(T)));
	}

private:
	/**
	 * Allocates a region of memory that is the given number of bytes
	 * in size.
	 */
	char* AllocateMemory(size_t size);

	// MemoryPoolImpl is declared, but not defined here.
	struct MemoryPoolImpl;

	// Fortunately, we don't need a definition to create a pointer to
	// MemoryPoolImpl, so that's exactly what we'll do.
	std::unique_ptr<MemoryPoolImpl> m_impl;
};

} // end of namespace

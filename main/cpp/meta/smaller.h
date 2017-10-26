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
 *  Copyright 2012, Jan Broeckhove.
 */
/**
 * @file.
 * Compute type with smallest memory size.
 */

// BEGIN_SNIPPET{FullSource}
#include "select.h"

/**
 * Compile-time selection of type with smallest size
 */
template <typename T1, typename T2>
struct smaller
{
        using type = typename select<T1, T2, (sizeof(T1) < sizeof(T2))>::type;
};
// END_SNIPPET{FullSource}

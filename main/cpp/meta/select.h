#ifndef GOBELIJN_META_SELECT_H
#define GOBELIJN_META_SELECT_H
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
 * Select one of two types depending on bool switch.
 */

// BEGIN_SNIPPET{FullSource}
/// Primary template for selection between two types.

template <typename T1, typename T2, bool b>
struct select;

/// Specialization for bool==true
template <typename T1, typename T2>
struct select<T1, T2, true>
{
	using type = T1;
};

/// Specialization for bool==false
template <typename T1, typename T2>
struct select<T1, T2, false>
{
	using type = T2;
};
// END_SNIPPET{FullSource}

#endif // end-of-include-guard

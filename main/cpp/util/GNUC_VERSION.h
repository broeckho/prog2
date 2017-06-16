#ifndef GNUC_VERSION_H_INCLUDED
#define GNUC_VERSION_H_INCLUDED
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
 * @file
 * Macros to determine GCC major, minor and patch version.
 */

#if defined(__GNUC__)
#if defined(__GNUC_PATCHLEVEL__)
#define GNUC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#else
#define GNUC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100)
#endif
#endif

#endif // end-of-include-guard

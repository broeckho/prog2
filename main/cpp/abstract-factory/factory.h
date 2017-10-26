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
 * Factory interface.
 */

namespace AbstractFactory {
/**
 * A class template for abstract factories: objects that construct values
 * based on their internal state, and a variable number of parameters.
 */
template <typename TResult, typename... TArgs>
class Factory
{
public:
        /// Destructor needs to be virtual.
        virtual ~Factory() {}

        /// Instructs this factory to create a value.
        virtual TResult Create(TArgs... args) = 0;
};
}

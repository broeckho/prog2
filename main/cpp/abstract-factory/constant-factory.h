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
 * Constant Factory.
 */

#include "factory.h"

namespace AbstractFactory {
/**
 * A factory class template that always returns a constant, pre-defined
 * value. Any arguments are always discarded.
 */
template <typename TResult, typename... TArgs>
class ConstantFactory : public Factory<TResult, TArgs...>
{
public:
	// Creates a factory that always produces the given value.
	ConstantFactory(const TResult& value) : m_value(value) {}

	// Instructs this factory to create a value.
	virtual TResult Create(TArgs...) override final { return m_value; }

	virtual ~ConstantFactory() {}

private:
	TResult m_value;
};
}

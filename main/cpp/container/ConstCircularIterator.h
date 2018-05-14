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
 *  Copyright 2012, Jan Broeckhove, CoMP research group, Universiteit Antwerpen.
 */
/**
 * @file
 * ConstCircularIterator class and helper functions.
 */

#include <iterator>
#include <type_traits>

#include "CircularIteratorImpl.h"

namespace UA_CoMP {
namespace Container {

/**
 * Alias template defines const circular iterator.
 * @see Impl_::CircularIterator
 */
template <typename T>
using ConstCircularIterator = Impl_::CircularIterator<T, typename std::add_const<typename T::value_type>::type,
                                                      typename std::add_const<typename T::value_type>::type*,
                                                      typename std::add_const<typename T::value_type>::type&>;

/**
 * Helper produces const circular iterator whose range
 * corresponds to the begin and end iterators of a container.
 * @param  c    container
 * @return      CircularIterator pointing to beginning of container
 */
template <typename T>
ConstCircularIterator<typename T::const_iterator> make_const_circular(const T& c)
{
        return ConstCircularIterator<typename T::const_iterator>(std::begin(c), std::end(c), std::begin(c));
}

/**
 * Helper produces const circular iterator whose range
 * corresponds to the begin and end iterators of a container.
 * @param  c    container
 * @return      CircularIterator pointing to beginning of container
 */
template <typename T>
ConstCircularIterator<typename T::const_iterator> make_const_circular(const T& c, typename T::const_iterator i)
{
        return ConstCircularIterator<typename T::const_iterator>(std::begin(c), std::end(c), i);
}

/**
 * Helper produces non-const circular iterator with
 * specified range and initial value.
 * @param  b     iterator pointing to beginning of range
 * @param  e     iterator pointing to end of range
 * @param  i     initial position of the iterator
 */
template <typename T>
ConstCircularIterator<T> make_const_circular(T b, T e, T i)
{
        return ConstCircularIterator<T>(b, e, i);
}

/**
 * Helper produces non-const circular iterator with
 * specified range, with initial value at the start of the range.
 * @param  b     iterator pointing to beginning of range
 * @param  e     iterator pointing to end of range
 */
template <typename T>
ConstCircularIterator<T> make_const_circular(T b, T e)
{
        return ConstCircularIterator<T>(b, e, b);
}

/**
 * Helper yields the position the iterator would have if
 * moved forward (in circular fashion) by 1 position.
 * @param  i    current iterator position
 * @return      one position forward
 */
template <typename T>
ConstCircularIterator<T> next(ConstCircularIterator<T> c)
{
        ConstCircularIterator<T> tmp(c);
        return ++tmp;
}

/**
 * Helper yields the position the iterator would have if
 * moved backward (in circular fashion) by 1 position.
 * @param  i    current iterator position
 * @return      one position backward
 */
template <typename T>
ConstCircularIterator<T> prev(ConstCircularIterator<T> c)
{
        ConstCircularIterator<T> tmp(c);
        return --tmp;
}
} // namespace Container
} // namespace UA_CoMP

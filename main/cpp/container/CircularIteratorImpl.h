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
 * Circular iterator implementation.
 */
#include <iterator>

namespace UA_CoMP {
namespace Container {

namespace Impl_ {
/**
 * Implementation of a circular iterator. It will provide
 * both const and non-const iterator.
 *
 * Template parameters:
 * 	T	iterator type that gets wrapped to be circular.
 * 	V	value type of iterator T (and hence of its container).
 * 	P	pointer-to-V type (can be const qualified).
 * 	R	reference-to-V type (can be const qualified).
 */
template <typename T, typename V, typename P = V*, typename R = V&>
class CircularIterator : public std::iterator<std::bidirectional_iterator_tag, V, typename T::difference_type, P, R>
{
public:
        // ==================================================================
        // Member types (in addition to those introduced by the std::iterator
        // base class (i.e. value_type, difference_type, pointer, reference,
        // iterator_category).
        // ==================================================================
        using type = CircularIterator<T, V, P, R>;
        using base_type = T;

        /**
         * Constructor requires range and start value.
         * @param  b      begin iterator of the range
         * @param  e      end iterator of the range
         * @param  i      start iterator of circular sequencing
         */
        CircularIterator(base_type b, base_type e, base_type i) : m_begin(b), m_end(e), m_it(i) {}

        /**
         * Return underlying base type iterator.
         * @return  current value of iterator
         */
        base_type get() const { return m_it; }

        /**
         * Conversion to return iterator to its base type.
         * @return  current value of iterator
         */
        explicit operator base_type() const { return m_it; }

        /**
         * Assignment operator from base type to circularized iterator.
         * @return  reference to iterator
         */
        type& operator=(const base_type& i)
        {
                m_it = i;
                return *this;
        }

        /**
         * Dereferencing operator.
         * @ return  reference (const / non-const depending on template
         *           parameters) to value pointed to by iterator.
         */
        typename type::reference operator*() const { return (*m_it); }

        /**
         * Structure dereferencing operator.
         * @return  pointer (const / non-const depending on template
         *          parameters) to value pointed to by iterator.
         */
        typename type::pointer operator->() const { return &(operator*()); }

        /**
         * Pre-increment operator works circularly: at the end of
         * the range it jumps back to the beginning and keeps going.
         * @return  iterator after (circular) increment
         */
        type& operator++()
        {
                ++m_it;
                if (m_it == m_end) {
                        m_it = m_begin;
                }
                return (*this);
        }

        /**
         * Post-increment operator works circularly: at the end of
         * the range it jumps back to the beginning and keeps going.
         * @return  iterator before (circular) increment
         */
        type operator++(int)
        {
                type t(*this);
                ++(*this);
                return t;
        }

        /**
         * Pre-decrement operator works circularly: at the beginning
         * of the range it jumps to the end and keeps going.
         * @return  iterator after (circular) decrement
         */
        type& operator--()
        {
                if (m_it == m_begin) {
                        m_it = m_end;
                }
                --m_it;
                return (*this);
        }

        /**
         * Post-decrement operator works circularly: at the beginning
         * of the range it jumps to the end and keeps going.
         * @return  iterator before (circular) decrement
         */
        type operator--(int)
        {
                type t(*this);
                --(*this);
                return t;
        }

        /**
         * Equality test of the pointing iterator only,
         * not of the range iterators.
         * @param  rhs     circular iterator to compare with.
         * @return         true iff current positions iterators coincide
         */
        bool operator==(const type& rhs) const { return (m_it == rhs.m_it); }

        /**
         * Equality test of the pointing iterator only,
         * not of the range iterators.
         * @param  rhs     circular iterator to compare with.
         * @return         true iff current positions iterators coincide
         */
        bool operator==(const base_type& rhs) const { return (m_it == rhs); }

        /**
         * Inequality test of the pointing iterator only,
         * not of the range iterators.
         * @param  rhs     circular iterator to compare with.
         * @return         true iff current positions iterators coincide
         */
        bool operator!=(const type& rhs) const { return !operator==(rhs); }

        /**
         * Inequality test of the pointing iterator only,
         * not of the range iterators.
         * @param  rhs     circular iterator to compare with.
         * @return         true iff current positions iterators coincide
         */
        bool operator!=(const base_type& rhs) const { return !operator==(rhs); }

protected:
        base_type m_begin;
        base_type m_end;
        base_type m_it;
};
} // namespace Impl_
} // namespace Container
} // namespace UA_CoMP

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
 * Tests for Quad.
 */

#include <gtest/gtest.h>
#include <vector>

#include "container/ConstCircularIterator.h"

namespace UA_CoMP {
namespace Container {
namespace Tests {

class Dummy
{
public:
        Dummy(unsigned int u) : m_u(u) {}
        unsigned int f() const { return m_u; }

private:
        unsigned int m_u;
};

using namespace std;

class UnitConstCircular : public ::testing::Test
{
protected:
        virtual void SetUp() {}

        virtual void TearDown() {}

        vector<unsigned int> m_vector{0U, 1U, 2U, 3U};
        vector<Dummy> m_dummy{Dummy(0U), Dummy(1U), Dummy(2U), Dummy(3U)};

        typedef vector<unsigned int>::const_iterator VII;
        typedef ConstCircularIterator<VII> CII;
        typedef vector<Dummy>::const_iterator VDI;
        typedef ConstCircularIterator<VDI> CDI;
};

TEST_F(UnitConstCircular, Instantiation)
{
        CII it(m_vector.begin(), m_vector.end(), m_vector.begin());
        ASSERT_EQ(true, it == it);
}

TEST_F(UnitConstCircular, BaseAssignment)
{
        VII vit = m_vector.begin();
        CII cit1(m_vector.begin(), m_vector.end(), m_vector.begin());
        CII cit2(m_vector.begin(), m_vector.end(), m_vector.end());
        cit2 = vit;
        ASSERT_EQ(true, cit1 == cit2);
}

TEST_F(UnitConstCircular, BaseEquality)
{
        VII vit = m_vector.begin();
        CII cit1(m_vector.begin(), m_vector.end(), m_vector.begin());
        ASSERT_EQ(true, cit1 == vit);
}

TEST_F(UnitConstCircular, BaseInequality)
{
        VII vit = m_vector.begin();
        CII cit1(m_vector.begin(), m_vector.end(), m_vector.begin());
        ASSERT_EQ(true, cit1 != ++vit);
}

TEST_F(UnitConstCircular, BaseTypeConversion)
{
        auto it = make_const_circular(m_vector);
        ASSERT_EQ(true, m_vector.begin() == CII::base_type(it));
}

TEST_F(UnitConstCircular, MakeHelper1)
{
        auto it = make_const_circular(m_vector);
        ASSERT_EQ(0U, *it);
}

TEST_F(UnitConstCircular, MakeHelper2)
{
        auto it = make_const_circular(m_vector, ++m_vector.begin());
        EXPECT_EQ(m_vector[1], *it);
}

TEST_F(UnitConstCircular, MakeHelper3)
{
        auto iref = ++(++m_vector.begin());
        auto it = make_const_circular(m_vector.begin(), m_vector.end(), iref);
        EXPECT_EQ(m_vector[2], *it);
}

TEST_F(UnitConstCircular, Dereference)
{
        CII it = make_const_circular(m_vector);
        ASSERT_EQ(true, (*it) == 0U);
}

TEST_F(UnitConstCircular, StructureDereference)
{
        CDI it = make_const_circular(m_dummy);
        ASSERT_EQ(true, it->f() == 0U);
}

TEST_F(UnitConstCircular, Increment)
{
        CII it = make_const_circular(m_vector);
        ASSERT_EQ(true, *(++it) == 1U);
}

TEST_F(UnitConstCircular, IncrementPastEnd)
{
        CII it = make_const_circular(m_vector);
        ASSERT_EQ(true, *(++it) == 1U);
        ASSERT_EQ(true, *(++it) == 2U);
        ASSERT_EQ(true, *(++it) == 3U);
        ASSERT_EQ(true, *(++it) == 0U);
}

TEST_F(UnitConstCircular, PostIncrement)
{
        CII it = make_const_circular(m_vector);
        ASSERT_EQ(true, *(it++) == 0U && *it == 1U);
}

TEST_F(UnitConstCircular, Decrement)
{
        CII it = make_const_circular(m_vector);
        ASSERT_EQ(true, *(++it) == 1U);
        ASSERT_EQ(true, *(++it) == 2U);
        ASSERT_EQ(true, *(--it) == 1U);
        ASSERT_EQ(true, *(--it) == 0U);
}

TEST_F(UnitConstCircular, DecrementPastBegin)
{
        CII it = make_const_circular(m_vector);
        ASSERT_EQ(true, *(--it) == 3U);
        ASSERT_EQ(true, *(--it) == 2U);
}

TEST_F(UnitConstCircular, PostDecrement)
{
        CII it = make_const_circular(m_vector);
        ASSERT_EQ(true, *(it--) == 0U && *it == 3U);
}

TEST_F(UnitConstCircular, Equality)
{
        CII it = make_const_circular(m_vector);
        ASSERT_EQ(true, it == it);
        ++it;
        ASSERT_EQ(true, it == it);
}

TEST_F(UnitConstCircular, Inequality)
{
        CII it1 = make_const_circular(m_vector);
        CII it2 = make_const_circular(m_vector);
        ASSERT_EQ(true, it1 != ++it2);
}

TEST_F(UnitConstCircular, NextHelper)
{
        CII it1 = make_const_circular(m_vector);
        ASSERT_EQ(true, *next(it1) == 1U);
        ASSERT_EQ(true, *it1 == 0);
}

TEST_F(UnitConstCircular, PreviousHelper)
{
        CII it1 = make_const_circular(m_vector);
        ASSERT_EQ(true, *prev(it1) == 3U);
        ASSERT_EQ(true, *it1 == 0);
}

} // namespace Tests
} // namespace Container
} // namespace UA_CoMP

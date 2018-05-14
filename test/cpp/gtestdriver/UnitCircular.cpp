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

#include "container/CircularIterator.h"

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

class UnitCircular : public ::testing::Test
{
protected:
        virtual void SetUp() {}

        virtual void TearDown() {}

        vector<unsigned int> m_vector{0U, 1U, 2U, 3U};
        vector<Dummy> m_dummy{Dummy(0U), Dummy(1U), Dummy(2U), Dummy(3U)};

        typedef vector<unsigned int>::iterator VII;
        typedef CircularIterator<VII> CII;
        typedef vector<Dummy>::iterator VDI;
        typedef CircularIterator<VDI> CDI;
};

TEST_F(UnitCircular, Instantiation)
{
        CII it(m_vector.begin(), m_vector.end(), m_vector.begin());
        EXPECT_EQ(true, it == it);
}

TEST_F(UnitCircular, BaseAssignment)
{
        VII vit = m_vector.begin();
        CII cit1(m_vector.begin(), m_vector.end(), m_vector.begin());
        CII cit2(m_vector.begin(), m_vector.end(), m_vector.end());
        cit2 = vit;
        EXPECT_EQ(true, cit1 == cit2);
}

TEST_F(UnitCircular, BaseEquality)
{
        auto vit = m_vector.begin();
        auto it = make_circular(m_vector);
        EXPECT_EQ(true, it == vit);
}

TEST_F(UnitCircular, BaseInequality)
{
        auto vit = m_vector.begin();
        auto it = make_circular(m_vector);
        EXPECT_EQ(true, it != ++vit);
}

TEST_F(UnitCircular, BaseTypeConversion)
{
        auto it = make_circular(m_vector);
        EXPECT_EQ(true, m_vector.begin() == CII::base_type(it));
}

TEST_F(UnitCircular, MakeHelper1)
{
        auto it = make_circular(m_vector);
        *it = 5U;
        EXPECT_EQ(5U, m_vector[0]);
}

TEST_F(UnitCircular, MakeHelper2)
{
        auto it1 = make_circular(m_vector, ++m_vector.begin());
        *it1 = 5U;
        EXPECT_EQ(5U, m_vector[1]);
}

TEST_F(UnitCircular, MakeHelper3)
{
        auto iref = ++(++m_vector.begin());
        auto it = make_circular(m_vector.begin(), m_vector.end(), iref);
        *it = 5U;
        EXPECT_EQ(5U, m_vector[2]);
}

TEST_F(UnitCircular, Dereference)
{
        auto it = make_circular(m_vector);
        EXPECT_EQ(0U, *it);
        *it = 4U;
        ++(++(++(++it)));
        EXPECT_EQ(4U, *it);
}

TEST_F(UnitCircular, StructureDereference)
{
        auto it = make_circular(m_dummy);
        EXPECT_EQ(0U, it->f());
}

TEST_F(UnitCircular, Increment)
{
        auto it = make_circular(m_vector);
        EXPECT_EQ(1U, *(++it));
}

TEST_F(UnitCircular, IncrementPastEnd)
{
        auto it = make_circular(m_vector);
        EXPECT_EQ(1U, *(++it));
        EXPECT_EQ(2U, *(++it));
        EXPECT_EQ(3U, *(++it));
        EXPECT_EQ(0U, *(++it));
}

TEST_F(UnitCircular, PostIncrement)
{
        auto it = make_circular(m_vector);
        EXPECT_EQ(0U, *(it++));
        EXPECT_EQ(1U, *it);
}

TEST_F(UnitCircular, Decrement)
{
        auto it = make_circular(m_vector);
        EXPECT_EQ(1U, *(++it));
        EXPECT_EQ(2U, *(++it));
        EXPECT_EQ(1U, *(--it));
        EXPECT_EQ(0U, *(--it));
}

TEST_F(UnitCircular, DecrementPastBegin)
{
        auto it = make_circular(m_vector);
        EXPECT_EQ(3U, *(--it));
        EXPECT_EQ(2U, *(--it));
}

TEST_F(UnitCircular, PostDecrement)
{
        auto it = make_circular(m_vector);
        EXPECT_EQ(0U, *(it--));
        EXPECT_EQ(3U, *it);
}

TEST_F(UnitCircular, Equality)
{
        auto it = make_circular(m_vector);
        EXPECT_EQ(true, it == it);
        ++it;
        EXPECT_EQ(true, it == it);
}

TEST_F(UnitCircular, Inequality)
{
        auto it1 = make_circular(m_vector);
        auto it2 = make_circular(m_vector);
        EXPECT_EQ(true, it1 != ++it2);
}

TEST_F(UnitCircular, NextHelper)
{
        auto it1 = make_circular(m_vector);
        EXPECT_EQ(1U, *next(it1));
        EXPECT_EQ(0U, *it1);
}

TEST_F(UnitCircular, PreviousHelper)
{
        auto it1 = make_circular(m_vector);
        EXPECT_EQ(3U, *prev(it1));
        EXPECT_EQ(0U, *it1);
}

TEST_F(UnitCircular, Loop1)
{
        auto it1 = make_circular(m_vector);
        do {
                *it1 = 0U;
        } while (++it1 != m_vector.begin());

        EXPECT_EQ(0U, m_vector[0]);
        EXPECT_EQ(0U, m_vector[1]);
        EXPECT_EQ(0U, m_vector[2]);
        EXPECT_EQ(0U, m_vector[3]);
}

TEST_F(UnitCircular, Loop2)
{
        auto iref = ++(++m_vector.begin());
        auto it1 = make_circular(m_vector, iref);
        auto i = 0U;
        do {
                *it1 = i++;
        } while (++it1 != iref);

        EXPECT_EQ(2U, m_vector[0]);
        EXPECT_EQ(3U, m_vector[1]);
        EXPECT_EQ(0U, m_vector[2]);
        EXPECT_EQ(1U, m_vector[3]);
}

TEST_F(UnitCircular, Loop3)
{
        auto iref = ++(++m_vector.begin());
        auto it1 = make_circular(m_vector, iref);
        auto i = 5U;
        do {
                *it1 = i++;
        } while (--it1 != iref);

        EXPECT_EQ(7U, m_vector[0]);
        EXPECT_EQ(6U, m_vector[1]);
        EXPECT_EQ(5U, m_vector[2]);
        EXPECT_EQ(8U, m_vector[3]);
}

} // namespace Tests
} // namespace Container
} // namespace UA_CoMP

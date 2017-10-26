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
* Tests for Timekeeper.
*/

#include "timekeeper/ClockTraits.h"
#include "timekeeper/CumulativeRecords.h"
#include <gtest/gtest.h>
#include <utility>
#include <vector>

namespace UA_CoMP {
namespace Timekeeper {

using namespace std;
using namespace std::chrono;

class UnitRecords : public ::testing::Test
{
protected:
        virtual void SetUp() {}

        virtual void TearDown() {}

        Records<milliseconds> m_milli;
        Records<milliseconds> m_milli2;
        Records<seconds> m_secs;
};

TEST_F(UnitRecords, Absent)
{
        EXPECT_FALSE(m_milli.IsPresent("haha")) << "Name should be absent.";
        EXPECT_EQ(0U, m_milli.GetCount("haha")) << "Count should be zero for absent name.";
}

TEST_F(UnitRecords, Record)
{
        const milliseconds d{3};
        m_milli.Record("name1", d);

        EXPECT_FALSE(m_milli.IsPresent("haha")) << "Name should be absent.";
        EXPECT_TRUE(m_milli.IsPresent("name1")) << "Name should be present.";
        EXPECT_EQ(0U, m_milli.GetCount("haha")) << "Count should be zero for absent name.";
        EXPECT_EQ(1U, m_milli.GetCount("name1")) << "Count should be one.";
        EXPECT_EQ(d, m_milli.GetCumulative("name1")) << "Result of GetCumulative in error.";
        EXPECT_EQ(1U, m_milli.GetRecord("name1").size()) << "Record name1 has wrong size.";
        EXPECT_EQ(3, m_milli.GetRecord("name1")[0].count()) << "The element 1 in Record name1 wrong.";

        m_milli.Record("name1", milliseconds{6});
        const unsigned int j1 = m_milli.GetCumulative("name1").count();
        const unsigned int m1 = m_milli.GetMean("name1").count();

        EXPECT_EQ(2U, m_milli.GetCount("name1")) << "Count should be one.";
        EXPECT_EQ(9U, j1) << "Result of GetCumulative in error.";
        EXPECT_EQ(4U, m1) << "Result of GetMean in error.";
        EXPECT_EQ(2U, m_milli.GetRecord("name1").size()) << "Record name1 has wrong size.";
        EXPECT_EQ(3, m_milli.GetRecord("name1")[0].count()) << "The element 1 in Record name1 wrong.";
        EXPECT_EQ(6, m_milli.GetRecord("name1")[1].count()) << "The element 2 in Record name1 wrong.";
}

TEST_F(UnitRecords, RecordCast1)
{
        m_milli.Record("name1", nanoseconds{3});
        const auto j1 = duration_cast<nanoseconds>(m_milli.GetCumulative("name1")).count();

        EXPECT_EQ(0, j1) << "Record nanos in milli records truncates.";
}

TEST_F(UnitRecords, RecordCast2)
{
        m_milli.Record("name1", milliseconds{3});
        const auto j1 = duration_cast<milliseconds>(m_milli.GetCumulative("name1")).count();

        EXPECT_EQ(3, j1) << "RecordCast not working OK with milliseconds.";
}

TEST_F(UnitRecords, RecordCast3)
{
        m_milli.Record("name1", minutes{3});
        const auto j1 = duration_cast<minutes>(m_milli.GetCumulative("name1")).count();

        EXPECT_EQ(3, j1) << "RecordCast not working OK with minutes.";
}

TEST_F(UnitRecords, GetRecords)
{
        m_milli.Record("name1", milliseconds{2});
        m_milli.Record("name1", seconds{1});
        m_milli.Record("name2", seconds{3});
        m_milli2 = m_milli.GetRecords();

        EXPECT_EQ(2U, m_milli2.GetNames().size()) << "GetNames has wrong size.";
        EXPECT_EQ(2U, m_milli2.GetCount("name1")) << "GetCount for name1 in error.";
        EXPECT_EQ(2U, m_milli2.GetRecord("name1").size()) << "Error in records for name1.";
        EXPECT_EQ(1U, m_milli2.GetRecord("name2").size()) << "Error in records for name2.";
}

TEST_F(UnitRecords, GetRecordsCast)
{
        m_milli.Record("name1", milliseconds{2});
        m_milli.Record("name1", seconds{1});
        m_milli.Record("name2", seconds{3});
        m_secs = m_milli.GetRecords<seconds>();

        EXPECT_EQ(2U, m_secs.GetNames().size()) << "GetNames has wrong size.";
        EXPECT_EQ(2U, m_secs.GetCount("name1")) << "GetCount for name1 in error.";
        EXPECT_EQ(0, m_secs.GetRecord("name1")[0].count()) << "Error in element 0 for name1.";
        EXPECT_EQ(0, m_secs.GetRecord("name1")[0].count()) << "Error in element 1 for name1.";
        EXPECT_EQ(3, m_secs.GetCumulative("name2").count()) << "Error in records for name2.";
}

TEST_F(UnitRecords, Merge)
{
        m_milli.Record("name1", milliseconds{2});
        m_milli2.Record("name2", milliseconds{3});
        m_milli2.Record("name1", milliseconds{5});
        m_milli.Merge(m_milli2);

        EXPECT_EQ(2U, m_milli.GetNames().size()) << "GetNames has wrong size.";
        EXPECT_EQ(7, m_milli.GetCumulative("name1").count()) << "Error in records for name1.";
        EXPECT_EQ(3, m_milli.GetCumulative("name2").count()) << "Error in records for name2.";
}

TEST_F(UnitRecords, MergeCast)
{
        m_milli.Record("name1", milliseconds{2});
        m_secs.Record("name2", seconds{3});
        m_secs.Record("name1", seconds{5});
        m_milli.Merge(m_secs);

        EXPECT_EQ(2U, m_milli.GetNames().size()) << "GetNames has wrong size.";
        EXPECT_EQ(5002, m_milli.GetCumulative("name1").count()) << "Error in records for name1.";
        EXPECT_EQ(3000, m_milli.GetCumulative("name2").count()) << "Error in records for name2.";
}

} // namespace Timekeeper
} // namespace-UA_CoMP

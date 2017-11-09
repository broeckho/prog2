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

#include "template_quad/quad.h"
#include <gtest/gtest.h>

namespace UA_CoMP {
namespace Num {
namespace QuadTests {

/// Test GetOrder method.
TEST(QuadTest, GetOrder)
{
        AdaptiveQuadrature<GaussLegendre16Rule, GaussLegendre32Rule> quad(1.0e-6, 1, 100);
        ASSERT_EQ(static_cast<unsigned int>(16), quad.rule1().getOrder());
        ASSERT_EQ(static_cast<unsigned int>(32), quad.rule2().getOrder());
}

/// Test accessors.
TEST(QuadTest, ConvergenceTolerance)
{
        AdaptiveQuadrature<GaussLegendre4Rule, GaussLegendre8Rule> quad(1.0e-6, 1, 100);
        quad.setConvergenceTolerance(1.0e-10);
        ASSERT_NEAR(quad.getConvergenceTolerance(), 1.0e-10, 1.0e-14);
}

/// Test accessors.
TEST(QuadTest, InitialCellCount)
{
        AdaptiveQuadrature<GaussLegendre4Rule, GaussLegendre8Rule> quad(1.0e-6, 1, 100);
        quad.setInitialCellCount(30);
        ASSERT_EQ(static_cast<unsigned int>(30), quad.getInitialCellCount());
}

/// Test accessors.
TEST(QuadTest, CellCountLimit)
{
        AdaptiveQuadrature<GaussLegendre4Rule, GaussLegendre8Rule> quad(1.0e-6, 1, 100);
        quad.setCellCountLimit(130);
        ASSERT_EQ(static_cast<unsigned int>(130), quad.getCellCountLimit());
}

/// Test the bisector meta rule.
TEST(QuadTest, BiSector)
{
        OscillatoryFunctor f(-1.0, 20.0);
        double const check = GaussLegendre16Rule::sum(0.0, 0.5, f) + GaussLegendre16Rule::sum(0.5, 0.5, f);
        double const sum = Bisector<GaussLegendre16Rule>::sum(0.0, 1.0, f);
        ASSERT_NEAR(sum, check, 1.0e-14);
}

/// Invoke evaluate member.
TEST(QuadTest, Evaluate)
{
        OscillatoryFunctor f(-1.0, 20.0);
        AdaptiveQuadrature<GaussLegendre8Rule> quad(1.0e-7, 1, 1000);
        std::tuple<bool, double, double, unsigned int> const retValue = quad.evaluate(-1.0, 2.0, f);
        double const sum2 = std::get<2>(retValue);
        double const check = f.getIntegral()(-1.0, 2.0);
        ASSERT_NEAR(check, sum2, 1.0e-8);
}

/// Invoke operator().
TEST(QuadTest, CallOperator)
{
        OscillatoryFunctor f(-1.0, 20.0);
        AdaptiveQuadrature<GaussLegendre8Rule> quad(1.0e-7, 1, 1000);
        double const integ = quad(-1.0, 2.0, f);
        double const check = f.getIntegral()(-1.0, 2.0);
        ASSERT_NEAR(check, integ, 1.0e-8);
}

/// Invoke operator() now using an initial cell count.
TEST(QuadTest, CellCount)
{
        OscillatoryFunctor f(-1.0, 20.0);
        AdaptiveQuadrature<GaussLegendre8Rule> quad(1.0e-7, 1, 1000);
        quad.setInitialCellCount(50);
        double const integ = quad(-1.0, 2.0, f);
        double const check = f.getIntegral()(-1.0, 2.0);
        ASSERT_NEAR(check, integ, 1.0e-8);
}

/// Test throwing an exception when cellCount exceeded.
TEST(QuadTest, CellCountException)
{
        OscillatoryFunctor f(-1.0, 20.0);
        AdaptiveQuadrature<GaussLegendre4Rule, GaussLegendre8Rule> quad(1.0e-14, 1, 10);
        ASSERT_THROW(quad.evaluate(0.0, 15.0, f), std::runtime_error);
}

/// Test not throwing an exception when cellCount exceeded.
TEST(QuadTest, CellCountNoException)
{
        OscillatoryFunctor f(-1.0, 20.0);
        AGL_Quadrature<4, 8, ComboDifference, OnViolationReturn> quad(1.0e-14, 1, 10);
        std::tuple<bool, double, double, unsigned int> const retValue = quad.evaluate(0.0, 15.0, f);
        unsigned int const cell_count = std::get<3>(retValue);
        ASSERT_EQ(quad.getCellCountLimit(), cell_count);
}

} // end-of-namespace QuadTests
} // end-of-namespace-Num
} // end-of-namespace-UA_CoMP

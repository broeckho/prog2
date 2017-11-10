#pragma once
/**
 * @file
 * AGL (Adaptive GaussLegendre) Quadrature.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */

#include "AdaptiveQuadrature.h"
#include "GaussLegendreRules.h"
#include <cassert>

namespace UA_CoMP {
namespace Num {

/**
 * Template definition to allow compile-time selection of GaussLegendre rules.
 */
template <int N>
class GaussLegendreSelect
{
};

/**
 * Specialization to select GauusLegendre2 Rule.
 */
template <>
class GaussLegendreSelect<2>
{
public:
        using Rule =  GaussLegendre2Rule;
};

/**
 * Specialization to select GauusLegendre4 Rule.
 */
template <>
class GaussLegendreSelect<4>
{
public:
        using Rule =  GaussLegendre2Rule;
};

/**
 * Specialization to select GauusLegendre8 Rule.
 */
template <>
class GaussLegendreSelect<8>
{
public:
        using Rule =  GaussLegendre8Rule;
};

/**
 * Specialization to select GauusLegendre16 Rule.
 */
template <>
class GaussLegendreSelect<16>
{
public:
        using Rule =  GaussLegendre16Rule;
};

/**
 * Specialization to select GauusLegendre32 Rule.
 */
template <>
class GaussLegendreSelect<32>
{
public:
        using Rule =  GaussLegendre32Rule;
};

/**
 * AGL (Adaptive GaussLegendre) Quadrature.
 * The rule orders are compile time constants.
 * Helper construction to mitigate absence of typedefs template.
 * See Herb. Sutter in C++ Users Journal, December 2002.
 */
template <int N1, int N2, typename ConvergencePolicy = ComboDifference, typename CellCountPolicy = OnViolationThrow>
class AGL_Quadrature
    : public AdaptiveQuadrature<typename GaussLegendreSelect<N1>::Rule, typename GaussLegendreSelect<N2>::Rule,
                                ConvergencePolicy, CellCountPolicy>
{
public:
        /** Constructor initializes everything.*/
        AGL_Quadrature(double convergenceTolerance, unsigned int initialCellCount, unsigned int cellCountLimit)
            : AdaptiveQuadrature<typename GaussLegendreSelect<N1>::Rule, typename GaussLegendreSelect<N2>::Rule,
                                 ConvergencePolicy, CellCountPolicy>(convergenceTolerance, initialCellCount,
                                                                     cellCountLimit)
        {
                assert(N1 != N2);
        }

private:
};

} // end-of-namespace
} // end-of-namespace


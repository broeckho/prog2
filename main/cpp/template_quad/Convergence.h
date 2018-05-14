#pragma once
/**
 * @file
 * Predefined convergence policies for the AdaptiveQuadrature template.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */
#include <cmath>

namespace UA_CoMP {
namespace Num {

/**
 * Policy that checks convergence via absolute difference.
 */
class AbsoluteDifference
{
public:
        /** Returns true iff the absolute difference is below tolerance. */
        static double evaluate(double v1, double v2) { return std::fabs(v1 - v2); }
};

/**
 * Policy that checks convergence via combo difference.
 * Cfr. A Numerical Library in C, H. T. Lau, CRC Press, Ch. 4.2.1
 */
class ComboDifference
{
public:
        /** Returns true iff combo difference is below tolerance. */
        static double evaluate(double v1, double v2)
        {
                return std::fabs(v1 - v2) / (1.0 + std::fabs(v1) + std::fabs(v2));
        }
};

} // namespace Num
} // namespace UA_CoMP

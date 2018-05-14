#pragma once
/**
 * @file
 * Utilities.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */
#include <functional>

namespace UA_CoMP {
namespace Num {

/// Compares two functors on a grid and returns maximum absolute difference.
double abs_diff(double b, double e, double h, std::function<double(double)> f1, std::function<double(double)> f2);

} // namespace Num
} // namespace UA_CoMP

#ifndef INC_ABSDIFF_H
#define INC_ABSDIFF_H
/**
 * @file
 * Utilities.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */
#include <functional>

namespace UA_CoMP {
namespace Num {

double abs_diff(double b, double e, double h, std::function<double(double)> f1, std::function<double(double)> f2);

} // end-of-namespace-Num
} // end-of-namespace-UA_CoMP

#endif // end-of-include-guard

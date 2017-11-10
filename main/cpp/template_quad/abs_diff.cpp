/**
 * @file
 * abs_diff utility function.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */

#include "abs_diff.h"
#include <cmath>

namespace UA_CoMP {
namespace Num {

using std::function;

/**
* Compares two functors on a grid and returns maximum absolute difference.
*/
double abs_diff(double b, double e, double h, function<double(double)> f1, function<double(double)> f2)
{
        double maxDiff = 0.0;
        auto n = static_cast<unsigned int>((e-b)/h);
        for (int i=0; i < n; ++i) {
                double y = b + static_cast<double>(i) * h;
                double const temp = std::fabs(f1(y) - f2(y));
                maxDiff = (temp > maxDiff ? temp : maxDiff);
        }
        return maxDiff;
}

} // end-of-namespace
} // end-of-namespace

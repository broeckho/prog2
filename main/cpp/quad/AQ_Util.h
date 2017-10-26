#ifndef GOBELIJN_QUAD_AQ_UTIL_H_INCLUDED
#define GOBELIJN_QUAD_AQ_UTIL_H_INCLUDED
/**
 * @file
 * Utilities for the implementation of the Adaptive Quadrature.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */
#include <type_traits>

namespace UA_CoMP {
namespace Num {

/** Convert T const& to T */
template <typename T>
class StripConstRef
{
public:
        typedef typename std::remove_cv<typename std::remove_reference<T>::type>::type type;
};

} // end-of-namespace Num
} // end-of-namespace-UA_CoMP

#endif // end-of-include-guard

#pragma once
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
        using type = typename std::remove_cv<typename std::remove_reference<T>::type>::type;
};

} // namespace Num
} // namespace UA_CoMP

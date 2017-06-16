#ifndef GOBELIJN_QUAD_SIMPLERULES_H_INCLUDED
#define GOBELIJN_QUAD_SIMPLERULES_H_INCLUDED
/**
 * @file
 * Elementary Quadrature Rules.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */
#include "quad/AQ_Util.h"

namespace UA_CoMP {
namespace Num {

/**
 * The Simpson rule.
 * Cfr. The Handbook of Mathematical Functions,
 * M. Abramowitz and I. Stegun, Dover Publications
 * Chapter 25, item 25.4.5.
 */
class SimpsonRule
{
public:
	/**
	 * Execute the rule on the cell.
	 * @return              Sum of functor values in quadrature points of cell
	 * @param       l       Left bounadry of quadrature domain
	 * @param       d       Distance to right boundary of the domain
	 * @param       f       Functor that gets summed
	 * @exception           none
	 */
	template <class Ftor>
	static typename Ftor::result_type sum(typename Ftor::argument_type l, typename Ftor::argument_type d, Ftor f)
	{
		typedef typename StripConstRef<typename Ftor::argument_type>::type Arg;
		typedef typename StripConstRef<typename Ftor::result_type>::type Res;

		Arg const h = static_cast<Arg>(0.5) * d;
		Arg const r = l + d;
		return static_cast<Res>(0.333333333333333) * h * (f(l) + static_cast<Res>(4.0) * f(l + h) + f(r));
	}
};

} // end-of-namespace Num
} // end-of-namespace-UA_CoMP

#endif // end-of-include-guard

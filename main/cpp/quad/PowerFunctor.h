#ifndef GOBELIJN_QUAD_POWERFUNCTOR_H
#define GOBELIJN_QUAD_POWERFUNCTOR_H
/**
 * @file
 * Power functor.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */
#include "quad/AQ_Util.h"
#include <cmath>
#include <functional>

namespace UA_CoMP {
namespace Num {

/**
 * Power Functor.
 */
class PowerFunctor : public std::unary_function<double, double>
{
public:
	/** Nested class contains the analytic integral of the functor for testing
	 * purposes. */
	class Integral : public std::binary_function<argument_type, argument_type, result_type>
	{
	public:
		/** Non-default constructor. */
		Integral(int n) : fN(n) {}

		/** The definite integral from a to b */
		result_type operator()(first_argument_type a, first_argument_type b) const
		{
			return (std::pow(b, fN + 1) - std::pow(a, fN + 1)) / static_cast<result_type>(fN + 1);
		}

	private:
		int fN;
	};

	/** Straightforward constructor. */
	PowerFunctor(int n) : fN(n), fIntegral(n) {}

	/** Evaluation operator. */
	result_type operator()(argument_type x) const { return std::pow(x, fN); }

	/** Return the analytic integral object.*/
	Integral getIntegral() const { return fIntegral; }

private:
	int fN;
	Integral fIntegral;
};

} // end-of-namespace-Num
} // end-of-namespace-UA_CoMP

#endif // end-of-include-guard

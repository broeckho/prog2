#ifndef GOBELIJN_QUAD_OSCILLATORYFUNCTOR_H
#define GOBELIJN_QUAD_OSCILLATORYFUNCTOR_H
/**
 * @file
 * Oscillatory functor.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 201.
 */
#include "quad/AQ_Util.h"
#include <cmath>
#include <functional>

namespace UA_CoMP {
namespace Num {
using std::exp;
using std::sin;
using std::cos;
/**
 * Oscillatory functor.
 * Cfr. The Handbook of Mathematical Functions,
 * M. Abramowitz and I. Stegun, Dover Publications, Item 4.3.136.
 */
class OscillatoryFunctor : public std::unary_function<double, double>
{
public:
        typedef argument_type Arg;
        typedef result_type Res;

        /** Nested class contains the analytic integral of the functor for testing
         * purposes. */
        class Integral : public std::binary_function<Arg, Arg, Res>
        {
        public:
                /** Non-default constructor. */
                Integral(Arg a, Arg b) : fA(a), fB(b) {}

                /** The definite integral from a to b */
                result_type operator()(Arg a, Arg b) const
                {
                        return ((exp(fA * b) * (fA * sin(fB * b) - fB * cos(fB * b)) + fB) -
                                (exp(fA * (double)a) * (fA * sin(fB * a) - fB * cos(fB * a)) + fB)) /
                               (fA * fA + fB * fB);
                }

        private:
                Arg fA;
                Arg fB;
        };

        /** Straightforward constructor. */
        OscillatoryFunctor(argument_type a, argument_type b) : fA(a), fB(b), fIntegral(a, b) {}

        /** Functor evaluation. */
        result_type operator()(argument_type x) const { return exp(fA * x) * sin(fB * x); }

        /** Return the analytic integral object.*/
        Integral getIntegral() const { return fIntegral; }

private:
        double fA;
        double fB;
        Integral fIntegral;
};

} // end-of-namespace-Num
} // end-of-namespace-UA_CoMP

#endif // end-of-include-guard

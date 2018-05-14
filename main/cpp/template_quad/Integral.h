#pragma once
/**
 * @file
 * The Integral wrapper template.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */
#include <functional>

namespace UA_CoMP {
namespace Num {

/**
 * Wrap a quadrature algoritm and a functor to produce an integral.
 * The integral is a function of its lower and upper integration boundaries.
 * It models the adaptable binary function concept.
 */
template <typename QuadAlgorithm, typename Integrand>
class Integral : public std::binary_function<typename Integrand::argument_type, typename Integrand::argument_type,
                                             typename Integrand::result_type>
{
public:
        /**
         * Constructor initializes all datamembers.
         * @param       quad        Quadrature algorithm that computes the integral.
         * @param       ftor        Functor that get integrated.
         */
        Integral(QuadAlgorithm const& quad, Integrand const& ftor) : fQuadAlgorithm(quad), fIntegrand(ftor) {}

        /**
         * Evaluates integral from l to r.
         * @return                  Value of the integral.
         * @param       l           Left integration boundary.
         * @param       r           Right integration boundary.
         */
        typename Integral::result_type operator()(typename Integral::first_argument_type l,
                                                  typename Integral::first_argument_type r) const
        {
                return fQuadAlgorithm(l, r, fIntegrand);
        }

private:
        QuadAlgorithm fQuadAlgorithm;
        Integrand fIntegrand;
};

/**
 * Helper function that returns an Integral for a
 * quadrature algorithm and a functor.
 */
template <typename QuadAlgorithm, typename Integrand>
inline Integral<QuadAlgorithm, Integrand> make_integral(QuadAlgorithm const& quad, Integrand const& ftor)
{
        return Integral<QuadAlgorithm, Integrand>(quad, ftor);
}

} // namespace Num
} // namespace UA_CoMP

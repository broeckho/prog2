#ifndef GOBELIJN_QUAD_GAUSSLEGENDRERULES_H_INCLUDED
#define GOBELIJN_QUAD_GAUSSLEGENDRERULES_H_INCLUDED
/**
 * @file
 * GaussLegendre Quadrature Rules.
 * Header file implements GaussLegendre of orders 2, 4, 8, 16, 32.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */

namespace UA_CoMP {
namespace Num {

/**
 * The Gauss-Legendre rule of order 2.
 * Cfr. The Handbook of Mathematical Functions,
 * M. Abramowitz and I. Stegun, Dover Publications
 * Chapter 25, Table 25.4.
 */
class GaussLegendre2Rule
{
public:
        /**
         * Return the order of the rule.
         * @return              Order of the rule.
         * @exception           None.
         */
        static unsigned int getOrder() { return 2; }

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

                double const z1 = 0.577350269189626;

                Arg const h = 0.5 * d;
                Arg const m = l + h;
                return static_cast<Res>(h * (f(m - z1 * h) + f(m + z1 * h)));
        }
};

/**
 * The Gauss-Legendre rule of order 4.
 * Cfr. The Handbook of Mathematical Functions,
 * M. Abramowitz and I. Stegun, Dover Publications
 * Chapter 25, Table 25.4.
 */
class GaussLegendre4Rule
{
public:
        /**
         * Return the order of the rule.
         * @return              Order of the rule.
         * @exception           None.
         */
        static unsigned int getOrder() { return 4; }

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

                double const z1 = 0.339981043584856;
                double const z2 = 0.861136311594053;
                double const w1 = 0.652145154862546;
                double const w2 = 0.347854845137454;

                Arg const h = 0.5 * d;
                Arg const m = l + h;
                Res const s = w1 * (f(m - z1 * h) + f(m + z1 * h)) + w2 * (f(m - z2 * h) + f(m + z2 * h));
                return h * s;
        }
};

/**
 * The Gauss-Legendre rule of order 8.
 * Cfr. The Handbook of Mathematical Functions,
 * M. Abramowitz and I. Stegun, Dover Publications
 * Chapter 25, Table 25.4.
 */
class GaussLegendre8Rule
{
public:
        /**
         * Return the order of the rule.
         * @return              Order of the rule.
         * @exception           None.
         */
        static unsigned int getOrder() { return 8; }

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

                double const z1 = 0.183434642495650;
                double const z2 = 0.525532409916329;
                double const z3 = 0.796666477413627;
                double const z4 = 0.960289856497536;

                double const w1 = 0.362683783378362;
                double const w2 = 0.313706645877887;
                double const w3 = 0.222381034453374;
                double const w4 = 0.101228536290376;

                Arg const h = 0.5 * d;
                Arg const m = l + h;
                Res const s = w1 * (f(m - z1 * h) + f(m + z1 * h)) + w2 * (f(m - z2 * h) + f(m + z2 * h)) +
                              w3 * (f(m - z3 * h) + f(m + z3 * h)) + w4 * (f(m - z4 * h) + f(m + z4 * h));
                return h * s;
        }
};

/**
 * The Gauss-Legendre rule of order 16.
 * Cfr. The Handbook of Mathematical Functions,
 * M. Abramowitz and I. Stegun, Dover Publications
 * Chapter 25, Table 25.4.
 */
class GaussLegendre16Rule
{
public:
        /**
         * Return the order of the rule.
         * @return              Order of the rule.
         * @exception           None.
         */
        static unsigned int getOrder() { return 16; }

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

                double const z1 = 0.0950125098376374;
                double const z2 = 0.281603550779259;
                double const z3 = 0.458016777657227;
                double const z4 = 0.617876244402644;
                double const z5 = 0.755404408355003;
                double const z6 = 0.865631202387832;
                double const z7 = 0.944575023073233;
                double const z8 = 0.989400934991650;

                double const w1 = 0.189450610455068;
                double const w2 = 0.182603415044924;
                double const w3 = 0.169156519395003;
                double const w4 = 0.149595988816577;
                double const w5 = 0.124628971255534;
                double const w6 = 0.0951585116824928;
                double const w7 = 0.0622535239386479;
                double const w8 = 0.0271524594117541;

                Arg const h = 0.5 * d;
                Arg const m = l + h;
                Res const s = w1 * (f(m - z1 * h) + f(m + z1 * h)) + w2 * (f(m - z2 * h) + f(m + z2 * h)) +
                              w3 * (f(m - z3 * h) + f(m + z3 * h)) + w4 * (f(m - z4 * h) + f(m + z4 * h)) +
                              w5 * (f(m - z5 * h) + f(m + z5 * h)) + w6 * (f(m - z6 * h) + f(m + z6 * h)) +
                              w7 * (f(m - z7 * h) + f(m + z7 * h)) + w8 * (f(m - z8 * h) + f(m + z8 * h));
                return h * s;
        }
};

/**
 * The Gauss-Legendre rule of order 32.
 * Cfr. The Handbook of Mathematical Functions,
 * M. Abramowitz and I. Stegun, Dover Publications
 * Chapter 25, Table 25.4.
 */
class GaussLegendre32Rule
{
public:
        /**
         * Return the order of the rule.
         * @return              Order of the rule.
         * @exception           None.
         */
        static unsigned int getOrder() { return 32; }

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

                double const z1 = 0.99726386184948;
                double const z2 = 0.98561151154527;
                double const z3 = 0.96476225558751;
                double const z4 = 0.93490607593774;
                double const z5 = 0.89632115576605;
                double const z6 = 0.84936761373257;
                double const z7 = 0.79448379596794;
                double const z8 = 0.73218211874029;
                double const z9 = 0.66304426693022;
                double const z10 = 0.58771575724076;
                double const z11 = 0.50689990893223;
                double const z12 = 0.42135127613064;
                double const z13 = 0.33186860228213;
                double const z14 = 0.23928736225214;
                double const z15 = 0.14447196158280;
                double const z16 = 0.048307665687738;

                double const w1 = 0.0070186100094701;
                double const w2 = 0.016274394730906;
                double const w3 = 0.025392065309262;
                double const w4 = 0.034273862913021;
                double const w5 = 0.042835898022227;
                double const w6 = 0.050998059262376;
                double const w7 = 0.058684093478536;
                double const w8 = 0.065822222776362;
                double const w9 = 0.072345794108849;
                double const w10 = 0.078193895787070;
                double const w11 = 0.083311924226947;
                double const w12 = 0.087652093004404;
                double const w13 = 0.091173878695764;
                double const w14 = 0.093844399080805;
                double const w15 = 0.095638720079275;
                double const w16 = 0.096540088514728;

                Arg const h = 0.5 * d;
                Arg const m = l + h;
                // The sum was split in two contributions because the CodeWarrior 5.0 chokes
                // otherwise.
                Res s1 = w1 * (f(m - z1 * h) + f(m + z1 * h)) + w2 * (f(m - z2 * h) + f(m + z2 * h)) +
                         w3 * (f(m - z3 * h) + f(m + z3 * h)) + w4 * (f(m - z4 * h) + f(m + z4 * h)) +
                         w5 * (f(m - z5 * h) + f(m + z5 * h)) + w6 * (f(m - z6 * h) + f(m + z6 * h)) +
                         w7 * (f(m - z7 * h) + f(m + z7 * h)) + w8 * (f(m - z8 * h) + f(m + z8 * h));
                s1 += w9 * (f(m - z9 * h) + f(m + z9 * h)) + w10 * (f(m - z10 * h) + f(m + z10 * h)) +
                      w11 * (f(m - z11 * h) + f(m + z11 * h)) + w12 * (f(m - z12 * h) + f(m + z12 * h)) +
                      w13 * (f(m - z13 * h) + f(m + z13 * h)) + w14 * (f(m - z14 * h) + f(m + z14 * h)) +
                      w15 * (f(m - z15 * h) + f(m + z15 * h)) + w16 * (f(m - z16 * h) + f(m + z16 * h));
                return h * s1;
        }
};

} // end-of-namespace Num
} // end-of-namespace-UA_CoMP

#endif // end-of-include-guard

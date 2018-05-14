#pragma once
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
        static constexpr unsigned int getOrder() { return 2; }

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
                using Arg = typename StripConstRef<typename Ftor::argument_type>::type;
                using Res = typename StripConstRef<typename Ftor::result_type>::type;

                constexpr double z1{0.577350269189626};

                const Arg h{0.5 * d};
                const Arg m{l + h};
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
        static constexpr unsigned int getOrder() { return 4; }

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
                using Arg = typename StripConstRef<typename Ftor::argument_type>::type;
                using Res = typename StripConstRef<typename Ftor::result_type>::type;

                constexpr double z1{0.339981043584856};
                constexpr double z2{0.861136311594053};
                constexpr double w1{0.652145154862546};
                constexpr double w2{0.347854845137454};

                const Arg h{0.5 * d};
                const Arg m{l + h};
                const Res s{w1 * (f(m - z1 * h) + f(m + z1 * h)) + w2 * (f(m - z2 * h) + f(m + z2 * h))};
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
        static constexpr unsigned int getOrder() { return 8; }

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
                using Arg = typename StripConstRef<typename Ftor::argument_type>::type;
                using Res = typename StripConstRef<typename Ftor::result_type>::type;

                constexpr double z1{0.183434642495650};
                constexpr double z2{0.525532409916329};
                constexpr double z3{0.796666477413627};
                constexpr double z4{0.960289856497536};

                constexpr double w1{0.362683783378362};
                constexpr double w2{0.313706645877887};
                constexpr double w3{0.222381034453374};
                constexpr double w4{0.101228536290376};

                const Arg h{0.5 * d};
                const Arg m{l + h};
                const Res s{w1 * (f(m - z1 * h) + f(m + z1 * h)) + w2 * (f(m - z2 * h) + f(m + z2 * h)) +
                            w3 * (f(m - z3 * h) + f(m + z3 * h)) + w4 * (f(m - z4 * h) + f(m + z4 * h))};
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
        static constexpr unsigned int getOrder() { return 16; }

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
                using Arg = typename StripConstRef<typename Ftor::argument_type>::type;
                using Res = typename StripConstRef<typename Ftor::result_type>::type;

                constexpr double z1{0.0950125098376374};
                constexpr double z2{0.281603550779259};
                constexpr double z3{0.458016777657227};
                constexpr double z4{0.617876244402644};
                constexpr double z5{0.755404408355003};
                constexpr double z6{0.865631202387832};
                constexpr double z7{0.944575023073233};
                constexpr double z8{0.989400934991650};

                constexpr double w1{0.189450610455068};
                constexpr double w2{0.182603415044924};
                constexpr double w3{0.169156519395003};
                constexpr double w4{0.149595988816577};
                constexpr double w5{0.124628971255534};
                constexpr double w6{0.0951585116824928};
                constexpr double w7{0.0622535239386479};
                constexpr double w8{0.0271524594117541};

                const Arg h{0.5 * d};
                const Arg m{l + h};
                const Res s{w1 * (f(m - z1 * h) + f(m + z1 * h)) + w2 * (f(m - z2 * h) + f(m + z2 * h)) +
                            w3 * (f(m - z3 * h) + f(m + z3 * h)) + w4 * (f(m - z4 * h) + f(m + z4 * h)) +
                            w5 * (f(m - z5 * h) + f(m + z5 * h)) + w6 * (f(m - z6 * h) + f(m + z6 * h)) +
                            w7 * (f(m - z7 * h) + f(m + z7 * h)) + w8 * (f(m - z8 * h) + f(m + z8 * h))};
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
        static constexpr unsigned int getOrder() { return 32; }

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
                using Arg = typename StripConstRef<typename Ftor::argument_type>::type;
                using Res = typename StripConstRef<typename Ftor::result_type>::type;

                constexpr double z1{0.99726386184948};
                constexpr double z2{0.98561151154527};
                constexpr double z3{0.96476225558751};
                constexpr double z4{0.93490607593774};
                constexpr double z5{0.89632115576605};
                constexpr double z6{0.84936761373257};
                constexpr double z7{0.79448379596794};
                constexpr double z8{0.73218211874029};
                constexpr double z9{0.66304426693022};
                constexpr double z10{0.58771575724076};
                constexpr double z11{0.50689990893223};
                constexpr double z12{0.42135127613064};
                constexpr double z13{0.33186860228213};
                constexpr double z14{0.23928736225214};
                constexpr double z15{0.14447196158280};
                constexpr double z16{0.048307665687738};

                constexpr double w1{0.0070186100094701};
                constexpr double w2{0.016274394730906};
                constexpr double w3{0.025392065309262};
                constexpr double w4{0.034273862913021};
                constexpr double w5{0.042835898022227};
                constexpr double w6{0.050998059262376};
                constexpr double w7{0.058684093478536};
                constexpr double w8{0.065822222776362};
                constexpr double w9{0.072345794108849};
                constexpr double w10{0.078193895787070};
                constexpr double w11{0.083311924226947};
                constexpr double w12{0.087652093004404};
                constexpr double w13{0.091173878695764};
                constexpr double w14{0.093844399080805};
                constexpr double w15{0.095638720079275};
                constexpr double w16{0.096540088514728};

                const Arg h{0.5 * d};
                const Arg m{l + h};
                // The sum was split in two contributions because the CodeWarrior 5.0 chokes otherwise.
                const Res s{w1 * (f(m - z1 * h) + f(m + z1 * h)) + w2 * (f(m - z2 * h) + f(m + z2 * h)) +
                            w3 * (f(m - z3 * h) + f(m + z3 * h)) + w4 * (f(m - z4 * h) + f(m + z4 * h)) +
                            w5 * (f(m - z5 * h) + f(m + z5 * h)) + w6 * (f(m - z6 * h) + f(m + z6 * h)) +
                            w7 * (f(m - z7 * h) + f(m + z7 * h)) + w8 * (f(m - z8 * h) + f(m + z8 * h)) +
                            w9 * (f(m - z9 * h) + f(m + z9 * h)) + w10 * (f(m - z10 * h) + f(m + z10 * h)) +
                            w11 * (f(m - z11 * h) + f(m + z11 * h)) + w12 * (f(m - z12 * h) + f(m + z12 * h)) +
                            w13 * (f(m - z13 * h) + f(m + z13 * h)) + w14 * (f(m - z14 * h) + f(m + z14 * h)) +
                            w15 * (f(m - z15 * h) + f(m + z15 * h)) + w16 * (f(m - z16 * h) + f(m + z16 * h))};
                return h * s;
        }
};

} // namespace Num
} // namespace UA_CoMP

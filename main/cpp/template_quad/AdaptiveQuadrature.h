#pragma once
/**
 * @file
 * The AdaptiveQuadrature template.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */

#include "AQ_Util.h"
#include "CellCountViolation.h"
#include "Convergence.h"

#include <cmath>
#include <exception>
#include <iostream>
#include <stack>
#include <tuple>

namespace UA_CoMP {
namespace Num {

/** Used to disambiguate rules in AdaptiveQuadrature. */
template <typename T>
class AQRule1 : public T
{
};

/** Used to disambiguate rules in AdaptiveQuadrature. */
template <typename T>
class AQRule2 : public T
{
};

/**
 * Given a quadrature rule, a new rule is
 * generated that consists of applying
 * the original rule on both subintervals
 * obtained through bisection.
 */
template <typename Rule>
class Bisector : public Rule
{
public:
        /** Execute the rule on the bisected cell. */
        template <typename Ftor>
        static typename Ftor::result_type sum(typename Ftor::argument_type l, typename Ftor::argument_type d,
                                              Ftor const& f)
        {
                using Arg = typename UA_CoMP::Num::StripConstRef<typename Ftor::argument_type>::type;

                Arg const h = static_cast<Arg>(0.5) * d;
                Arg const m = l + h;
                return Rule::sum(l, h, f) + Rule::sum(m, h, f);
        }
};

/**
 * \class AdaptiveQuadrature
 * The AdaptiveQuadrature is a host class with
 * policy classes QuadRule1, QuadRule2, ErrorPolicy
 * and ConvergencePolicy.
 * All of their interfaces are exposed through public
 * inheritance.
 * The host class also has a template
 * member function with the integrand as template
 * parameter. It evaluates the integral by dividing
 * the integration domain into cells and applying
 * two quadrature rules (QuadRule1 and QuadRule2)
 * on each cell. If both sums agree according to the
 * approximation expressed in ConvergencePolicy, they
 * are accepted as contribution to the integral. If
 * not the cell is bisected and the same procedure
 * is applied to the smaller cells. Thus the cellsize
 * adapts locally to the rate of change of the integrand.
 * Re CellCount:
 * The cellCount is monitored and the
 * ''cellCount <= cellCountLimit'' is an invariant. If
 * the algorithm threatens to break it then, depending
 * on the policy an exception is thrown, or the program
 * exits or the quadrature proceeds with the current
 * pattern of cells without further subdivision.
 * All of this can be achieved with reasonably generic
 * assertion like policy class that is used to test
 * the invariant and reacts if the condition is violated.
 * It has to implement a member
 *               bool check(bool b)
 * that returns the value of b, but may be throwing,
 * exiting etc as side effect.
 * An alternative would have been an OnCellCountViolation
 * class with a member function
 *               bool check(unsigned int cellCount)
 * However I do not really anticipate any real use for
 * the additional flexibility this provides. I mean, what
 * can you do but check cellCount <= cellCountLimit ?
 * Re ConvergencePolicy:
 * Now this is a different kettle of fish: there are
 * probably many ways you could evaluate a convergence
 * criterion. Absolute difference and Combo difference
 * seem good candidates, but there's also Relative
 * difference, Relative and Absolute difference at the
 * same time ... I want to preserve flexibility here,
 * so the policy class needs to have a constructor
 * storing all those numbers related to the criterion.
 * Hence the policy simply has to have a member function
 *              bool check(double sum1, double sum2)
 * instead of a static member.
 * It can have as many data members and getter/setters
 * as it wants but must also provide a default constructor.
 *
 * \class QuadRule1
 * \brief Template parameter provides first quadrature rule for
 *      AdaptiveQuadrature.
 * \class QuadRule2
 * \brief Template parameter provides second quadrature rule for
 *      AdaptiveQuadrature.
 * \class ConvergencePolicy
 * \brief Template parameter provides policy for managing
 * 		convergence criterion in AdaptiveQuadrature.
 * \class CellCountPolicy
 * \brief Template parameter provides policy for managing
 * 		cell count in AdaptiveQuadrature.
 */
template <typename QuadRule1, typename QuadRule2 = Bisector<QuadRule1>, typename ConvergencePolicy = ComboDifference,
          typename CellCountPolicy = OnViolationThrow>
class AdaptiveQuadrature : public AQRule1<QuadRule1>,
                           public AQRule2<QuadRule2>,
                           public ConvergencePolicy,
                           public CellCountPolicy
{
public:
        using first_rule = AQRule1<QuadRule1>;
        using second_rule = AQRule2<QuadRule2>;

        /**
        * Constructor initializes everything.
        */
        AdaptiveQuadrature(double convergenceTolerance, unsigned int initialCellCount, unsigned int cellCountLimit)
            : fConvergenceTolerance(convergenceTolerance), fInitialCellCount(initialCellCount),
              fCellCountLimit(cellCountLimit)
        {
        }

        // The implicit essential operators are fine for now.

        /**
         * Return a reference to the first sum rule subobject.
         * @return          Reference to first sum rule.
         * @exception       None.
         */
        AQRule1<QuadRule1>& rule1() { return *this; }

        /**
         * Return a reference to the second sum rule subobject.
         * @return          Reference to first sum rule.
         * @exception       None.
         */
        AQRule2<QuadRule2>& rule2() { return *this; }

        // Defined below.
        template <typename Integrand>
        std::tuple<bool, typename Integrand::result_type, typename Integrand::result_type, unsigned int> evaluate(
            typename Integrand::argument_type l, typename Integrand::argument_type r, Integrand ftor) const;

        // Defined below
        template <typename Integrand>
        typename Integrand::result_type operator()(typename Integrand::argument_type l,
                                                   typename Integrand::argument_type r, Integrand ftor) const;

        /** Return the convergence tolerance. */
        double getConvergenceTolerance() const { return fConvergenceTolerance; }

        /** Return the initial cell count. */
        unsigned int getInitialCellCount() const { return fInitialCellCount; }

        /** Return the cell count limit. */
        unsigned int getCellCountLimit() const { return fCellCountLimit; }

        /** Set the convergence tolerance. */
        void setConvergenceTolerance(double x) { fConvergenceTolerance = x; }

        /** Set initial cell count. */
        void setInitialCellCount(unsigned int i) { fInitialCellCount = i; }

        /** Set cell count limit. */
        void setCellCountLimit(unsigned int i) { fCellCountLimit = i; }

private:
        double fConvergenceTolerance;
        unsigned int fInitialCellCount;
        unsigned int fCellCountLimit;
};

/**
 * Evaluates the quadrature for a functor based on comparing two sum rules.
 * @return                      True iff both approximating sums satisfy the
 * convergence criterion.
 * @param       l               Left boundary of integration interval.
 * @param       r               Right boundary of integration interval.
 * @param       ftor            Integrand.
 * @exception                   Depends on policies used.
 */
template <typename QuadRule1, typename QuadRule2, typename ConvergencePolicy, typename CellCountPolicy>
template <typename Integrand>
std::tuple<bool, typename Integrand::result_type, typename Integrand::result_type, unsigned int>
AdaptiveQuadrature<QuadRule1, QuadRule2, ConvergencePolicy, CellCountPolicy>::evaluate(
    typename Integrand::argument_type l, typename Integrand::argument_type r, Integrand ftor) const
{
        using std::stack;
        using std::pair;
        using std::make_pair;

        using Arg = typename StripConstRef<typename Integrand::argument_type>::type;
        using Res = typename StripConstRef<typename Integrand::result_type>::type;

        // Stack of integration cells with each cell (left endpoint, size)
        stack<pair<Arg, Arg>> divStack;
        Res cumulateSum1;
        Res cumulateSum2;
        unsigned int cellCounter;
        bool NoMoreCells = false;

        // Initialize with the required number of cells on the stack,
        // set the cumulative sums (of rule1 and rule2) to zero and
        // initialize the cell count.
        {
                Arg const d = (r - l) / static_cast<Arg>(fInitialCellCount);
                for (Arg b = l; b < r - 0.5 * d; b += d) {
                        divStack.push(make_pair(b, d));
                }
                cumulateSum1 = 0.0;
                cumulateSum2 = 0.0;
                cellCounter = fInitialCellCount;
        }

        // Work that stack until it is empty.
        while (!divStack.empty()) {

                // Look at the top cell and determine sums for it.
                Arg const b = divStack.top().first;
                Arg const d = divStack.top().second;
                Res const sum1 = first_rule::sum(b, d, ftor);
                Res const sum2 = second_rule::sum(b, d, ftor);
                // If the use of the nested types does not work, then:
                // Res const sum1 = Rule1<QuadRule1>::sum(b, d, ftor);
                // Res const sum2 = Rule2<QuadRule2>::sum(b, d, ftor);

                // If the sums for both rules agree, or if we are not allowed to
                // create new cells, we are done with this cell. Add its contribution
                // to the cumulatve sums. If allowed (cell count violation does not
                // throw exception) we continue summing on the existing cells to obtain
                // at least a rough estimate of the integral.
                if ((ConvergencePolicy::evaluate(sum1, sum2) < fConvergenceTolerance) || NoMoreCells) {
                        cumulateSum1 += sum1;
                        cumulateSum2 += sum2;
                        divStack.pop();
                } else {
                        // Executing this block increases the cellCount; check that against the
                        // policy.
                        // Not executing leaves the current cell on stack to be processed, as
                        // should be.
                        NoMoreCells = !CellCountPolicy::check(cellCounter + 1 <= fCellCountLimit);
                        if (!NoMoreCells) {
                                divStack.pop();
                                Arg const dN = 0.5 * d;
                                divStack.push(make_pair(b + dN, dN));
                                divStack.push(make_pair(b, dN));
                                ++cellCounter;
                        }
                }
        }

        bool const status = (ConvergencePolicy::evaluate(cumulateSum1, cumulateSum2) < fConvergenceTolerance);
        return std::make_tuple(status, cumulateSum1, cumulateSum2, cellCounter);
}

/**
 * Simplified version of the evaluate member function, returns only second sum
 * value.
 * @see evaluate
 * @return                      Value for quadrature.
 * @param       l               Left boundary of integration interval.
 * @param       r               Right boundary of integration interval.
 * @param       ftor            Integrand.
 */
template <typename QuadRule1, typename QuadRule2, typename ConvergencePolicy, typename ErrorPolicy>
template <typename Integrand>
inline typename Integrand::result_type AdaptiveQuadrature<QuadRule1, QuadRule2, ConvergencePolicy, ErrorPolicy>::
operator()(typename Integrand::argument_type l, typename Integrand::argument_type r, Integrand ftor) const
{
        return std::get<2>(evaluate(l, r, ftor));
}

} // end-of-namespace
} // end-of-namespace


/**
 * @file
 * Demo for the AdaptiveQuadrature template.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */

#include "quad.h"
#include <iomanip>

using std::boolalpha;
using std::setprecision;
using std::setw;
using std::scientific;
using std::cout;
using std::endl;
using std::string;
using std::tuple;
using std::get;
using namespace UA_CoMP::Num;

namespace {
/**
 * Evaluate integral through quadrature and
 * print out comparison with exact result.
 */
template <typename Quad, typename Integrand>
void verifyQuad(double b, double e, Quad quad, Integrand ftor)
{
        try {
                tuple<bool, typename Integrand::result_type, typename Integrand::result_type, unsigned int> const
                    retValue = quad.evaluate(b, e, ftor);
                bool const stat = get<0>(retValue);
                double const sum1 = get<1>(retValue);
                double const sum2 = get<2>(retValue);
                unsigned int const cellCount = get<3>(retValue);
                double const check = ftor.getIntegral()(b, e);

                cout << boolalpha << scientific << setprecision(12);
                cout << "    AdaptiveQuadrature status: " << stat << endl
                     << "    sum1:  " << setw(20) << sum1 << endl
                     << "    sum2:  " << setw(20) << sum2 << "    diff:  " << setw(20) << fabs(sum1 - sum2) << endl
                     << "    cellCount:  " << cellCount << endl
                     << "    exact value: " << setw(20) << check << "    diff: " << setw(20) << fabs(sum2 - check)
                     << endl;
        } catch (std::exception& e) {
                cout << "std::exception: " << e.what() << endl;
        } catch (...) {
                cout << "Unknown exception in the verifyQuad procedure." << endl;
        }
}
} // end-of-anonymous-namespace

/**
 * Demonstrate the use of the AdaptiveQuadrature algorithm
 * with a variety of functors.
 */
int main()
{
        cout << "Using AdaptiveQuadrature: " << endl << endl;
        string const separator = "\n\n------------------------------------------------------\n";
        OscillatoryFunctor const ftor1(0.0, 10.0);
        OscillatoryFunctor const ftor2(-1.0, 20.0);

        {
                cout << separator << "Simpson vs Simpson-Bisector:" << endl;
                AdaptiveQuadrature<SimpsonRule> quad(1.0e-6, 50, 1000);
                verifyQuad(-1.0, 15.0, quad, ftor1);
        }
        {
                cout << separator << "GaussLegendre8 vs GaussLegendre8-Bisector:" << endl;
                AdaptiveQuadrature<GaussLegendre8Rule> quad(1.0e-2, 1, 1500);
                verifyQuad(-10.0, 35.0, quad, ftor1);
                cout << endl << "    reset convergenceTolerance and initialCellCount:" << endl;
                quad.setConvergenceTolerance(1.0e-12);
                quad.setInitialCellCount(10);
                verifyQuad(-10.0, 35.0, quad, ftor1);
        }
        {
                cout << separator << "GaussLegendre 16 vs 32:" << endl;
                AdaptiveQuadrature<GaussLegendre16Rule, GaussLegendre32Rule> quad(1.0e-10, 1, 1000);
                verifyQuad(0.0, 50.0, quad, ftor2);
        }
        {
                cout << separator << "GaussLegendre 16 vs 32 with initial cell count 20:" << endl;
                AdaptiveQuadrature<GaussLegendre16Rule, GaussLegendre32Rule> quad(1.0e-9, 1, 1000);
                quad.setInitialCellCount(20);
                verifyQuad(0.0, 50.0, quad, ftor2);
        }
        {
                cout << separator << "Simpson vs GaussLegendre2 and AbsoluteDifference:" << endl;
                AdaptiveQuadrature<SimpsonRule, GaussLegendre2Rule, AbsoluteDifference, OnViolationReturn> quad(1.0e-5,
                                                                                                                2, 100);
                verifyQuad(0.0, 5.0, quad, ftor2);
        }
        {
                cout << separator << "AGL_Quadrature and AbsoluteDifference:" << endl;
                AGL_Quadrature<8, 16, AbsoluteDifference> quad(1.0e-5, 2, 100);
                verifyQuad(0.0, 5.0, quad, ftor2);
        }

        return 0;
}

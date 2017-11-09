/**
 * @file
 * Demo for the Integral template.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */

#include "abs_diff.h"
#include "quad.h"

using std::cout;
using std::endl;
using std::bind1st;
using std::function;
using UA_CoMP::Num::OscillatoryFunctor;
using UA_CoMP::Num::AGL_Quadrature;
using UA_CoMP::Num::abs_diff;

/** Demo use of the Integral wrapper. */
int main()
{
        cout << "Verify Integral: " << endl;
        {
                cout << endl << "ComboApproximation and GaussLegendre 16 vs 32:" << endl;
                OscillatoryFunctor const ftor(-1.0, 20.0);
                AGL_Quadrature<16, 32> quad(1.0e-7, 1, 1000);
                function<double(double)> f1 = bind1st(ftor.getIntegral(), 0.0);
                function<double(double, double)> ff = make_integral(quad, ftor);
                function<double(double)> f2 = bind1st(ff, 0.0);
                double const d = abs_diff(0.0, 3.0, 0.1, f1, f2);
                cout << "abs diff for integral function is: " << d << endl;
        }
        return 0;
}

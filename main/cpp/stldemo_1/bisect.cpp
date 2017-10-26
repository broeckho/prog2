/*
 *  This file is part of the gobelijn software.
 *  Gobelijn is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or any later
 *  version. Gobelijn is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for details. You should have received
 *  a copy of the GNU General Public License along with the software. If not,
 *  see <http://www.gnu.org/licenses/>.
 *
 *  Copyright 2012, Jan Broeckhove, CoMP/UA.
 */
/**
 * @file
 * Demo for bisection root finder.
 */
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

namespace {

/// Function used to demo bisect
double f(double x) { return 5.0 * x - 3.0; }

/// Bisection root finder fashioned after Numerical Recipes.
double bisect(double func(double), double x1, double x2, double xacc)
{
        int const JMAX = 40;
        double dx, f, fmid, xmid, rtb;

        f = func(x1);
        fmid = func(x2);
        if (f * fmid >= 0.0) {
                cerr << "root must be bracketed" << endl;
                exit(EXIT_FAILURE);
        }
        if (f < 0.0) {
                rtb = x1;
                dx = x2 - x1;
        } else {
                rtb = x2;
                dx = x1 - x2;
        }

        for (int j = 0; j < JMAX; j++) {
                dx *= 0.5;
                xmid = rtb + dx;
                fmid = func(xmid);
                if (fmid <= 0.0) {
                        rtb = xmid;
                }
                if ((fabs(dx) < xacc) || (fmid == 0.0)) {
                        return rtb;
                }
        }
        cerr << "Too many bisections" << endl;
        exit(EXIT_FAILURE);
        return 0.0;
}

} // unnamed namespace

int main()
{
        cout << bisect(f, -2.0, 2.0, 0.00001) << endl;
        return 0;
}

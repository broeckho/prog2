#include "../../demo-operator_overloading/call-operator/plotter.h"
#include "../../demo-operator_overloading/call-operator/polynomial.h"
#include <iostream>

int main()
{
        std::vector<double> input{0, 0, -0.6, -3, 1};
        Polynomial<double> poly(input);

        Plotter<double> plot;
        std::cout << plot.plot(poly, -0.8, 0.8) << std::endl;
        std::cout << plot.plot(poly, -5.9, 6.4) << std::endl;
        return 0;
}

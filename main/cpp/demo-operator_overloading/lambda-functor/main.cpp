#include <functional>
#include <iostream>
using std::cout;
using std::endl;

#ifdef USE_FUNCTOR
#include "../../demo-operator_overloading/lambda-functor/functor-lambda.cpp"
#else
#include "../../demo-operator_overloading/lambda-functor/lambda-functor.cpp"
#endif

int main()
{
	int counter = 40;
	auto adder = makeCountingAdder(counter);
	cout << adder(2) << endl;
	cout << adder(4) << endl;
	cout << adder(8) << endl;
	cout << "Current counter count: " << counter << endl;
}

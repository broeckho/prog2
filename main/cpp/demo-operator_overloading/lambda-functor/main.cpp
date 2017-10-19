#include <functional>
#include <iostream>
using std::cout;
using std::endl;

#ifdef USE_FUNCTOR
class Lambda1
{
public:
	Lambda1(int& counter) : counter(counter) {}
	int operator()(int x)
	{
		int val = counter + x;
		counter++;
		return val;
	}

private:
	int& counter;
};

Lambda1 makeCountingAdder(int& counter) { return Lambda1(counter); }
#else
std::function<int(int)> makeCountingAdder(int& counter)
{
	return [&counter](int x) -> int {
		int val = counter + x;
		counter++;
		return val;
	};
}

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

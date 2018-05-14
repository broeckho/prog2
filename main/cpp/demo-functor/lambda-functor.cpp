#include <functional>
#include <iostream>
using std::cout;
using std::endl;

std::function<int(int)> makeCountingAdder(int& counter)
{
        return [&counter](int x) -> int {
                int val = counter + x;
                counter++;
                return val;
        };
}

int main()
{
        int counter = 40;
        auto adder = makeCountingAdder(counter);
        cout << adder(2) << endl;
        cout << adder(4) << endl;
        cout << adder(8) << endl;
        cout << "Current counter count: " << counter << endl;
}

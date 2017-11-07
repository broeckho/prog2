/**
 * @brief demonstrates the easy syntax of lambdas instead of functors.
 * @author Tobia De Koninck (Groepje P = NP)
 */
#include <functional>
#include <iostream>
#include <set>

int main()
{
        int offset{0}; // voorbeeld van een capture
        std::set<int*, std::function<bool(int*, int*)>> ints{
            [offset](const int* lhs, const int* rhs) -> bool { return *lhs < *rhs + offset; }};

        ints.insert(new int(13));
        ints.insert(new int(11));
        ints.insert(new int(10));
        ints.insert(new int(12));

        for (int* aInt : ints) {
                // the ints are sorted by there value and no the address in memory.
                std::cout << aInt << " = " << *aInt << std::endl;
        }

        for (int* aInt : ints) {
                delete aInt;
        }
        ints.clear();
}

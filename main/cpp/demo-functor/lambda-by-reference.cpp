/**
 * @brief Demonstration of a lambda, with a capture taken by reference.
 * @see lambda-by-value.cpp
 * @author Tobia De Koninck (Groepje P = NP)
 */

#include <iostream>

int main()
{
        std::string suffix = "\n";

        auto lambda1 = [&suffix](const std::string& string) -> std::string { return string + suffix; };

        std::string ex = "Hello World";
        std::cout << lambda1(ex);
        suffix = "ab\n";
        std::cout << lambda1(ex); // suffix has changed in in the lambda
        return 0;
}

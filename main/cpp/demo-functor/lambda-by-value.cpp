/**
 * @brief Demonstration of a lambda, with a capture taken by value.
 * @see lambda-by-reference.cpp
 * @author Tobia De Koninck (Groepje P = NP)
 */

#include <iostream>

int main()
{
        std::string suffix = "\n";

        auto lambda1 = [suffix](const std::string& string) -> std::string { return string + suffix; };

        std::string ex = "Hello World";
        std::cout << lambda1(ex);
        suffix = "ab";
        std::cout << lambda1(ex); // suffix is the same in lambda
        return 0;
}

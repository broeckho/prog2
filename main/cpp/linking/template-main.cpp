#include <iostream>

template <typename T>
T muladd(T a, T b, T c);

int main() { std::cout << muladd<int>(1, 2, 3) << std::endl; }

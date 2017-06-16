#include <iostream>

class MulAddHelpers
{
public:
	static int muladd(int a, int b, int c) { return a * b + c; }
};

inline int muladd(int a, int b, int c) { return a * b + c; }

int main()
{
	std::cout << MulAddHelpers::muladd(1, 2, 3) << std::endl;
	std::cout << muladd(1, 2, 3) << std::endl;
}

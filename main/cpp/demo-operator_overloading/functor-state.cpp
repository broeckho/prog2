#include <algorithm>
#include <iostream>
#include <vector>

class Sum
{
public:
	Sum() : m_total(0) {}
	void operator()(int value) { m_total += value; }

	friend std::ostream& operator<<(std::ostream& os, Sum& s)
	{
		os << s.m_total;
		return os;
	}

private:
	int m_total;
};

int main()
{
	std::vector<int> vect({1, 2, 3, 4, 5, 6});
	Sum sum = for_each(vect.begin(), vect.end(), Sum());
	std::cout << sum << std::endl;
	return 0;
}

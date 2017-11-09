/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include <iostream>
#include <stack>
#include <vector>

template <typename T>
class ElementT;

template <typename T>
class ElementT<std::vector<T>>
{
public:
        typedef T Type;
};

template <typename T>
class ElementT<std::stack<T>>
{
public:
        typedef T Type;
};

template <typename T>
void print_element_type(T const&)
{
        std::cout << "Container of "
                  << typeid(typename ElementT<T>::Type).name() << " elements.\n";
}

int main()
{
        std::stack<bool> s;
        std::vector<int> v;
        print_element_type(s);
        print_element_type(v);
        return 0;
}

/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include <iostream>
#include <list>
#include <stack>
#include <typeinfo>
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
class ElementT<std::list<T>>
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
        std::cout << "Container of " << typeid(typename ElementT<T>::Type).name() << " elements.\n";
}

int main()
{
        std::stack<bool> s;
        print_element_type(s);
        return 0;
}

#ifndef INC_BASICS_STACK1_HPP
#define INC_BASICS_STACK1_HPP
/**
 * @file.
 * Stack class template.
 * @author J. Broeckhove, CoMP/UA - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
#include <stdexcept>
#include <vector>

template <typename T>
class Stack
{
private:
        std::vector<T> elems;

public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty() const { return elems.empty(); }
};

template <typename T>
void Stack<T>::push(T const& elem)
{
        elems.push_back(elem);
}

template <typename T>
void Stack<T>::pop()
{
        if (elems.empty()) {
                throw std::out_of_range("pop(): empty stack");
        }
        elems.pop_back();
}

template <typename T>
T Stack<T>::top() const
{
        if (elems.empty()) {
                throw std::out_of_range("top(): empty stack");
        }
        return elems.back();
}
// END_SNIPPET{FullSource}

#endif // INC_BASICS_STACK1_HPP

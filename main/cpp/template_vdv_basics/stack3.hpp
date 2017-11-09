#ifndef INC_BASICS_STACK3_HPP
#define INC_BASICS_STACK3_HPP
/**
 * @file.
 * Stack class template.
 * @author J. Broeckhove, CoMP/UA - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
#include <stdexcept>
#include <vector>

template <typename T, typename CONT = std::vector<T>>
class Stack
{
private:
        CONT elems;

public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty() const { return elems.empty(); }
};

template <typename T, typename CONT>
void Stack<T, CONT>::push(T const& elem)
{
        elems.push_back(elem);
}

template <typename T, typename CONT>
void Stack<T, CONT>::pop()
{
        if (elems.empty()) {
                throw std::out_of_range("pop(): empty stack");
        }
        elems.pop_back();
}

template <typename T, typename CONT>
T Stack<T, CONT>::top() const
{
        if (elems.empty()) {
                throw std::out_of_range("top(): empty stack");
        }
        return elems.back();
}
// END_SNIPPET{FullSource}

#endif // INC_BASICS_STACK3_HPP

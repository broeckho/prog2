#pragma once
/**
 * @file.
 * Demonstrate use of member function templates.
 * @author J. Broeckhove - see copyright.txt
 */

#include "stack7decl.hpp"
#include <deque>
#include <stdexcept>

template <typename T, typename ALLOC, template <typename, typename> class CONT>
void Stack<T, ALLOC, CONT>::push(T const& elem)
{
        elems.push_back(elem);
}

template <typename T, typename ALLOC, template <typename, typename> class CONT>
void Stack<T, ALLOC, CONT>::pop()
{
        if (elems.empty()) {
                throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elems.pop_back();
}

template <typename T, typename ALLOC, template <typename, typename> class CONT>
T Stack<T, ALLOC, CONT>::top() const
{
        if (elems.empty()) {
                throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elems.back();
}


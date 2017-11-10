#pragma once
/**
 * @file.
 * Template function returns maximum.
 * @author J. Broeckhove - see copyright.txt
 */

#include "stack5assign.hpp"
#include "stack5decl.hpp"
#include <deque>
#include <stdexcept>

template <typename T>
void Stack<T>::push(T const& elem)
{
        elems.push_back(elem);
}

template <typename T>
void Stack<T>::pop()
{
        if (elems.empty()) {
                throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elems.pop_back();
}

template <typename T>
T Stack<T>::top() const
{
        if (elems.empty()) {
                throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elems.back();
}


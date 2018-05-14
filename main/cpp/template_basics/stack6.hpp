#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include <deque>
#include <stdexcept>

/// Stack template.
/// \tparam T           Template param for element.
/// \tparam CONT        Template param for container for elements.
template <typename T, typename CONT = std::deque<T>>
class Stack
{
public:
        /// Assignment of one stack to another.
        /// \tparam T2  Template param for element type of rhs stack.
        /// \return     reference to the stack.
        template <typename T2, typename CONT2>
        Stack<T, CONT>& operator=(Stack<T2, CONT2> const&);

        /// Check whether stack is empty.
        /// \return     True iff empty.
        bool empty() const { return elems.empty(); }

        /// Pop element off the stack.
        void pop();

        /// Pushes element onto stack.
        /// \param e    Element to be pushed onto stack
        void push(const T& e);

        /// Return top element of the stack (but not pop-ing it).
        /// \return     Top element of the stack
        T top() const;

private:
        CONT elems; ///< Container for the stack elements.
};

// -------------------- Implementations ----------------------------------------

template <typename T, typename CONT>
template <typename T2, typename CONT2>
Stack<T, CONT>& Stack<T, CONT>::operator=(const Stack<T2, CONT2>& op2)
{
        if ((void*)this == (void*)&op2) {
                return *this;
        }

        Stack<T2, CONT2> tmp(op2);
        elems.clear();
        while (!tmp.empty()) {
                elems.push_front(tmp.top());
                tmp.pop();
        }
        return *this;
}

template <typename T, typename CONT>
void Stack<T, CONT>::push(T const& elem)
{
        elems.push_back(elem);
}

template <typename T, typename CONT>
void Stack<T, CONT>::pop()
{
        if (elems.empty()) {
                throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elems.pop_back();
}

template <typename T, typename CONT>
T Stack<T, CONT>::top() const
{
        if (elems.empty()) {
                throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elems.back();
}

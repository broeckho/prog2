#pragma once
/**
 * @file.
 * Template function returns maximum.
 * @author J. Broeckhove - see copyright.txt
 */

#include <deque>
#include <stdexcept>

/// Stack class using dequeue as element container.
/// \tparam T           template param for element type.
template <typename T>
class Stack
{
public:
        /// Assignment of one stack to another.
        /// \tparam T2  Template param for element type of rhs stack.
        /// \return     reference to the stack.
        template <typename T2>
        Stack<T>& operator=(const Stack<T2>& rhs);

        /// Check whether stack is empty.
        /// \return     True iff empty.
        bool empty() const { return elems.empty(); }

        /// Pop element off the stack.
        void pop();

        /// Pushes element onto stack.
        /// \param e    Element to be pushed onto stack.
        void push(const T& e);

        /// Return top element of the stack (but not pop-ing it).
        /// \return     Top element of the stack.
        T top() const;

private:
        std::deque<T> elems;    ///< Container for the stack elements.

};

// -------------------- Implementations ----------------------------------------

template <typename T>
template <typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& op2)
{
        if ((void*)this == (void*)&op2) {
                return *this;
        }

        Stack<T2> tmp(op2);
        elems.clear();
        while (!tmp.empty()) {
                elems.push_front(tmp.top());
                tmp.pop();
        }
        return *this;
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
void Stack<T>::push(T const& elem)
{
        elems.push_back(elem);
}

template <typename T>
T Stack<T>::top() const
{
        if (elems.empty()) {
                throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elems.back();
}

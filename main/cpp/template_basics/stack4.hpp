#pragma once
/**
 * @file.
 * Template function returns maximum.
 * @author J. Broeckhove - see copyright.txt
 */

#include <stdexcept>

/// Stack class using vector as element container.
/// \tparam T           Template param for element type.
/// \tparam MAXSIZE     Maximum capacity of the container.
template <typename T, int MAXSIZE>
class Stack
{
public:
        /// Check whether stack is empty.
        /// \return     True iff empty.
        bool empty() const { return numElems == 0; }

        /// Check wheter stack is full.
        /// \return     True iff full.
        bool full() const { return numElems == MAXSIZE; }

        /// Pop element off the stack.
        void pop();

        /// Pushes element onto stack.
        /// \param e    Element to be pushed onto stack.
        void push(const T& e);

        /// Return top element of the stack (but not pop-ing it).
        /// \return     Top element of the stack.
        T top() const;

private:
        T elems[MAXSIZE];               ///< Array to caontain stack elements.
        unsigned int numElems {0};      ///< Current number of elements.
};

// -------------------- Implementations ----------------------------------------

template <typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::pop()
{
        if (numElems <= 0) {
                throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        --numElems;
}

template <typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(T const& elem)
{
        if (numElems == MAXSIZE) {
                throw std::out_of_range("Stack<>::push(): stack is full");
        }
        elems[numElems] = elem;
        ++numElems;
}

template <typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::top() const
{
        if (numElems <= 0) {
                throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elems[numElems - 1];
}


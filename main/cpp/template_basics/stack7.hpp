#pragma once
/**
 * @file.
 * Demonstrate use of member function templates.
 * @author J. Broeckhove - see copyright.txt
 */

#include <deque>
#include <stdexcept>

/// Stack template.
/// \tparam T           Template param for element.
/// \tparam ALLOC       Allocator for the stack container.
/// \tparam CONT        Template param for container for elements.
template <typename T, typename ALLOC = std::allocator<T>, template <typename, typename> class CONT = std::deque>
class Stack
{
public:
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
        CONT<T, ALLOC> elems;           ///< Container for the stack elements.
};

// -------------------- Implementations ----------------------------------------

template <typename T, typename ALLOC, template <typename, typename> class CONT>
void Stack<T, ALLOC, CONT>::pop()
{
        if (elems.empty()) {
                throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elems.pop_back();
}

template <typename T, typename ALLOC, template <typename, typename> class CONT>
void Stack<T, ALLOC, CONT>::push(T const& elem)
{
        elems.push_back(elem);
}

template <typename T, typename ALLOC, template <typename, typename> class CONT>
T Stack<T, ALLOC, CONT>::top() const
{
        if (elems.empty()) {
                throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elems.back();
}


#pragma once
/**
 * @file.
 * Stack class template.
 * @author J. Broeckhove, CoMP/UA - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
#include <stdexcept>
#include <vector>


/// Stack class using vector as element container.
/// \tparam T           Template param for element type.
/// \tparam CONT        Container type fo stack elements.
template <typename T, typename CONT = std::vector<T>>
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
        CONT elems;     ///< Container for the stack elements.
};

// -------------------- Implementations ----------------------------------------

template <typename T, typename CONT>
void Stack<T, CONT>::pop()
{
        if (elems.empty()) {
                throw std::out_of_range("pop(): empty stack");
        }
        elems.pop_back();
}

template <typename T, typename CONT>
void Stack<T, CONT>::push(const T& elem)
{
        elems.push_back(elem);
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


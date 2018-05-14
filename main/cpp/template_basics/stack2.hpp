#pragma once
/**
 * @file.
 * Full specialisation of stack class template.
 * @author J. Broeckhove, CoMP/UA - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
#include "stack1.hpp"
#include <deque>
#include <stdexcept>
#include <string>

/// Specialisation for string as element type.
template <>
class Stack<std::string>
{
public:
        /// Check whether stack is empty.
        /// \return     True iff empty.
        bool empty() const { return elems.empty(); }

        /// Pop element off the stack.
        void pop();

        /// Pushes element onto stack.
        /// \param s    String pushed on stack.
        void push(const std::string& s);

        /// Return top element of the stack (but not pop-ing it).
        /// \return     Top element of the stack.
        std::string top() const;

private:
        std::deque<std::string> elems; ///< Container for the stack elements.
};

// -------------------- Implementations ----------------------------------------

void Stack<std::string>::pop()
{
        if (elems.empty()) {
                throw std::out_of_range("pop(): empty stack");
        }
        elems.pop_back();
}

void Stack<std::string>::push(std::string const& elem) { elems.push_back(elem); }

std::string Stack<std::string>::top() const
{
        if (elems.empty()) {
                throw std::out_of_range("top(): empty stack");
        }
        return elems.back();
}
// END_SNIPPET{FullSource}

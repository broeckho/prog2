#pragma once
/**
 * @file.
 * Demonstrate use of member function templates.
 * @author J. Broeckhove - see copyright.txt
 */

#include <deque>

template <typename T, typename CONT = std::deque<T>>
class Stack
{
private:
        CONT elems;

public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty() const { return elems.empty(); }

        template <typename T2, typename CONT2>
        Stack<T, CONT>& operator=(Stack<T2, CONT2> const&);
};


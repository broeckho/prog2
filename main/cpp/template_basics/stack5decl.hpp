#pragma once
/**
 * @file.
 * Template function returns maximum.
 * @author J. Broeckhove - see copyright.txt
 */

#include <deque>

template <typename T>
class Stack
{
public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty() const { return elems.empty(); }

        template <typename T2>
        Stack<T>& operator=(Stack<T2> const&);
private:
        std::deque<T> elems;

};

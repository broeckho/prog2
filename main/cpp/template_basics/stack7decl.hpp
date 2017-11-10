#pragma once
/**
 * @file.
 * Demonstrate use of member function templates.
 * @author J. Broeckhove - see copyright.txt
 */

#include <deque>

template <typename T, typename ALLOC = std::allocator<T>, template <typename, typename> class CONT = std::deque>
class Stack
{
public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty() const { return elems.empty(); }
private:
        CONT<T, ALLOC> elems;

};


/**
 * @file.
 * Demonstrate use of member function templates.
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_BASICS_STACK7DECL_HPP
#define INC_BASICS_STACK7DECL_HPP

#include <deque>

template <typename T, typename ALLOC = std::allocator<T>, template <typename, typename> class CONT = std::deque>
class Stack
{
private:
	CONT<T, ALLOC> elems;

public:
	void push(T const&);
	void pop();
	T top() const;
	bool empty() const { return elems.empty(); }
};

#endif // INC_BASICS_STACK7DECL_HPP

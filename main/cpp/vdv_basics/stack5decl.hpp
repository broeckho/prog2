/**
 * @file.
 * Template function returns maximum.
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_BASICS_STACK5DECL_HPP
#define INC_BASICS_STACK5DECL_HPP

#include <deque>

template <typename T>
class Stack
{
private:
	std::deque<T> elems;

public:
	void push(T const&);
	void pop();
	T top() const;
	bool empty() const { return elems.empty(); }

	template <typename T2>
	Stack<T>& operator=(Stack<T2> const&);
};

#endif // INC_BASICS_STACK5DECL_HPP

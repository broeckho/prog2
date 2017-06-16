/**
 * @file.
 * Demonstrate use of member function templates.
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_BASICS_STACK6DECL_HPP
#define INC_BASICS_STACK6DECL_HPP

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

#endif // INC_BASICS_STACK6DECL_HPP

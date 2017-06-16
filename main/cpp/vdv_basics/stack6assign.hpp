/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_BASICS_STACK6ASSIGN_HPP
#define INC_BASICS_STACK6ASSIGN_HPP

#include "stack6decl.hpp"

template <typename T, typename CONT>
template <typename T2, typename CONT2>
Stack<T, CONT>& Stack<T, CONT>::operator=(Stack<T2, CONT2> const& op2)
{
	if ((void*)this == (void*)&op2) {
		return *this;
	}

	Stack<T2, CONT2> tmp(op2);
	elems.clear();
	while (!tmp.empty()) {
		elems.push_front(tmp.top());
		tmp.pop();
	}
	return *this;
}

#endif // INC_BASICS_STACK6ASSIGN_HPP

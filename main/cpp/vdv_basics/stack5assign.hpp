/**
 * @file.
 * Stack assignment operator.
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_BASICS_STACK5ASSIGN_HPP
#define INC_BASICS_STACK5ASSIGN_HPP

#include "stack5decl.hpp"

template <typename T>
template <typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& op2)
{
	if ((void*)this == (void*)&op2) {
		return *this;
	}

	Stack<T2> tmp(op2);
	elems.clear();
	while (!tmp.empty()) {
		elems.push_front(tmp.top());
		tmp.pop();
	}
	return *this;
}

#endif // INC_BASICS_STACK5ASSIGN_HPP

#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>

template <typename T>

class Polynomial
{
public:
	Polynomial(const std::vector<T>& vect) : vect(vect) {}
	T operator()(const T& x);
	Polynomial<T> operator+(const Polynomial<T>& x) const;
	Polynomial<T> operator*(const Polynomial<T>& x) const;
	Polynomial<T> operator-(const Polynomial<T>& x) const;
	Polynomial<T> derive() const;

	T horner(const T& x) const;

protected:
	Polynomial() {}
	std::vector<T> vect;
};

#endif // POLYNOMIAL_H

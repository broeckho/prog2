#include "polynomial.h"

template <typename T>
T Polynomial<T>::operator()(const T& x)
{
        T result = 0;
        T multiplicant = 1;
        for (T& a : vect) {
                result += a * multiplicant;
                multiplicant *= x;
        }
        return result;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& x) const
{
        Polynomial<T> result;
        for (unsigned int i = 0; i < std::max(x.vect.size(), vect.size()); i++) {
                result.vect.push_back((vect.size() > i ? vect[i] : 0) + (x.vect.size() > i ? x.vect[i] : 0));
        }
        return result;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T>& x) const
{
        Polynomial<T> result;
        for (unsigned int i = 0; i < std::max(x.vect.size(), vect.size()); i++) {
                result.vect.push_back((vect.size() > i ? vect[i] : 0) * (x.vect.size() > i ? x.vect[i] : 0));
        }
        return result;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial<T>& x) const
{
        Polynomial<T> result;
        for (unsigned int i = 0; i < std::max(x.vect.size(), vect.size()); i++) {
                result.vect.push_back((vect.size() > i ? vect[i] : 0) - (x.vect.size() > i ? x.vect[i] : 0));
        }
        return result;
}

template <typename T>
Polynomial<T> Polynomial<T>::derive() const
{
        Polynomial<T> result;
        for (int i = 1; i < vect.size(); i++) {
                result.vect.push_back(vect[i] * i);
        }
        return result;
}

template <typename T>
T Polynomial<T>::horner(const T& x) const
{
        T result = vect[vect.size() - 1];
        for (auto i = vect.size() - 2; i >= 0; i--) {
                result = vect[i] + result * x;
        }
        return result;
}

template class Polynomial<double>;

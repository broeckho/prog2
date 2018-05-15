#pragma once
/**
 * @file.
 * Template function returns maximum.
 * @author J. Broeckhove - see copyright.txt
 */

template <typename T>
inline T const& max(T const& a, T const& b)
{
        return a < b ? b : a;
}

inline int const& max(int const& a, int const& b) { return a < b ? b : a; }

template <typename T>
inline T const& max(T const& a, T const& b, T const& c)
{
        return max(max(a, b), c);
}

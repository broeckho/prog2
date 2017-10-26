#ifndef INC_BASICS_MAX_HPP
#define INC_BASICS_MAX_HPP
/**
 * @file.
 * Template function returns maximum.
 * @author J. Broeckhove - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
template <typename T>
inline T const& max(T const& a, T const& b)
{
        return a < b ? b : a;
}
// END_SNIPPET{FullSource}

#endif // INC_BASICS_MAX_HPP

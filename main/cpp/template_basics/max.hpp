#pragma once
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


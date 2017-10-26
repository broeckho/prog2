/**
 * @file.
 * Template function usage with parameter deduction.
 * @author J. Broeckhove - see copyright.txt
 */

template <typename T>
inline T const& max(T const& a, T const& b)
{
        return a < b ? b : a;
}

template <typename T>
inline T const& max(T const& a, T const& b, T const& c)
{
        return max(max(a, b), c); // uses template version even for ints
}

inline int const& max(int const& a, int const& b) { return a < b ? b : a; }

int main()
{
        ::max(7, 42, 68); // OK but uses template int-max

        return 0;
}

/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_SUMPOLICY2_HPP
#define INC_TRAITS_SUMPOLICY2_HPP

template <typename T1, typename T2>
class SumPolicy
{
public:
        static void accumulate(T1& total, T2 const& value) { total += value; }
};

#endif // INC_TRAITS_SUMPOLICY2_HPP

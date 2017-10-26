/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_SUMPOLICY3_HPP
#define INC_TRAITS_SUMPOLICY3_HPP

template <bool use_compound_op = true>
class SumPolicy
{
public:
        template <typename T1, typename T2>
        static void accumulate(T1& total, T2 const& value)
        {
                total += value;
        }
};

template <>
class SumPolicy<false>
{
public:
        template <typename T1, typename T2>
        static void accumulate(T1& total, T2 const& value)
        {
                total = total + value;
        }
};

#endif // INC_TRAITS_SUMPOLICY3_HPP

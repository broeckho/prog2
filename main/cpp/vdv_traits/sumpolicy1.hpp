/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_SUMPOLICY1_HPP
#define INC_TRAITS_SUMPOLICY1_HPP

class SumPolicy
{
public:
        template <typename T1, typename T2>
        static void accumulate(T1& total, T2 const& value)
        {
                total += value;
        }
};

#endif // INC_TRAITS_SUMPOLICY1_HPP

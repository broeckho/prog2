#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

class SumPolicy
{
public:
        template <typename T1, typename T2>
        static void accumulate(T1& total, const T2& value)
        {
                total += value;
        }
};

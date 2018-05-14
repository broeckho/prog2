#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

template <typename T1, typename T2>
class SumPolicy
{
public:
        static void accumulate(T1& total, const T2& value) { total += value; }
};

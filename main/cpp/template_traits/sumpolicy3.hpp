#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

template <bool use_compound_op = true>
class SumPolicy
{
public:
        template <typename T1, typename T2>
        static void accumulate(T1& total, const T2& value) { total += value; }
};

template <>
class SumPolicy<false>
{
public:
        template <typename T1, typename T2>
        static void accumulate(T1& total, const T2& value) { total = total + value; }
};


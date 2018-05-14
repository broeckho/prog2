#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

template <typename T>
class AccumulationTraits;

template <>
class AccumulationTraits<char>
{
public:
        using type = int;
        static const type value = 0;
};

template <>
class AccumulationTraits<short>
{
public:
        using type = int;
        static const type value = 0;
};

template <>
class AccumulationTraits<int>
{
public:
        using type = long;
        static constexpr type value = 0;
};

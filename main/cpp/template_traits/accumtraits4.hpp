#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

template <typename T>
struct AccumulationTraits;

template <>
struct AccumulationTraits<char>
{
        using type = int;
        static constexpr type zero() { return 0; }
};

template <>
struct AccumulationTraits<short>
{
        using type = int;
        static constexpr type zero() { return 0; }
};

template <>
struct AccumulationTraits<int>
{
        using type = long;
        static constexpr type zero() { return 0; }
};

template <>
struct AccumulationTraits<unsigned int>
{
        using type = unsigned long;
        static constexpr type zero() { return 0; }
};

template <>
struct AccumulationTraits<float>
{
        using type = double;
        static constexpr type zero() { return 0; }
};

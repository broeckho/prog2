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
};

template <>
class AccumulationTraits<short>
{
public:
        using type = int;
};

template <>
class AccumulationTraits<int>
{
public:
        using type = long;
};

template <>
class AccumulationTraits<unsigned int>
{
public:
        using type = unsigned long;
};

template <>
class AccumulationTraits<float>
{
public:
        using type = double;
};

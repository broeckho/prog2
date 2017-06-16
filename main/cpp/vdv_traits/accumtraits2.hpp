/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_ACCUMTRAITS2_HPP
#define INC_TRAITS_ACCUMTRAITS2_HPP

template <typename T>
class AccumulationTraits;

template <>
class AccumulationTraits<char>
{
public:
	typedef int AccT;
};

template <>
class AccumulationTraits<short>
{
public:
	typedef int AccT;
};

template <>
class AccumulationTraits<int>
{
public:
	typedef long AccT;
};

template <>
class AccumulationTraits<unsigned int>
{
public:
	typedef unsigned long AccT;
};

template <>
class AccumulationTraits<float>
{
public:
	typedef double AccT;
};

#endif // INC_TRAITS_ACCUMTRAITS2_HPP

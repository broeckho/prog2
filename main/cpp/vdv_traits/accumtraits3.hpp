/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_ACCUMTRAITS3_HPP
#define INC_TRAITS_ACCUMTRAITS3_HPP

template <typename T>
class AccumulationTraits;

template <>
class AccumulationTraits<char>
{
public:
	typedef int AccT;
	static AccT const zero = 0;
};

template <>
class AccumulationTraits<short>
{
public:
	typedef int AccT;
	static AccT const zero = 0;
};

template <>
class AccumulationTraits<int>
{
public:
	using AccT = long;
	static AccT constexpr zero = 0;
};

#endif // INC_TRAITS_ACCUMTRAITS3_HPP

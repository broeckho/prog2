/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_ACCUMTRAITS4_HPP
#define INC_TRAITS_ACCUMTRAITS4_HPP

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

#endif // INC_TRAITS_ACCUMTRAITS4_HPP

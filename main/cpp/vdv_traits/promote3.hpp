/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_PROMOTE3_HPP
#define INC_TRAITS_PROMOTE3_HPP

#define MK_PROMOTION(T1, T2, Tr)                                                                                       \
	template <>                                                                                                    \
	class Promotion<T1, T2>                                                                                        \
	{                                                                                                              \
	public:                                                                                                        \
		typedef Tr ResultT;                                                                                    \
	};                                                                                                             \
                                                                                                                       \
	template <>                                                                                                    \
	class Promotion<T2, T1>                                                                                        \
	{                                                                                                              \
	public:                                                                                                        \
		typedef Tr ResultT;                                                                                    \
	};

#endif // INC_TRAITS_PROMOTE3_HPP

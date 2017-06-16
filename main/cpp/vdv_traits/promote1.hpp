/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_PROMOTE1_HPP
#define INC_TRAITS_PROMOTE1_HPP

/**
 * Primary template for type promotion.
 */
template <typename T1, typename T2>
class Promotion
{
public:
	typedef typename IfThenElse<(sizeof(T1) > sizeof(T2)), T1,
				    typename IfThenElse<(sizeof(T1) < sizeof(T2)), T2, void>::ResultT>::ResultT ResultT;
};

#endif // INC_TRAITS_PROMOTE1_HPP

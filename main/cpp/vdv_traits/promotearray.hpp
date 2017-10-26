/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_PROMOTEARRAY_HPP
#define INC_TRAITS_PROMOTEARRAY_HPP

template <typename T1, typename T2>
class Promotion<Array<T1>, Array<T2>>
{
public:
        typedef Array<typename Promotion<T1, T2>::ResultT> ResultT;
};

template <typename T>
class Promotion<Array<T>, Array<T>>
{
public:
        typedef Array<typename Promotion<T, T>::ResultT> ResultT;
};

#endif // INC_TRAITS_PROMOTEARRAY_HPP

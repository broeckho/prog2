/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_PROMOTE2_HPP
#define INC_TRAITS_PROMOTE2_HPP

/**
 * Partial specialization for two identical types.
 */
template <typename T>
class Promotion<T, T>
{
public:
        typedef T ResultT;
};

#endif // INC_TRAITS_PROMOTE2_HPP

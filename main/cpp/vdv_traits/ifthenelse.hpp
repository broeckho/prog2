/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_IFTHENELSE_HPP
#define INC_TRAITS_IFTHENELSE_HPP

/**
 * Primary template: yield second or third
 * argument depending on first argument.
 */
template <bool C, typename Ta, typename Tb>
class IfThenElse;

/**
 * Partial specialization: true
 * yields the second argument
 */
template <typename Ta, typename Tb>
class IfThenElse<true, Ta, Tb>
{
public:
        typedef Ta ResultT;
};

/**
 * Partial specialization: false
 * yields the third argument
 */
template <typename Ta, typename Tb>
class IfThenElse<false, Ta, Tb>
{
public:
        typedef Tb ResultT;
};

#endif // INC_TRAITS_IFTHENELSE_HPP

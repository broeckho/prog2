/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_ISCLASST_HPP
#define INC_TRAITS_ISCLASST_HPP

template <typename T>
class IsClassT
{
private:
        typedef char One;
        typedef struct
        {
                char a[2];
        } Two;
        template <typename C>
        static One test(int C::*);
        template <typename C>
        static Two test(...);

public:
// Original code does compiles with gcc 3.4 but
// not with with gcc 4.0.2. Elimination of
// the  IsClass<T> qualifier does the trick
#if defined __GNUC__
#if (__GNUC__ <= 3)
        enum
        {
                Yes = (sizeof(IsClassT<T>::test<T>(0)) == 1)
        };
#else
        enum
        {
                Yes = (sizeof(test<T>(0)) == 1)
        };
#endif
#else
        enum
        {
                Yes = (sizeof(test<T>(0)) == 1)
        };
#endif
        enum
        {
                No = !Yes
        };
};

#endif // INC_TRAITS_ISCLASST_HPP

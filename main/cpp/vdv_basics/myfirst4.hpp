/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_BASICS_MYFIRST4_HPP
#define INC_BASICS_MYFIRST4_HPP

// use export if USE_EXPORT is defined
#if defined(USE_EXPORT)
#define EXPORT export
#else
#define EXPORT
#endif

EXPORT
template <typename T>
void print_typeof(T const&);

#if !defined(USE_EXPORT)
#include "myfirst.cpp"
#endif

#endif // INC_BASICS_MYFIRST4_HPP

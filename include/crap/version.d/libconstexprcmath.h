#ifndef CRAP_VERSION_LIBCONSTEXPRCMATH
#define CRAP_VERSION_LIBCONSTEXPRCMATH

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_constexpr_cmath
#define crap_lib_constexpr_cmath __cpp_lib_constexpr_cmath
#else
#define crap_lib_constexpr_cmath 0L
#endif

#endif


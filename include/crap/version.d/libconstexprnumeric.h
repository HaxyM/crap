#ifndef CRAP_VERSION_LIBCONSTEXPRNUMERIC
#define CRAP_VERSION_LIBCONSTEXPRNUMERIC

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_constexpr_numeric
#define crap_lib_constexpr_numeric __cpp_lib_constexpr_numeric
#else
#define crap_lib_constexpr_numeric 0L
#endif

#endif


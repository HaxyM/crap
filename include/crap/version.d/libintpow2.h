#ifndef CRAP_VERSION_LIBINTPOW2
#define CRAP_VERSION_LIBINTPOW2

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_int_pow2
#define crap_lib_int_pow2 __cpp_lib_int_pow2
#else
#define crap_lib_int_pow2 0L
#endif

#endif


#ifndef CRAP_VERSION_LIBBITOPS
#define CRAP_VERSION_LIBBITOPS

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_bitops
#define crap_lib_bitops __cpp_lib_bitops
#else
#define crap_lib_bitops 0L
#endif

#endif


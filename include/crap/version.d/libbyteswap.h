#ifndef CRAP_VERSION_LIBBYTESWAP
#define CRAP_VERSION_LIBBYTESWAP

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_byteswap
#define crap_lib_byteswap __cpp_lib_byteswap
#else
#define crap_lib_byteswap 0L
#endif

#endif


#ifndef CRAP_VERSION_CHAR8T
#define CRAP_VERSION_CHAR8T

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_char8_t
#define crap_char8_t __cpp_char8_t
#else
#define crap_char8_t 0L
#endif

#endif


#ifndef CRAP_VERSION_CONSTEVAL
#define CRAP_VERSION_CONSTEVAL

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_consteval
#define crap_consteval __cpp_consteval
#else
#define crap_consteval 0L
#endif

#endif


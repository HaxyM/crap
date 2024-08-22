#ifndef CRAP_VERSION_LIBVOIDT
#define CRAP_VERSION_LIBVOIDT

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_void_t
#define crap_lib_void_t __cpp_lib_void_t
#else
#ifdef _MSC_VER
#if _MSC_VER >= 1900
#define crap_lib_void_t _MSVC_LANG
#else
#define crap_lib_void_t 0L
#endif
#else
#define crap_lib_void_t 0L
#endif
#endif

#endif


#ifndef CRAP_VERSION_LIBGCDLCM
#define CRAP_VERSION_LIBGCDLCM

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_gcd_lcm
#define crap_lib_gcd_lcm __cpp_lib_gcd_lcm
#else
#ifdef _MSC_VER
#if _MSC_VER >= 1911
#define crap_lib_gcd_lcm _MSVC_LANG
#else
#define crap_lib_gcd_lcm 0L
#endif
#else
#define crap_lib_gcd_lcm 0L
#endif
#endif

#endif


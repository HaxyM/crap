#ifndef CRAP_VERSION_LIBINTEGRALCONSTANTCALLABLE
#define CRAP_VERSION_LIBINTEGRALCONSTANTCALLABLE

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_integral_constant_callable
#define crap_lib_integral_constant_callable __cpp_lib_integral_constant_callable
#else
#ifdef _MSC_VER
#if _MSC_VER >= 1900
#define crap_lib_integral_constant_callable _MSVC_LANG
#else
#define crap_lib_integral_constant_callable 0L
#endif
#else
#define crap_lib_integral_constant_callable 0L
#endif
#endif

#endif


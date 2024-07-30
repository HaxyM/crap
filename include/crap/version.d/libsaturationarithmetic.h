#ifndef CRAP_VERSION_LIBSATURATIONARITHMETIC
#define CRAP_VERSION_LIBSATURATIONARITHMETIC

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_saturation_arithmetic
#define crap_lib_saturation_arithmetic __cpp_lib_saturation_arithmetic
#else
#define crap_lib_saturation_arithmetic 0L
#endif

#endif


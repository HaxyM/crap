#ifndef CRAP_VERSION_LIBINTEGERCOMPARISONFUNCTIONS
#define CRAP_VERSION_LIBINTEGERCOMPARISONFUNCTIONS

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_integer_comparison_functions
#define crap_lib_integer_comparison_functions __cpp_lib_integer_comparison_functions
#else
#define crap_lib_integer_comparison_functions 0L
#endif

#endif


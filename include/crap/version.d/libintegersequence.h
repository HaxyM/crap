#ifndef CRAP_VERSION_LIBINTEGERSEQUENCE
#define CRAP_VERSION_LIBINTEGERSEQUENCE

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_integer_sequence
#define crap_lib_integer_sequence __cpp_lib_integer_sequence
#else
#ifdef _MSC_VER
#if _MSC_VER >= 1900
#define crap_lib_integer_sequence _MSVC_LANG
#else
#define crap_lib_integer_sequence 0L
#endif
#else
#define crap_lib_integer_sequence 0L
#endif
#endif

#endif


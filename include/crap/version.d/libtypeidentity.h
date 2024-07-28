#ifndef CRAP_VERSION_LIBTYPEIDENTITY
#define CRAP_VERSION_LIBTYPEIDENTITY

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_type_identity
#define crap_lib_type_identity __cpp_lib_type_identity
#else
#ifdef _MSC_VER
#if _MSC_VER >= 1921
#define crap_lib_type_identity _MSVC_LANG
#else
#define crap_lib_type_identity 0L
#endif
#else
#define crap_lib_type_identity 0L
#endif
#endif

#endif


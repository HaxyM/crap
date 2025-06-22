#ifndef CRAP_VERSION_NONTYPETEMPLATEARGS
#define CRAP_VERSION_NONTYPETEMPLATEARGS

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_nontype_template_args
#define crap_nontype_template_args __cpp_nontype_template_args
#else
#ifdef _MSC_VER
#if _MSC_VER >= 1926
#define crap_nontype_template_args _MSVC_LANG //P1907R1
#elif _MSC_VER >= 1912
#define crap_nontype_template_args _MSVC_LANG //N4268
#else
#define crap_nontype_template_args 0L
#endif
#else
#define crap_nontype_template_args 0L
#endif
#endif

#endif


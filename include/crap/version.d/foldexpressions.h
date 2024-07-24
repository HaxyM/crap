#ifndef CRAP_VERSION_FOLDEXPRESSIONS
#define CRAP_VERSION_FOLDEXPRESSIONS

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_fold_expressions
#define crap_fold_expressions __cpp_fold_expressions
#else
#ifdef _MSC_VER
#if _MSC_VER >= 1912
#define crap_fold_expressions _MSVC_LANG
#else
#define crap_fold_expressions 0L
#endif
#else
#define crap_fold_expressions 0L
#endif
#endif

#endif


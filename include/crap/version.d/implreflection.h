#ifndef CRAP_VERSION_IMPLREFLECTION
#define CRAP_VERSION_IMPLREFLECTION

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_impl_reflection
#define crap_impl_reflection __cpp_impl_reflection
#else
#define crap_impl_reflection 0L
#endif

#endif


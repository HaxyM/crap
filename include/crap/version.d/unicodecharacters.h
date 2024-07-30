#ifndef CRAP_VERSION_UNICODECHARACTERS
#define CRAP_VERSION_UNICODECHARACTERS

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_unicode_characters
#define crap_unicode_characters __cpp_unicode_characters
#else
#ifdef _MSC_VER
#if _MSC_VER >= 1900
#define crap_unicode_characters _MSVC_LANG
#else
#define crap_unicode_characters 0L
#endif
#else
#define crap_unicode_characters 0L
#endif
#endif

#endif


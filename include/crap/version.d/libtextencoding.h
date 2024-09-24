#ifndef CRAP_VERSION_LIBTEXTENCODING
#define CRAP_VERSION_LIBTEXTENCODING

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_lib_text_encoding
#define crap_lib_text_encoding __cpp_lib_text_encoding
#else
#define crap_lib_text_encoding 0L
#endif

#endif


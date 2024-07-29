#ifndef CRAP_VERSION_PACKINDEXING
#define CRAP_VERSION_PACKINDEXING

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_pack_indexing
#define crap_pack_indexing __cpp_pack_indexing
#else
#define crap_pack_indexing 0L
#endif

#endif


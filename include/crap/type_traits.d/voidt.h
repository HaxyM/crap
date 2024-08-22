#ifndef CRAP_TYPETRAITS_VOIDT
#define CRAP_TYPETRAITS_VOIDT

#include "../version.d/libvoidt.h"

#if (crap_lib_void_t >= 201411L)
#include <type_traits>
#endif

namespace crap
{
#if (crap_lib_void_t >= 201411L)
 template <class ... Types> using voidT = std :: void_t<Types...>;
#else
 //TODO: May require CWG Issue 1558 walkaround.
 template <class...> using voidT = void;
#endif
}
#endif


#ifndef CRAP_UTILITY_TYPEIDENTITY
#define CRAP_UTILITY_TYPEIDENTITY

#include "../version.d/libtypeidentity.h"

#if (crap_lib_type_identity >= 201806L)
#include <type_traits>
#endif

namespace crap
{
#if (crap_lib_type_identity >= 201806L)
 template <class Type> using typeIdentity = std :: type_identity<Type>;
#else
 template <class Type> struct typeIdentity
 {
  using type = Type;
 };
#endif
}
#endif


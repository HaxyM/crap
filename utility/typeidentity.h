#ifndef CRAP_UTILITY_TYPEIDENTITY
#define CRAP_UTILITY_TYPEIDENTITY

#include "language.h"

#if CPP20
#include <type_traits>
#endif

namespace crap
{
#if CPP20
 template <class Type> using typeIdentity = std :: type_identity<Type>;
#else
 template <class Type> struct typeIdentity
 {
  using type = Type;
 };
#endif
}
#endif


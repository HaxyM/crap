#ifndef CRAP_UTILITY_TYPECOMA
#define CRAP_UTILITY_TYPECOMA

#include "typeidentity.h"

namespace crap
{
 template <class, class Type> using typeComa = typeIdentity<Type>;
 template <class, class Type> using typeComa_t = Type;
}
#endif

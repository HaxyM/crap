#ifndef CRAP_NUMERIC_CONTRACTTYPE
#define CRAP_NUMERIC_CONTRACTTYPE

#include <ratio>

#include "../utility.d/typeidentity.h"

namespace crap
{
 template <class Type> struct contractType;

 template <intmax_t Numerator, intmax_t Denominator> struct contractType<std :: ratio<Numerator, Denominator> >
	 : typeIdentity<typename std :: ratio <Numerator, Denominator> :: type> {};

 template <class Type> using contractType_t = typename contractType <Type> :: type;
}
#endif


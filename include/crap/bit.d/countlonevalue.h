#ifndef CRAP_BIT_COUNTLONEVALUE
#define CRAP_BIT_COUNTLONEVALUE

#include "countlzerovalue.h"

namespace crap
{
 template <class Type, Type Value>
	 using countlOneValue = countlZeroValue<Type, static_cast<Type>(~Value)>;
}
#endif


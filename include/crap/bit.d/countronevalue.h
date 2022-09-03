#ifndef CRAP_BIT_COUNTRONEVALUE
#define CRAP_BIT_COUNTRONEVALUE

#include "countrzerovalue.h"

namespace crap
{
 template <class Type, Type Value>
	 using countrOneValue = countrZeroValue<Type, static_cast<Type>(~Value)>;
}
#endif


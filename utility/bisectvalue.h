#ifndef CRAP_UTILITY_BISECTVALUE
#define CRAP_UTILITY_BISECTVALUE

#include "splitvalue.h"

namespace crap
{
 template <class Type, Type ... Values> using bisectValue = splitValue<(sizeof...(Values) / 2u), Type, Values...>;
}
#endif


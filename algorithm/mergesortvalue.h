#ifndef CRAP_ALGORITHM_MERGESORTVALUE
#define CRAP_ALGORITHM_MERGESORTVALUE

#include "copyvalue.h"
#include "mergevaluezipper.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 using mergeSortValue = mergeValueZipper<Type, Operator, copyValue <Type, Values> :: template type...>;
}
#endif


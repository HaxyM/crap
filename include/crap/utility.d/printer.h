#ifndef CRAP_UTILITY_PRINTER
#define CRAP_UTILITY_PRINTER

#include <iostream>
#include <string>

#include "valueList.h"

namespace crap
{
 class printer
 {
  public:
  template <class Type, Type ... Values> static std :: ostream& print(std :: ostream& stream, const std :: string& separator, valueList<Type, Values...>);
 };
}

template <class Type, Type ... Values> inline std :: ostream& crap :: printer :: print(std :: ostream& stream, const std :: string& separator, crap :: valueList<Type, Values...>)
{
 (void)((int[]){0, (((void)(stream << Values << separator)), 0)...});
 return stream;
}
#endif


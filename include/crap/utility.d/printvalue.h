#ifndef CRAP_UTILITY_PRINTVALUE
#define CRAP_UTILITY_PRINTVALUE

#include <iostream>
#include <string>

namespace crap
{
 template <class Type, Type ... Values> class printValue
 {
  public:
  static std :: ostream& print(std :: ostream& stream, const std :: string& separator);
 };
}

template <class Type, Type ... Values>
inline std :: ostream&
crap :: printValue <Type, Values...> :: print(std :: ostream& stream, const std :: string& separator)
{
 (void)((int[]){0, (((void)(stream << Values << separator)), 0)...});
 return stream;
}
#endif


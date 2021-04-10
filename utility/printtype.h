#ifndef CRAP_UTILITY_PRINTTYPE
#define CRAP_UTILITY_PRINTTYPE

#include <iostream>
#include <string>
#include <typeinfo>

namespace crap
{
 template <class ... Types> class printType
 {
  public:
  static std :: ostream& print(std :: ostream& stream, const std :: string& separator);
 };
}

template <class ... Types>
inline std :: ostream&
crap :: printType <Types...> :: print(std :: ostream& stream, const std :: string& separator)
{
 (void)((int[]){0, (((void)(stream << typeid(Types).name() << separator)), 0)...});
 return stream;
}
#endif


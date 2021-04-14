#ifndef CRAP_ALGORITHM_FINDTYPE
#define CRAP_ALGORITHM_FINDTYPE

#include "findiftype.h"

#include <cstddef>

namespace crap
{
 template <class Type, template <class, class> class Operator, class ... Types>
	 struct findType
 {
  private:
  template <class SubType> using condition = Operator<Type, SubType>;
  public:
  constexpr const static std :: size_t value = findIfType <condition, Types...> :: value;
  constexpr const static std :: size_t npos = findIfType <condition, Types...> :: npos;
 };
}
#endif


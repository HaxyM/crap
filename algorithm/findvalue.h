#ifndef CRAP_ALGORITHM_FINDVALUE
#define CRAP_ALGORITHM_FINDVALUE

#include "findifvalue.h"

#include <cstddef>

namespace crap
{
 template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values>
	 struct findValue
 {
  private:
  template <Type SubValue> using condition = Operator<Value, SubValue>;
  public:
  constexpr const static std :: size_t value = findIfValue <Type, condition, Values...> :: value;
  constexpr const static std :: size_t npos = findIfValue <Type, condition, Values...> :: npos;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values>
        inline constexpr crap :: findValue <Type, Value, Operator, Values...> :: operator
        typename crap :: findValue <Type, Value, Operator, Values...> :: value_type () const noexcept
{
 return crap :: findValue <Type, Value, Operator, Values...> :: value;
}
#endif


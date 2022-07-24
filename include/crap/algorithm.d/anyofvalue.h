#ifndef CRAP_ALGORITHM_ANYOFVALUE
#define CRAP_ALGORITHM_ANYOFVALUE

#include "../functional.d/logicalorvalue.h"
#include "../utility.d/commontype.h"

#include <type_traits>

namespace crap
{
 template <class Type, template <Type> class, Type...> struct anyOfValue;

 template <class Type, template <Type> class Operator> struct anyOfValue<Type, Operator>
 {
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct anyOfValue
 {
  private:
  using resultType = typename commonType <decltype(Operator <Values> :: value)...> :: type;
  public:
  constexpr const static auto value =
	  logicalOrValue <resultType, static_cast<resultType>(Operator <Values> :: value)...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <Type> class Operator>
	inline constexpr crap :: anyOfValue <Type, Operator> :: operator
	typename crap :: anyOfValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: anyOfValue <Type, Operator> :: value;
};

template <class Type, template <Type> class Operator, Type ... Values>
	inline constexpr crap :: anyOfValue <Type, Operator, Values...> :: operator
	typename crap :: anyOfValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: anyOfValue <Type, Operator, Values...> :: value;
};
#endif


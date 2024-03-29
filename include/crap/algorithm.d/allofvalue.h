#ifndef CRAP_ALGORITHM_ALLOFVALUE
#define CRAP_ALGORITHM_ALLOFVALUE

#include "../functional.d/logicalandvalue.h"
#include "../utility.d/commontype.h"

#include <type_traits>

namespace crap
{
 template <class Type, template <Type> class, Type...> struct allOfValue;

 template <class Type, template <Type> class Operator> struct allOfValue<Type, Operator>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct allOfValue
 {
  private:
  using resultType = typename commonType <decltype(Operator <Values> :: value)...> :: type;
  public:
  constexpr const static auto value =
	  logicalAndValue <resultType, static_cast<resultType>(Operator <Values> :: value)...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <Type> class Operator>
	inline constexpr crap :: allOfValue <Type, Operator> :: operator
	typename crap :: allOfValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: allOfValue <Type, Operator> :: value;
};

template <class Type, template <Type> class Operator, Type ... Values>
	inline constexpr crap :: allOfValue <Type, Operator, Values...> :: operator
	typename crap :: allOfValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: allOfValue <Type, Operator, Values...> :: value;
};
#endif


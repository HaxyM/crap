#ifndef CRAP_ALGORITHM_ALLOFTYPE
#define CRAP_ALGORITHM_ALLOFTYPE

#include "../functional.d/logicalandvalue.h"
#include "../utility.d/commontype.h"

namespace crap
{
 template <template <class> class, class...> struct allOfType;

 template <template <class> class Operator> struct allOfType<Operator>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class> class Operator, class ... Types> struct allOfType
 {
  private:
  using resultType = typename commonType <decltype(Operator <Types> :: value)...> :: type;
  public:
  constexpr const static auto value = logicalAndValue <resultType, static_cast<resultType>(Operator <Types> :: value)...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <template <class> class Operator>
        inline constexpr crap :: allOfType <Operator> :: operator
	typename crap :: allOfType <Operator> :: value_type () const noexcept
{
 return crap :: allOfType <Operator> :: value;
}

template <template <class> class Operator, class ... Types>
        inline constexpr crap :: allOfType <Operator, Types...> :: operator
	typename crap :: allOfType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: allOfType <Operator, Types...> :: value;
}
#endif


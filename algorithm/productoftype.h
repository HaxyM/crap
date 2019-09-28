#ifndef CRAP_ALGORITHM_PRODUCTOFTYPE
#define CRAP_ALGORITHM_PRODUCTOFTYPE

#include "../functional/multipliesvalue.h"



#include <type_traits>

namespace crap
{
 template <template <class> class Operator, class ... Types> struct productOfType
 {
  private:
  using resultType = typename std :: common_type <decltype(Operator <Types> :: value)...> :: type;
  public:
  constexpr const static auto value = multipliesValue <resultType, static_cast<resultType>(Operator <Types> :: value)...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <template <class> class Operator, class ... Types>
inline constexpr crap :: productOfType <Operator, Types...> :: operator typename crap :: productOfType <Operator, Types...> :: value_type () const noexcept
{
 return value;
}
#endif


#ifndef CRAP_ALGORITHM_FINDTYPE
#define CRAP_ALGORITHM_FINDTYPE

#include <cstddef>

#include "findiftype.h"
#include "../version.d/libintegralconstantcallable.h"

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
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <class Type, template <class, class> class Operator, class ... Types>
        inline constexpr crap :: findType <Type, Operator, Types...> :: operator
        typename crap :: findType <Type, Operator, Types...> :: value_type () const noexcept
{
 return crap :: findType <Type, Operator, Types...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <class, class> class Operator, class ... Types>
        inline constexpr typename crap :: findType <Type, Operator, Types...> :: value_type
        crap :: findType <Type, Operator, Types...> :: operator () () const noexcept
{
 return crap :: findType <Type, Operator, Types...> :: value;
}
#endif
#endif


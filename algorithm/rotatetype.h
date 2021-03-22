#ifndef CRAP_ALGORITHM_ROTATETYPE
#define CRAP_ALGORITHM_ROTATETYPE

#include "../utility/concatenatetype.h"
#include "../utility/splittype.h"
#include "../utility/typelist.h"

namespace crap
{
 template <std :: size_t N, class...> struct rotateType;

 template <std :: size_t N> struct rotateType<N>
 {
  template <template <class...> class Container = typeList> using type = Container<>;
 };

 template <std :: size_t N, class Type> struct rotateType<N, Type>
 {
  template <template <class...> class Container = typeList> using type = Container<Type>;
 };

 template <std :: size_t N, class ... Types> struct rotateType
 {
  private:
  constexpr const static auto pivot = N % sizeof...(Types);
  using values = splitType<pivot, Types...>;
  using upper = typename values :: template upper<concatenateType>;
  using lower = typename values :: template lower<upper :: template with>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename lower :: template type<Container>;
 };
}
#endif


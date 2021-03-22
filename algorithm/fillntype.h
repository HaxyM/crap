#ifndef CRAP_ALGORITHM_FILLNTYPE
#define CRAP_ALGORITHM_FILLNTYPE

#include "copytype.h"
#include "../utility/concatenatetype.h"
#include "../utility/splittype.h"
#include "../utility/typelist.h"

#include <cstddef>

namespace crap
{
 template <class Type, std :: size_t N, class ... Types> struct fillNType
 {
  private:
  constexpr const static std :: size_t pivot = ((sizeof...(Types) < N) ? sizeof...(Types) : N);
  using values = splitType<N, Types...>;
  template <class> using coma = Type;
  template <class ... SubTypes> using transform = copyType<coma<SubTypes>...>;
  template <template <class...> class Container>
	  using lower = typename values :: template lower <transform> :: template type<Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename values :: template upper <lower <concatenateType> :: template with> ::
	  template type<Container>;
 };
}
#endif


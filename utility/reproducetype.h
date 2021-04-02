#ifndef CRAP_UTILITY_REPRODUCETYPE
#define CRAP_UTILITY_REPRODUCETYPE

#include "../algorithm/copytype.h"
#include "../numeric/iotavalue.h"
#include "../utility/typelist.h"

#include <cstddef>

namespace crap
{
 template <std :: size_t N, class Type> struct reproduceType
 {
  private:
  template <std :: size_t> using convertSingle = Type;
  template <std :: size_t ... Indices>
	  using convert = copyType<convertSingle<Indices>...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename iotaValue <N, std :: size_t> :: template
	  type <convert> :: template type<Container>;
 };
}
#endif


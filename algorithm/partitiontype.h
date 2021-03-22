#ifndef CRAP_ALGORITHM_PARTITIONTYPE
#define CRAP_ALGORITHM_PARTITIONTYPE

#include "counttype.h"
#include "partitioncopytype.h"
#include "../utility/concatenatetype.h"
#include "../utility/typelist.h"

#include <cstddef>

namespace crap
{
 template <template <class> class Operator, class ... Types> struct partitionType
 {
  private:
  using values = partitionCopyType<Operator, Types...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename values :: template
	  resultFalse <values :: template resultTrue <concatenateType> :: template with> :: template
	  type<Container>;
  constexpr const static std :: size_t value = values :: template resultTrue <countType> :: value;
 };
}
#endif


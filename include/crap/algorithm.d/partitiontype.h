#ifndef CRAP_ALGORITHM_PARTITIONTYPE
#define CRAP_ALGORITHM_PARTITIONTYPE

#include "partitioncopytype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/sizetype.h"
#include "../utility.d/typelist.h"

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
  constexpr const static std :: size_t value = values :: template resultTrue <sizeType> :: value;
 };
}
#endif


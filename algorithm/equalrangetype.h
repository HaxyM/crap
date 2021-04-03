#ifndef CRAP_ALGORITHM_EQUALRANGETYPE
#define CRAP_ALGORITHM_EQUALRANGETYPE

#include "../utility/typelist.h"
#include "../utility/typemultiplexer.h"

#include <cstddef>

namespace crap
{
 template <class, template <class, class> class, class...> struct equalRangeType;

 template <class Type, template <class, class> class Operator> struct equalRangeType<Type, Operator>
 {
  constexpr const static std :: size_t begin = 0u;
  constexpr const static std :: size_t end = 0u;
  constexpr const static std :: size_t npos = 0u;
 };

 template <class Type, template <class, class> class Operator, class Type1>
	 struct equalRangeType<Type, Operator, Type1>
 {
  constexpr const static std :: size_t begin = (Operator <Type1, Type> :: value ? 1u : 0u);
  constexpr const static std :: size_t end = (Operator <Type, Type1> :: value ? 0u : 1u);
  constexpr const static std :: size_t npos = 1u;
 };

 template <class Type, template <class, class> class Operator, class ... Types> struct equalRangeType
 {
  private:
  using values = typeList<Types...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <template <class...> class Container>
	  using lowerSource = typename values :: template till<half, Container>;
  template <template <class...> class Container>
	  using upperSource = typename values :: template since<half, Container>;
  template <template <class...> class Container> using emptySource = Container<>;
  template <class ... SubTypes> using This = equalRangeType<Type, Operator, SubTypes...>;
  using midType = typename values :: template at<half>;
  constexpr const static bool notInLower = Operator <midType, Type> :: value;
  constexpr const static bool notInUpper = Operator <Type, midType> :: value;
  using lower = typename typeMultiplexer <notInLower, This, emptySource, lowerSource> :: type;
  using upper = typename typeMultiplexer <notInUpper, This, emptySource, upperSource> :: type;
  public:
  constexpr const static std :: size_t begin = (notInLower ? (half + (upper :: begin)) : (lower :: begin));
  constexpr const static std :: size_t end = (notInUpper ? (lower :: end) : (half + (upper :: end)));
  constexpr const static std :: size_t npos = values :: size;
 };
}
#endif


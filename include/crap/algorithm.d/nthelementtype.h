#ifndef CRAP_ALGORITHM_NTHELEMENTTYPE
#define CRAP_ALGORITHM_NTHELEMENTTYPE

#include <cstddef>
#include <type_traits>

#include "minelementtype.h"
#include "maxelementtype.h"
#include "partitioncopytype.h"
#include "../iterator.d/sizetype.h"
#include "../utility.d/bisecttype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/splittype.h"
#include "../utility.d/swapindicestype.h"
#include "../utility.d/typelist.h"

namespace crap
{
 template <std :: size_t, template <class, class> class, class...> struct NthElementType;

 template <std :: size_t N, template <class, class> class Operator> struct NthElementType<N, Operator>
 {
  static_assert(N <= 0u, "Index out of range.");
  template <template <class...> class Container = typeList> using type = Container<>;
 };

 template <std :: size_t N, template <class, class> class Operator, class Type> struct
	 NthElementType<N, Operator, Type>
 {
  static_assert(N <= 1u, "Index out of range.");
  template <template <class...> class Container = typeList> using type = Container<Type>;
 };

 template <std :: size_t N , template <class, class> class Operator, class Type1, class Type2>
	 struct NthElementType<N, Operator, Type1, Type2>
 {
  static_assert(N <= 2u, "Index out of range.");
  template <template <class...> class Container = typeList>
	  using type = Container<typename std :: conditional <(Operator <Type2, Type1> :: value && (N < 2u)), Type2, Type1> :: type, typename std :: conditional <(Operator <Type2, Type1> :: value && (N < 2u)), Type1, Type2> :: type>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types> struct NthElementType
 {
  static_assert(N <= sizeof...(Types), "Index out of range.");
  private:
  template <bool, template <class...> class Container, std :: size_t, std :: size_t, class ... SubTypes>
	  struct Implementation;
  template <template <class...> class Container, std :: size_t NewN, std :: size_t LastIndex>
	  struct Implementation<false, Container, NewN, LastIndex>;
  template <template <class...> class Container, std :: size_t NewN, std :: size_t LastIndex, class SubType>
	  struct Implementation<false, Container, NewN, LastIndex, SubType>;
  template <template <class...> class Container, std :: size_t LastIndex, class First, class ... Rest>
	  struct Implementation<false, Container, 0u, LastIndex, First, Rest...>;
  template <template <class...> class Container, std :: size_t LastIndex, class First, class ... Rest>
	  struct Implementation<false, Container, LastIndex, LastIndex, First, Rest...>;
  template <template <class...> class Container, std :: size_t NewN, std :: size_t LastIndex, class First, class ... Rest>
	  struct Implementation<false, Container, NewN, LastIndex, First, Rest...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Implementation <(N == sizeof...(Types)), Container, N, (sizeof...(Types) - 1u), Types...> :: type;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, std :: size_t NewN, std :: size_t LastIndex>
 struct NthElementType <N, Operator, Types...> :: template Implementation<false, Container, NewN, LastIndex>
 {
  using type = Container<>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, std :: size_t NewN, std :: size_t LastIndex, class SubType>
 struct NthElementType <N, Operator, Types...> :: template Implementation<false, Container, NewN, LastIndex, SubType>
 {
  using type = Container<SubType>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, std :: size_t LastIndex, class First, class ... Rest>
 struct NthElementType <N, Operator, Types...> :: template Implementation<false, Container, 0u, LastIndex, First, Rest...>
 {
  private:
  constexpr const static std :: size_t minIndex = minElementType <Operator, First, Rest...> :: value;
  public:
  using type = typename swapIndicesType <0u, minIndex, First, Rest...> :: template type<Container>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, std :: size_t LastIndex, class First, class ... Rest>
 struct NthElementType <N, Operator, Types...> :: template
	 Implementation<false, Container, LastIndex, LastIndex, First, Rest...>
 {
  private:
  constexpr const static std :: size_t maxIndex = maxElementType <Operator, First, Rest...> :: value;
  public:
  using type = typename swapIndicesType <maxIndex, sizeof...(Rest), First, Rest...> :: template type<Container>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, std :: size_t NewN, std :: size_t LastIndex, class First, class ... Rest>
 struct NthElementType <N, Operator, Types...> :: template Implementation<false, Container, NewN, LastIndex, First, Rest...>
 {
  private:
  using comparedElement = typename typeList <First, Rest...> :: template at<NewN>;
  template <class Type> using Condition = Operator<Type, comparedElement>;
  using partitioned = partitionCopyType<Condition, First, Rest...>;
  constexpr const static std :: size_t lowerSize = partitioned :: template resultTrue <sizeType> :: value;
  template <class ... LowerTypes>
	  using lower = typename Implementation <lowerSize <= NewN, concatenateType, NewN, lowerSize - 1u, LowerTypes...> :: type;
  template <class ... UpperTypes>
	  using upper = typename Implementation <NewN < lowerSize, partitioned :: template resultTrue <lower> :: template with, (NewN - lowerSize), (LastIndex - lowerSize), UpperTypes...> :: type;
  public:
  using type = typename partitioned :: template resultFalse <upper> :: template type<Container>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <bool, template <class...> class Container, std :: size_t, std :: size_t, class ... SubTypes>
 struct NthElementType <N, Operator, Types...> :: Implementation
 {
  using type = Container<SubTypes...>;
 };
}
#endif


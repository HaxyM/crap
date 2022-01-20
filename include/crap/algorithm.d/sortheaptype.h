#ifndef CRAP_ALGORITHM_SORTHEAPTYPE
#define CRAP_ALGORITHM_SORTHEAPTYPE

#include "copytype.h"
#include "pullheaptype.h"
#include "../utility.d/typelist.h"

namespace crap
{
 template <template <class, class> class, class...> struct sortHeapType;

 template <template <class, class> class Operator> struct sortHeapType<Operator>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <template <class, class> class Operator, class Type>
	 struct sortHeapType<Operator, Type>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<Type>;
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct sortHeapType<Operator, Type1, Type2>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<Type2, Type1>;
 };

 template <template <class, class> class Operator, class ... Types> struct sortHeapType
 {
  private:
  template <class ... SubTypes> struct back;
  template <class ... SubTypes> using This = sortHeapType<Operator, SubTypes...>;
  using pop = typename pullHeapType <Operator, Types...> :: template type<back>;
  template <class ... SubTypes> using merge = copyType <SubTypes..., typename pop :: type>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename pop :: template rest <This> :: template type <merge> :: template type<Container>;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <class ... SubTypes>
 struct sortHeapType <Operator, Types...> :: back
 {
  private:
  using types = typeList<SubTypes...>;
  public:
  using type = typename types :: template at<sizeof...(SubTypes) - 1u>;
  template <template <class...> class Container>
	  using rest = typename types :: template till<sizeof...(SubTypes) - 1u, Container>;
 };
}
#endif


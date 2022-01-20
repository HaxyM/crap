#ifndef CRAP_ALGORITHM_REVERSETYPE
#define CRAP_ALGORITHM_REVERSETYPE

#include "../utility.d/bisecttype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typelist.h"

namespace crap
{
 template <class...> struct reverseType;

 template <> struct reverseType<>
 {
  template <template <class...> class Container = typeList> using type = Container<>;
 };

 template <class Type> struct reverseType<Type>
 {
  template <template <class...> class Container = typeList> using type = Container<Type>;
 };

 template <class Type1, class Type2> struct reverseType<Type1, Type2>
 {
  template <template <class...> class Container = typeList> using type = Container<Type2, Type1>;
 };

 template <class Type1, class Type2, class Type3> struct reverseType<Type1, Type2, Type3>
 {
  template <template <class...> class Container = typeList> using type = Container<Type3, Type2, Type1>;
 };

 template <class ... Types> struct reverseType
 {
  private:
  using values = bisectType<Types...>;
  template <class ... SubTypes> using This = reverseType<SubTypes...>;
  using upper = typename values :: template upper <This> :: template type<concatenateType>;
  using lower = typename values :: template lower <This> :: template type<upper :: template with>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename lower :: template type<Container>;
 };
}
#endif


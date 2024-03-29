#ifndef CRAP_NUMERIC_INNERPRODUCTTYPE
#define CRAP_NUMERIC_INNERPRODUCTTYPE

#include "reducetype.h"
#include "../algorithm.d/transform2type.h"

namespace crap
{
 template <template <class...> class AdditiveOperator, template <class...> class MultiplicativeOperator, class ... Types1>
 struct innerProductType
 {
  template <class ... Types2> struct with;
  template <class ... Types2> using with_t = typename with <Types2...> :: type;
 };

 template <template <class...> class AdditiveOperator, template <class...> class MultiplicativeOperator, class ... Types1>
 template <class ... Types2> struct innerProductType <AdditiveOperator, MultiplicativeOperator, Types1...> :: with
 {
  private:
  template <class A, class B> using multiplicative = MultiplicativeOperator<A, B>;
  template <class ... SubTypes> using Reductor = reduceType<AdditiveOperator, SubTypes...>;
  public:
  using type = typename transform2Type <multiplicative, Types1...> :: template
	  with <Types2...> :: template type<Reductor> :: type;
 };
}
#endif


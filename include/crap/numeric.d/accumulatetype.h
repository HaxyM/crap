#ifndef CRAP_NUMERIC_ACCUMULATETYPE
#define CRAP_NUMERIC_ACCUMULATETYPE

#include "../utility.d/bisecttype.h"
#include "../utility.d/typeidentity.h"

namespace crap
{
 template <template <class...> class, class...> struct accumulateType;

 template <template <class...> class Operator> struct accumulateType<Operator>
	 : typeIdentity<typename Operator <> :: type> {};

 template <template <class...> class Operator, class Type> struct accumulateType<Operator, Type>
	 : typeIdentity<typename Operator <Type> :: type> {};

 template <template <class...> class Operator, class Type1, class Type2> struct accumulateType<Operator, Type1, Type2>
	 : typeIdentity<typename Operator <Type1, Type2> :: type> {};

 template <template <class...> class Operator, class Type1, class Type2, class Type3>
	 struct accumulateType<Operator, Type1, Type2, Type3>
 {
  private:
  using subResult = typename Operator <Type1, Type2> :: type;
  public:
  using type = typename Operator <subResult, Type3> :: type;
 };

 template <template <class...> class Operator, class ... Types> struct accumulateType
 {
  private:
  using types = bisectType<Types...>;
  template <class ... SubTypes> using firstHalf = accumulateType <Operator, SubTypes...>;
  using firstHalfType = typename types :: template lower <firstHalf> :: type;
  template <class ... SubTypes> using secondHalf = accumulateType<Operator, firstHalfType, SubTypes...>;
  public:
  using type = typename types :: template upper <secondHalf> :: type;
 };

 template <template <class...> class Operator, class ... Types> using accumulateType_t = typename accumulateType <Operator, Types...> :: type;
}
#endif


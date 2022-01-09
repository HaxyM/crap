#ifndef CRAP_ALGORITHM_MINMAXELEMENTTYPE
#define CRAP_ALGORITHM_MINMAXELEMENTTYPE

#include <cstddef>
#include <type_traits>

#include "../utility/bisecttype.h"

namespace crap
{
 template <template <class, class> class, class...> struct minMaxElementType;

 template <template <class, class> class Operator> struct minMaxElementType<Operator>
 {
  constexpr const static std :: size_t maximum = 0u;
  constexpr const static std :: size_t minimum = 0u;
  constexpr const static std :: size_t npos = 0u;
 };

 template <template <class, class> class Operator, class Type>
	 struct minMaxElementType<Operator, Type>
 {
  template <template <class, class> class, class...> friend struct minMaxElementType;
  private:
  using maxType = Type;
  using minType = Type;
  public:
  constexpr const static std :: size_t maximum = 0u;
  constexpr const static std :: size_t minimum = 0u;
  constexpr const static std :: size_t npos = 1u;
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct minMaxElementType<Operator, Type1, Type2>
 {
  template <template <class, class> class, class...> friend struct minMaxElementType;
  private:
  using maxType = typename std :: conditional <(Operator <Type1, Type2> :: value), Type2, Type1> :: type;
  using minType = typename std :: conditional <(Operator <Type2, Type1> :: value), Type2, Type1> :: type;
  public:
  constexpr const static std :: size_t maximum = ((Operator <Type1, Type2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t minimum = ((Operator <Type2, Type1> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = 2u;
 };

 template <template <class, class> class Operator, class ... Types> struct minMaxElementType
 {
  template <template <class, class> class, class...> friend struct minMaxElementType;
  private:
  template <class ... SubTypes> using This = minMaxElementType<Operator, SubTypes...>;
  using lower = typename bisectType <Types...> :: template lower<This>;
  using upper = typename bisectType <Types...> :: template upper<This>;
  using maxType = typename 
	  std :: conditional <(Operator <typename lower :: maxType, typename upper :: maxType> :: value),
	      typename upper :: maxType, typename lower :: maxType> :: type;
  using minType = typename
	  std :: conditional <(Operator <typename upper :: minType, typename lower :: minType> :: value),
	      typename upper :: minType, typename lower :: minType> :: type;
  public:
  constexpr const static std :: size_t maximum =
	  ((Operator <typename lower :: maxType, typename upper :: maxType> :: value) ? (lower :: npos + upper :: maximum) : (lower :: maximum));
  constexpr const static std :: size_t minimum =
	  ((Operator <typename upper :: minType, typename lower :: minType> :: value) ? (lower :: npos + upper :: minimum) : (lower :: minimum));
  constexpr const static std :: size_t npos = sizeof...(Types);
 };
}
#endif


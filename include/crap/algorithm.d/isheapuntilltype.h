#ifndef CRAP_ALGORITHM_ISHEAPUNTILLTYPE
#define CRAP_ALGORITHM_ISHEAPUNTILLTYPE

#include <cstddef>

#include "../utility.d/bisectvalue.h"
#include "../utility.d/makeindexsequence.h"
#include "../utility.d/typelist.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <template <class, class> class, class...> struct isHeapUntillType;

 template <template <class, class> class Operator> struct isHeapUntillType<Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type>
	 struct isHeapUntillType<Operator, Type>
 {
  constexpr const static std :: size_t value = 1u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct isHeapUntillType<Operator, Type1, Type2>
 {
  constexpr const static std :: size_t value = (Operator <Type1, Type2> :: value ? 1u : 2u);
  constexpr const static std :: size_t npos = 2u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class ... Types>
	 struct isHeapUntillType
 {
  private:
  template <bool, class> struct Implementation;
  template <bool True> struct Implementation<True, indexSequence<0u> >;
  template <bool False, std :: size_t Index> struct Implementation<False, indexSequence<Index> >;
  template <bool HasFront, std :: size_t ... Indices>
	  struct Implementation<HasFront, indexSequence<Indices...> >;
  public:
  constexpr const static std :: size_t value =
	  Implementation <true, makeIndexSequence<sizeof...(Types)> > :: value;
  constexpr const static std :: size_t npos = sizeof...(Types);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class ... Types>
	 template <bool True>
 struct isHeapUntillType <Operator, Types...> ::
	 Implementation<True, indexSequence<0u> >
 {
  constexpr const static std :: size_t value = sizeof...(Types);
 };

 template <template <class, class> class Operator, class ... Types>
	 template <bool False, std :: size_t Index>
 struct isHeapUntillType <Operator, Types...> ::
	 Implementation<False, indexSequence<Index> >
 {
  private:
  using types = typeList<Types...>;
  using parent = typename types :: template at<(Index - 1u) / 2u>;
  using child = typename types :: template at<Index>;
  public:
  constexpr const static std :: size_t value =
	  (Operator <parent, child> :: value ? Index : sizeof...(Types));
 };

 template <template <class, class> class Operator, class ... Types>
	 template <bool HasFront, std :: size_t ... Indices>
 struct isHeapUntillType <Operator, Types...> ::
	 Implementation<HasFront, indexSequence<Indices...> >
 {
  private:
  template <std :: size_t ... SubIndices>
	  using Lower = typename isHeapUntillType <Operator, Types...> :: template
	  Implementation<HasFront, indexSequence<SubIndices...> >;
  constexpr const static std :: size_t lowerValue =
	  bisectValue <std :: size_t, Indices...> :: template lower <Lower> :: value;
  template <std :: size_t Index, std :: size_t Npos> struct Upper;
  template <std :: size_t Npos> struct Upper <Npos, Npos>;
  public:
  constexpr const static std :: size_t value = Upper <lowerValue, sizeof...(Types)> :: value;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <bool HasFront, std :: size_t ... Indices>
	 template <std :: size_t Index, std :: size_t Npos>
 struct isHeapUntillType <Operator, Types...> ::
	 Implementation <HasFront, indexSequence<Indices...> > :: Upper
 {
  constexpr const static std :: size_t value = Index;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <bool HasFront, std :: size_t ... Indices>
	 template <std :: size_t Npos>
 struct isHeapUntillType <Operator, Types...> ::
	 Implementation <HasFront, indexSequence<Indices...> > ::
	 Upper<Npos, Npos>
 {
  private:
  template <std :: size_t ... SubIndices>
	  using pass = typename isHeapUntillType <Operator, Types...> :: template
	  Implementation<false, indexSequence<SubIndices...> >;
  public:
  constexpr const static std :: size_t value =
	  bisectValue <std :: size_t, Indices...> :: template upper <pass> :: value;
 };
}

template <template <class, class> class Operator>
        inline constexpr crap :: isHeapUntillType <Operator> :: operator
        typename crap :: isHeapUntillType <Operator> :: value_type () const noexcept
{
 return crap :: isHeapUntillType <Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator>
	inline constexpr typename crap :: isHeapUntillType <Operator> :: value_type
	crap :: isHeapUntillType <Operator> :: operator () () const noexcept
{
 return crap :: isHeapUntillType <Operator> :: value;
}
#endif

template <template <class, class> class Operator, class Type1>
        inline constexpr crap :: isHeapUntillType <Operator, Type1> :: operator
        typename crap :: isHeapUntillType <Operator, Type1> :: value_type () const noexcept
{
 return crap :: isHeapUntillType <Operator, Type1> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type1>
	inline constexpr typename crap :: isHeapUntillType <Operator, Type1> :: value_type
	crap :: isHeapUntillType <Operator, Type1> :: operator () () const noexcept
{
 return crap :: isHeapUntillType <Operator, Type1> :: value;
}
#endif

template <template <class, class> class Operator, class Type1, class Type2>
        inline constexpr crap :: isHeapUntillType <Operator, Type1, Type2> :: operator
        typename crap :: isHeapUntillType <Operator, Type1, Type2> :: value_type () const noexcept
{
 return crap :: isHeapUntillType <Operator, Type1, Type2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type1, class Type2>
	inline constexpr typename crap :: isHeapUntillType <Operator, Type1, Type2> :: value_type
	crap :: isHeapUntillType <Operator, Type1, Type2> :: operator () () const noexcept
{
 return crap :: isHeapUntillType <Operator, Type1, Type2> :: value;
}
#endif

template <template <class, class> class Operator, class ... Types>
        inline constexpr crap :: isHeapUntillType <Operator, Types...> :: operator
        typename crap :: isHeapUntillType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: isHeapUntillType <Operator, Types...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class ... Types>
	inline constexpr typename crap :: isHeapUntillType <Operator, Types...> :: value_type
	crap :: isHeapUntillType <Operator, Types...> :: operator () () const noexcept
{
 return crap :: isHeapUntillType <Operator, Types...> :: value;
}
#endif
#endif

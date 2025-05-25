#ifndef CRAP_ALGORITHM_ISHEAPUNTILLVALUE
#define CRAP_ALGORITHM_ISHEAPUNTILLVALUE

#include <cstddef>

#include "../utility.d/bisectvalue.h"
#include "../utility.d/makeindexsequence.h"
#include "../utility.d/valuelist.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct isHeapUntillValue;

 template <class Type, template <Type, Type> class Operator> struct isHeapUntillValue<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct isHeapUntillValue<Type, Operator, Value>
 {
  constexpr const static std :: size_t value = 1u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct isHeapUntillValue<Type, Operator, Value1, Value2>
 {
  constexpr const static std :: size_t value = (Operator <Value1, Value2> :: value ? 1u : 2u);
  constexpr const static std :: size_t npos = 2u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 struct isHeapUntillValue
 {
  private:
  template <bool, class> struct Implementation;
  template <bool True> struct Implementation<True, indexSequence<0u> >;
  template <bool False, std :: size_t Index> struct Implementation<False, indexSequence<Index> >;
  template <bool HasFront, std :: size_t ... Indices>
	  struct Implementation<HasFront, indexSequence<Indices...> >;
  public:
  constexpr const static std :: size_t value =
	  Implementation <true, makeIndexSequence<sizeof...(Values)> > :: value;
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <bool True>
 struct isHeapUntillValue <Type, Operator, Values...> ::
	 Implementation<True, indexSequence<0u> >
 {
  constexpr const static std :: size_t value = sizeof...(Values);
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <bool False, std :: size_t Index>
 struct isHeapUntillValue <Type, Operator, Values...> ::
	 Implementation<False, indexSequence<Index> >
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static Type parent = values :: template At <(Index - 1u) / 2u> :: value;
  constexpr const static Type child = values :: template At <Index> :: value;
  public:
  constexpr const static std :: size_t value =
	  (Operator <parent, child> :: value ? Index : sizeof...(Values));
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <bool HasFront, std :: size_t ... Indices>
 struct isHeapUntillValue <Type, Operator, Values...> ::
	 Implementation<HasFront, indexSequence<Indices...> >
 {
  private:
  template <std :: size_t ... SubIndices>
	  using Lower = typename isHeapUntillValue <Type, Operator, Values...> :: template
	  Implementation<HasFront, indexSequence<SubIndices...> >;
  constexpr const static std :: size_t lowerValue =
	  bisectValue <std :: size_t, Indices...> :: template lower <Lower> :: value;
  template <std :: size_t Index, std :: size_t Npos> struct Upper;
  template <std :: size_t Npos> struct Upper <Npos, Npos>;
  public:
  constexpr const static std :: size_t value = Upper <lowerValue, sizeof...(Values)> :: value;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <bool HasFront, std :: size_t ... Indices>
	 template <std :: size_t Index, std :: size_t Npos>
 struct isHeapUntillValue <Type, Operator, Values...> ::
	 Implementation <HasFront, indexSequence<Indices...> > :: Upper
 {
  constexpr const static std :: size_t value = Index;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <bool HasFront, std :: size_t ... Indices>
	 template <std :: size_t Npos>
 struct isHeapUntillValue <Type, Operator, Values...> ::
	 Implementation <HasFront, indexSequence<Indices...> > ::
	 Upper<Npos, Npos>
 {
  private:
  template <std :: size_t ... SubIndices>
	  using pass = typename isHeapUntillValue <Type, Operator, Values...> :: template
	  Implementation<false, indexSequence<SubIndices...> >;
  public:
  constexpr const static std :: size_t value =
	  bisectValue <std :: size_t, Indices...> :: template upper <pass> :: value;
 };
}

template <class Type, template <Type, Type> class Operator>
        inline constexpr crap :: isHeapUntillValue <Type, Operator> :: operator
        typename crap :: isHeapUntillValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: isHeapUntillValue <Type, Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator>
	inline constexpr typename crap :: isHeapUntillValue <Type, Operator> :: value_type
	crap :: isHeapUntillValue <Type, Operator> :: operator () () const noexcept
{
 return crap :: isHeapUntillValue <Type, Operator> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1>
        inline constexpr crap :: isHeapUntillValue <Type, Operator, Value1> :: operator
        typename crap :: isHeapUntillValue <Type, Operator, Value1> :: value_type () const noexcept
{
 return crap :: isHeapUntillValue <Type, Operator, Value1> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1>
	inline constexpr typename crap :: isHeapUntillValue <Type, Operator, Value1> :: value_type
	crap :: isHeapUntillValue <Type, Operator, Value1> :: operator () () const noexcept
{
 return crap :: isHeapUntillValue <Type, Operator, Value1> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
        inline constexpr crap :: isHeapUntillValue <Type, Operator, Value1, Value2> :: operator
        typename crap :: isHeapUntillValue <Type, Operator, Value1, Value2> :: value_type () const noexcept
{
 return crap :: isHeapUntillValue <Type, Operator, Value1, Value2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	inline constexpr typename crap :: isHeapUntillValue <Type, Operator, Value1, Value2> :: value_type
	crap :: isHeapUntillValue <Type, Operator, Value1, Value2> :: operator () () const noexcept
{
 return crap :: isHeapUntillValue <Type, Operator, Value1, Value2> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type ... Values>
        inline constexpr crap :: isHeapUntillValue <Type, Operator, Values...> :: operator
        typename crap :: isHeapUntillValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: isHeapUntillValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values>
	inline constexpr typename crap :: isHeapUntillValue <Type, Operator, Values...> :: value_type
	crap :: isHeapUntillValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: isHeapUntillValue <Type, Operator, Values...> :: value;
}
#endif
#endif

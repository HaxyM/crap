#ifndef CRAP_ALGORITHM_ISHEAPVALUE
#define CRAP_ALGORITHM_ISHEAPVALUE

#include "../utility.d/valuelist.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct isHeapValue;

 template <class Type, template <Type, Type> class Operator> struct isHeapValue<Type, Operator>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct isHeapValue<Type, Operator, Value>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct isHeapValue<Type, Operator, Value1, Value2>
 {
  constexpr const static bool value = !(Operator <Value1, Value2> :: value);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2, Type Value3>
	 struct isHeapValue<Type, Operator, Value1, Value2, Value3>
 {
  private:
  template <bool, class...> struct CheckRight;
  template <class ... Empty> struct CheckRight<true, Empty...>;
  template <class ... Empty> struct CheckRight<false, Empty...>;
  public:
  constexpr const static bool value = CheckRight <!(Operator <Value1, Value2> :: value)> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct isHeapValue
 {
  private:
  template <std :: size_t Index, bool LeftChildIn, bool RightChildIn> struct Implementation;
  template <std :: size_t Index> struct Implementation<Index, false, false>;
  template <std :: size_t Index> struct Implementation<Index, true, false>;
  template <std :: size_t Index> struct Implementation<Index, true, true>;
  public:
  constexpr const static bool value =
	  Implementation <0u, (1u < sizeof...(Values)), (2u < sizeof...(Values))> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2, Type Value3>
	 template <class ... Empty>
 struct isHeapValue <Type, Operator, Value1, Value2, Value3> :: CheckRight<true, Empty...>
 {
  constexpr const static bool value = !(Operator <Value1, Value3> :: value);
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2, Type Value3>
	 template <class ... Empty>
 struct isHeapValue <Type, Operator, Value1, Value2, Value3> :: CheckRight<false, Empty...>
 {
  constexpr const static bool value = false;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index>
 struct isHeapValue <Type, Operator, Values...> :: Implementation<Index, false, false>
 {
  constexpr const static bool value = true;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index>
 struct isHeapValue <Type, Operator, Values...> :: Implementation<Index, true, false>
 {
  private:
  constexpr const static Type parent =
	  valueList <Type, Values...> :: template At <Index> :: value;
  constexpr const static Type leftChild =
	  valueList <Type, Values...> :: template At <(2u * Index) + 1u> :: value;
  public:
  constexpr const static bool value = !(Operator <parent, leftChild> :: value);
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index>
 struct isHeapValue <Type, Operator, Values...> :: Implementation<Index, true, true>
 {
  private:
  constexpr const static Type parent =
	  valueList <Type, Values...> :: template At <Index> :: value;
  constexpr const static Type leftChild = 
	  valueList <Type, Values...> :: template At <(2u * Index) + 1u> :: value;
  template <bool, Type> struct CheckRight;
  template <Type Parent> struct CheckRight<true, Parent>;
  template <Type Parent> struct CheckRight<false, Parent>;
  template <bool, std :: size_t> struct CheckSubTree;
  template <std :: size_t SubIndex> struct CheckSubTree<true, SubIndex>;
  template <std :: size_t SubIndex> struct CheckSubTree<false, SubIndex>;
  constexpr const static bool rightFine =
	  CheckRight <!(Operator <parent, leftChild> :: value), parent> :: value;
  constexpr const static bool leftSubTreeFine =
	  CheckSubTree <rightFine, (2u * Index) + 1u> :: value;
  public:
  constexpr const static bool value =
	  CheckSubTree <leftSubTreeFine, (2u * Index) + 2u> :: value;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index>
	 template <Type Parent>
 struct isHeapValue <Type, Operator, Values...> ::
	Implementation <Index, true, true> ::
	CheckRight<true, Parent>
 {
  private:
  constexpr const static Type rightChild =
	  	  CheckRight <!(Operator <parent, leftChild> :: value), parent> :: value;
  public:
  constexpr const static bool value = !(Operator <Parent, rightChild> :: value);
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index>
	 template <Type Parent>
 struct isHeapValue <Type, Operator, Values...> ::
	Implementation <Index, true, true> ::
	CheckRight<false, Parent>
 {
  constexpr const static bool value = false;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index>
	 template <std :: size_t SubIndex>
 struct isHeapValue <Type, Operator, Values...> ::
	Implementation <Index, true, true> ::
	CheckSubTree<true, SubIndex>
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
 : isHeapValue <Type, Operator, Values...> :: template
#else
 : isHeapValue <Type, Operator, Values...> ::
#endif
	Implementation<SubIndex,
	(((2u * SubIndex) + 1u) < sizeof...(Values)),
	(((2u * SubIndex) + 2u) < sizeof...(Values))>
 {
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index>
	 template <std :: size_t SubIndex>
 struct isHeapValue <Type, Operator, Values...> ::
	Implementation <Index, true, true> ::
	CheckSubTree<false, SubIndex>
 {
  constexpr const static bool value = false;
 };
}

template <class Type, template <Type, Type> class Operator>
        inline constexpr crap :: isHeapValue <Type, Operator> :: operator
        typename crap :: isHeapValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: isHeapValue <Type, Operator> :: value;
}

template <class Type, template <Type, Type> class Operator, Type Value>
        inline constexpr crap :: isHeapValue <Type, Operator, Value> :: operator
        typename crap :: isHeapValue <Type, Operator, Value> :: value_type () const noexcept
{
 return crap :: isHeapValue <Type, Operator, Value> :: value;
}

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
        inline constexpr crap :: isHeapValue <Type, Operator, Value1, Value2> :: operator
        typename crap :: isHeapValue <Type, Operator, Value1, Value2> :: value_type () const noexcept
{
 return crap :: isHeapValue <Type, Operator, Value1, Value2> :: value;
}

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2, Type Value3>
        inline constexpr crap :: isHeapValue <Type, Operator, Value1, Value2, Value3> :: operator
        typename crap :: isHeapValue <Type, Operator, Value1, Value2, Value3> :: value_type () const noexcept
{
 return crap :: isHeapValue <Type, Operator, Value1, Value2, Value3> :: value;
}

template <class Type, template <Type, Type> class Operator, Type ... Values>
        inline constexpr crap :: isHeapValue <Type, Operator, Values...> :: operator
        typename crap :: isHeapValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: isHeapValue <Type, Operator, Values...> :: value;
}
#endif


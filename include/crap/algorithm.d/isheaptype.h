#ifndef CRAP_ALGORITHM_ISHEAPTYPE
#define CRAP_ALGORITHM_ISHEAPTYPE

#include "../utility.d/typelist.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <template <class, class> class, class...> struct isHeapType;

 template <template <class, class> class Operator> struct isHeapType<Operator>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type>
	 struct isHeapType<Operator, Type>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct isHeapType<Operator, Type1, Type2>
 {
  constexpr const static bool value = !(Operator <Type1, Type2> :: value);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type1, class Type2, class Type3>
	 struct isHeapType<Operator, Type1, Type2, Type3>
 {
  private:
  template <bool, class...> struct CheckRight;
  template <class ... Empty> struct CheckRight<true, Empty...>;
  template <class ... Empty> struct CheckRight<false, Empty...>;
  public:
  constexpr const static bool value =
	  CheckRight <!(Operator <Type1, Type2> :: value)> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class ... Types> struct isHeapType
 {
  private:
  template <std :: size_t Index, bool LeftChildIn, bool RightChildIn>
	  struct Implementation;
  template <std :: size_t Index> struct Implementation<Index, false, false>;
  template <std :: size_t Index> struct Implementation<Index, true, false>;
  template <std :: size_t Index> struct Implementation<Index, true, true>;
  public:
  constexpr const static bool value =
	  Implementation <0u, (1u < sizeof...(Types)), (2u < sizeof...(Types))> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type1, class Type2, class Type3>
	 template <class ... Empty>
 struct isHeapType <Operator, Type1, Type2, Type3> :: CheckRight<true, Empty...>
 {
  constexpr const static bool value = !(Operator <Type1, Type3> :: value);
 };

 template <template <class, class> class Operator, class Type1, class Type2, class Type3>
	 template <class ... Empty>
 struct isHeapType <Operator, Type1, Type2, Type3> :: CheckRight<false, Empty...>
 {
  constexpr const static bool value = false;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t Index>
 struct isHeapType <Operator, Types...> :: Implementation<Index, false, false>
 {
  constexpr const static bool value = true;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t Index>
 struct isHeapType <Operator, Types...> :: Implementation<Index, true, false>
 {
  private:
  using parent = typename typeList <Types...> :: template at<Index>;
  using leftChild =
	  typename typeList <Types...> :: template at<(2u * Index) + 1u>;
  public:
  constexpr const static bool value = !(Operator <parent, leftChild> :: value);
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t Index>
 struct isHeapType <Operator, Types...> :: Implementation<Index, true, true>
 {
  private:
  using parent = typename typeList <Types...> :: template at<Index>;
  using leftChild =
	  typename typeList <Types...> :: template at<(2u * Index) + 1u>;
  template <bool, class> struct CheckRight;
  template <class Parent> struct CheckRight<true, Parent>;
  template <class Parent> struct CheckRight<false, Parent>;
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

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t Index>
	 template <class Parent>
 struct isHeapType <Operator, Types...> ::
	Implementation <Index, true, true> ::
	CheckRight<true, Parent>
 {
  private:
  using rightChild =
	  	  typename typeList <Types...> :: template at<(2u * Index) + 2u>;
  public:
  constexpr const static bool value = !(Operator <Parent, rightChild> :: value);
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t Index>
	 template <class Parent>
 struct isHeapType <Operator, Types...> ::
	Implementation <Index, true, true> ::
	CheckRight<false, Parent>
 {
  constexpr const static bool value = false;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t Index>
	 template <std :: size_t SubIndex>
 struct isHeapType <Operator, Types...> ::
	Implementation <Index, true, true> ::
	CheckSubTree<true, SubIndex>
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
 : isHeapType <Operator, Types...> :: template
#else
 : isHeapType <Operator, Types...> ::
#endif
	Implementation<SubIndex,
	(((2u * SubIndex) + 1u) < sizeof...(Types)),
	(((2u * SubIndex) + 2u) < sizeof...(Types))>
 {
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t Index>
	 template <std :: size_t SubIndex>
 struct isHeapType <Operator, Types...> ::
	Implementation <Index, true, true> ::
	CheckSubTree<false, SubIndex>
 {
  constexpr const static bool value = false;
 };
}

template <template <class, class> class Operator>
        inline constexpr crap :: isHeapType <Operator> :: operator
        typename crap :: isHeapType <Operator> :: value_type () const noexcept
{
 return crap :: isHeapType <Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator>
	inline constexpr typename crap :: isHeapType <Operator> :: value_type
	crap :: isHeapType <Operator> :: operator () () const noexcept
{
 return crap :: isHeapType <Operator> :: value;
}
#endif

template <template <class, class> class Operator, class Type>
        inline constexpr crap :: isHeapType <Operator, Type> :: operator
        typename crap :: isHeapType <Operator, Type> :: value_type () const noexcept
{
 return crap :: isHeapType <Operator, Type> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type>
	inline constexpr typename crap :: isHeapType <Operator, Type> :: value_type
	crap :: isHeapType <Operator, Type> :: operator () () const noexcept
{
 return crap :: isHeapType <Operator, Type> :: value;
}
#endif

template <template <class, class> class Operator, class Type1, class Type2>
        inline constexpr crap :: isHeapType <Operator, Type1, Type2> :: operator
        typename crap :: isHeapType <Operator, Type1, Type2> :: value_type () const noexcept
{
 return crap :: isHeapType <Operator, Type1, Type2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type1, class Type2>
	inline constexpr typename crap :: isHeapType <Operator, Type1, Type2> :: value_type
	crap :: isHeapType <Operator, Type1, Type2> :: operator () () const noexcept
{
 return crap :: isHeapType <Operator, Type1, Type2> :: value;
}
#endif

template <template <class, class> class Operator, class Type1, class Type2, class Type3>
        inline constexpr crap :: isHeapType <Operator, Type1, Type2, Type3> :: operator
        typename crap :: isHeapType <Operator, Type1, Type2, Type3> :: value_type () const noexcept
{
 return crap :: isHeapType <Operator, Type1, Type2, Type3> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type1, class Type2, class Type3>
	inline constexpr typename crap :: isHeapType <Operator, Type1, Type2, Type3> :: value_type
	crap :: isHeapType <Operator, Type1, Type2, Type3> :: operator () () const noexcept
{
 return crap :: isHeapType <Operator, Type1, Type2, Type3> :: value;
}
#endif

template <template <class, class> class Operator, class ... Types>
        inline constexpr crap :: isHeapType <Operator, Types...> :: operator
        typename crap :: isHeapType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: isHeapType <Operator, Types...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class ... Types>
	inline constexpr typename crap :: isHeapType <Operator, Types...> :: value_type
	crap :: isHeapType <Operator, Types...> :: operator () () const noexcept
{
 return crap :: isHeapType <Operator, Types...> :: value;
}
#endif
#endif


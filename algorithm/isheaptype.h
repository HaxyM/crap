#ifndef CRAP_ALGORITHM_ISHEAPTYPE
#define CRAP_ALGORITHM_ISHEAPTYPE

#include "../utility/typelist.h"

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <template <class, class> class, class...> struct isHeapType;

 template <template <class, class> class Operator> struct isHeapType<Operator>
 {
  constexpr const static bool value = true;
 };

 template <template <class, class> class Operator, class First, class ... Rest>
	 struct isHeapType<Operator, First, Rest...>
 {
  private:
  constexpr const static std :: size_t size = sizeof...(Rest) + 1u;
  template <std :: size_t Index> using leftChildIndex = std :: integral_constant<std :: size_t, (2u * Index) + 1u>;
  template <std :: size_t Index> using rightChildIndex = std :: integral_constant<std :: size_t, (2u * Index) + 2u>;
  template <std :: size_t Index>
	  using leftChildIn = std :: integral_constant<bool, ((leftChildIndex <Index> :: value) < size)>;
  template <std :: size_t Index>
	  using rightChildIn = std :: integral_constant<bool, ((rightChildIndex <Index> :: value) < size)>;
  template <std :: size_t, class, bool, bool> struct checkSubHeap;
  template <std :: size_t Index, class Type> struct checkSubHeap<Index, Type, false, false>;
  template <std :: size_t Index, class Type> struct checkSubHeap<Index, Type, true, false>;
  template <std :: size_t Index, class Type> struct checkSubHeap<Index, Type, true, true>;
  template <std :: size_t, class, bool, bool> friend struct isHeapType <Operator, First, Rest...> :: checkSubHeap;
  public:
  constexpr const static bool value =
	  checkSubHeap <0u, First, leftChildIn <0u> :: value, rightChildIn <0u> :: value> :: value;
 };

 template <template <class, class> class Operator, class First, class ... Rest>
	 template <std :: size_t Index, class Type>
	struct isHeapType <Operator, First, Rest...> :: template checkSubHeap<Index, Type, false, false>
 {
  constexpr const static bool value = true;
 };

 template <template <class, class> class Operator, class First, class ... Rest>
	 template <std :: size_t Index, class Type>
	struct isHeapType <Operator, First, Rest...> :: template checkSubHeap<Index, Type, true, false>
 {
  private:
  using leftChild = typename typeList <First, Rest...> :: template at<(2u * Index) + 1u>;
  public:
  constexpr const static bool value = !(Operator <Type, leftChild> :: value);
 };

 template <template <class, class> class Operator, class First, class ... Rest>
	 template <std :: size_t Index, class Type>
	struct isHeapType <Operator, First, Rest...> :: template checkSubHeap<Index, Type, true, true>
 {
  private:
  constexpr const static std :: size_t rightChildIndex = (2u * Index) + 2u;
  constexpr const static std :: size_t leftChildIndex = (2u * Index) + 1u;
  using rightChild = typename typeList <First, Rest...> :: template at<rightChildIndex>;
  using leftChild = typename typeList <First, Rest...> :: template at<leftChildIndex>;
  constexpr const static bool childsOk =
	  !(Operator <Type, rightChild> :: value || Operator <Type, leftChild> :: value);
  constexpr const static bool checkRightRight =
	  isHeapType <Operator, First, Rest...> :: template rightChildIn <rightChildIndex> :: value && childsOk;
  constexpr const static bool checkRightLeft =
	  isHeapType <Operator, First, Rest...> :: template leftChildIn <rightChildIndex> :: value && childsOk;
  constexpr const static bool checkLeftRight =
	  isHeapType <Operator, First, Rest...> :: template rightChildIn <leftChildIndex> :: value && childsOk;
  constexpr const static bool checkLeftLeft =
	  isHeapType <Operator, First, Rest...> :: template leftChildIn <leftChildIndex> :: value && childsOk;
  constexpr const static bool rightBranchOk =
	  isHeapType <Operator, First, Rest...> :: template
	  checkSubHeap <rightChildIndex, rightChild, checkRightLeft, checkRightRight> :: value;
  constexpr const static bool leftBranchOk =
	  isHeapType <Operator, First, Rest...> :: template
	  checkSubHeap <leftChildIndex, rightChild, checkLeftLeft, checkLeftRight> :: value;
  public:
  constexpr const static bool value = childsOk && rightBranchOk && leftBranchOk;
 };
}
#endif


#ifndef CRAP_ALGORITHM_ISHEAPVALUE
#define CRAP_ALGORITHM_ISHEAPVALUE

#include "../utility.d/valuelist.h"
#include <type_traits>

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct isHeapValue;

 template <class Type, template <Type, Type> class Operator> struct isHeapValue<Type, Operator>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type First, Type ... Rest> struct isHeapValue<Type, Operator, First, Rest...>
 {
  private:
  using values = valueList<Type, First, Rest...>;
  template <std :: size_t Index> using leftChildIndex = std :: integral_constant<std :: size_t, (2u * Index) + 1u>;
  template <std :: size_t Index> using rightChildIndex = std :: integral_constant<std :: size_t, (2u * Index) + 2u>;
  template <std :: size_t Index> using leftChildIn = std :: integral_constant<bool, ((leftChildIndex <Index> :: value) < (values :: size))>;
  template <std :: size_t Index> using rightChildIn = std :: integral_constant<bool, ((rightChildIndex <Index> :: value) < (values :: size))>;
  template <std :: size_t Index, Type Value>
	  constexpr const static bool isHeap(std :: integral_constant<bool, false>, std :: integral_constant<bool, false>);
  template <std :: size_t Index, Type Value>
	  constexpr const static bool isHeap(std :: integral_constant<bool, true>, std :: integral_constant<bool, false>);
  template <std :: size_t Index, Type Value>
	  constexpr const static bool isHeap(std :: integral_constant<bool, true>, std :: integral_constant<bool, true>);
  public:
  constexpr const static bool value = isHeap<0u, First>(leftChildIn<0u>{}, rightChildIn<0u>{});
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <Type, Type> class Operator, Type First, Type ... Rest> template <std :: size_t Index, Type Value> constexpr const bool
crap :: isHeapValue <Type, Operator, First, Rest...> :: isHeap(std :: integral_constant<bool, false>, std :: integral_constant<bool, false>)
{
 return true;
}

template <class Type, template <Type, Type> class Operator, Type First, Type ... Rest> template <std :: size_t Index, Type Value> constexpr const bool
crap :: isHeapValue <Type, Operator, First, Rest...> :: isHeap(std :: integral_constant<bool, true>, std :: integral_constant<bool, false>)
{
 constexpr const std :: size_t leftIndex = crap :: isHeapValue <Type, Operator, First, Rest...> :: template leftChildIndex <Index> :: value;
 constexpr const Type leftChild = crap :: isHeapValue <Type, Operator, First, Rest...> :: values :: template At <leftIndex> :: value;
 return !(Operator <Value, leftChild> :: value);
}

template <class Type, template <Type, Type> class Operator, Type First, Type ... Rest> template <std :: size_t Index, Type Value> constexpr const bool
crap :: isHeapValue <Type, Operator, First, Rest...> :: isHeap(std :: integral_constant<bool, true>, std :: integral_constant<bool, true>)
{
 constexpr const std :: size_t rightIndex = crap :: isHeapValue <Type, Operator, First, Rest...> :: template rightChildIndex <Index> :: value;
 constexpr const std :: size_t leftIndex = crap :: isHeapValue <Type, Operator, First, Rest...> :: template leftChildIndex <Index> :: value;
 constexpr const Type rightChild = crap :: isHeapValue <Type, Operator, First, Rest...> :: values :: template At <rightIndex> :: value;
 constexpr const Type leftChild = crap :: isHeapValue <Type, Operator, First, Rest...> :: values :: template At <leftIndex> :: value;
 using rightRightIn = typename crap :: isHeapValue <Type, Operator, First, Rest...> :: template rightChildIn<rightIndex>;
 using rightLeftIn = typename crap :: isHeapValue <Type, Operator, First, Rest...> :: template leftChildIn<rightIndex>;
 using leftRightIn = typename crap :: isHeapValue <Type, Operator, First, Rest...> :: template rightChildIn<leftIndex>;
 using leftLeftIn = typename crap :: isHeapValue <Type, Operator, First, Rest...> :: template leftChildIn<leftIndex>;
 constexpr const bool rightChildNok = Operator <Value, rightChild> :: value;
 constexpr const bool leftChildNok = Operator <Value, leftChild> :: value;
 constexpr const bool childsOk = !(rightChildNok || leftChildNok);
 using rightRightBranch = std :: integral_constant<bool, (rightRightIn :: value) && childsOk>;
 using rightLeftBranch = std :: integral_constant<bool, (rightLeftIn :: value) && childsOk>;
 using leftRightBranch = std :: integral_constant<bool, (leftRightIn :: value) && childsOk>;
 using leftLeftBranch = std :: integral_constant<bool, (leftLeftIn :: value) && childsOk>;
 constexpr const bool rightBranchOk =
	 crap :: isHeapValue <Type, Operator, First, Rest...> :: template isHeap<rightIndex, rightChild>(rightLeftBranch{}, rightRightBranch{});
 constexpr const bool leftBranchOk =
	 crap :: isHeapValue <Type, Operator, First, Rest...> :: template isHeap<leftIndex, leftChild>(leftLeftBranch{}, leftRightBranch{});
 return childsOk && rightBranchOk && leftBranchOk;
}

template <class Type, template <Type, Type> class Operator>
        inline constexpr crap :: isHeapValue <Type, Operator> :: operator
        typename crap :: isHeapValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: isHeapValue <Type, Operator> :: value;
}

template <class Type, template <Type, Type> class Operator, Type First, Type ... Rest>
        inline constexpr crap :: isHeapValue <Type, Operator, First, Rest...> :: operator
        typename crap :: isHeapValue <Type, Operator, First, Rest...> :: value_type () const noexcept
{
 return crap :: isHeapValue <Type, Operator, First, Rest...> :: value;
}
#endif


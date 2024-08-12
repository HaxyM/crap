#ifndef CRAP_NUMERIC_MULSATVALUE
#define CRAP_NUMERIC_MULSATVALUE

#include <type_traits>

#include "../numbers.d/identity.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/accumulatevalue.h"

#include "../version.d/char8t.h"
#include "../version.d/libsaturationarithmetic.h"
#include "../version.d/unicodecharacters.h"

#if (crap_lib_saturation_arithmetic >= 202311L)
#include <numeric>
#else
#include <limits>
#endif

namespace crap
{
 template <class Type, Type...> struct mulSatValue;

 template <class Type>
	 struct mulSatValue<Type> : std :: integral_constant<Type, identity <Type> :: value>
 {
  static_assert((std :: is_integral <Type> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, bool> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char> :: value) &&
#if (crap_char8_t >= 201811L)
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char8_t> :: value) &&
#endif
#if (crap_unicode_characters >= 200704L)
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char16_t> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char32_t> :: value) &&
#endif
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, wchar_t> :: value),
		  "Unsupported type.");
 };

 template <class Type, Type Value>
	 struct mulSatValue<Type, Value> : std :: integral_constant<Type, Value>
 {
  static_assert((std :: is_integral <Type> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, bool> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char> :: value) &&
#if (crap_char8_t >= 201811L)
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char8_t> :: value) &&
#endif
#if (crap_unicode_characters >= 200704L)
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char16_t> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char32_t> :: value) &&
#endif
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, wchar_t> :: value),
		  "Unsupported type.");
 };

#if (crap_lib_saturation_arithmetic >= 202311L)
 template <class Type, Type Value1, Type Value2>
	 struct mulSatValue<Type, Value1, Value2>
	 : std :: integral_constatn<Type, std :: mul_sat(Value1, Value2)> {};
#else
 template <class Type, Type Value1, Type Value2> struct mulSatValue<Type, Value1, Value2>
 {
  static_assert((std :: is_integral <Type> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, bool> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char> :: value) &&
#if (crap_char8_t >= 201811L)
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char8_t> :: value) &&
#endif
#if (crap_unicode_characters >= 200704L)
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char16_t> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char32_t> :: value) &&
#endif
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, wchar_t> :: value),
		  "Unsupported type.");
  private:
  constexpr const static Type const0 = zero <Type> :: value;
  constexpr const static Type const1 = identity <Type> :: value;
  constexpr const static bool nonTrivial =
	  ((Value1 != const0) && (Value2 != const0) && (Value1 != const1) && (Value2 != const1));
  template <bool NonTrivial, bool Val1Neg, bool Val2Neg, class ... Empty> struct Implementation;
  template <class ... Empty> struct Implementation<true, true, true, Empty...>;
  template <class ... Empty> struct Implementation<true, true, false, Empty...>;
  template <class ... Empty> struct Implementation<true, false, true, Empty...>;
  template <class ... Empty> struct Implementation<true, false, false, Empty...>;
  template <bool Val1Neg, bool Val2Neg, class ... Empty>
	  struct Implementation<false, Val1Neg, Val2Neg, Empty...>;
  public:
  constexpr const static Type value =
	  Implementation <nonTrivial, (Value1 < const0), (Value2 < const0)> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
#endif

 template <class Type, Type ... Values> struct subSatValue
 {
  private:
  constexpr const static Type const0 = zero <Type> :: value;
  public:
  constexpr const static auto value = accumulateValue <Type, This, Values...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
#if (crap_lib_saturation_arithmetic >= 202311L)
#else

 template <class Type, Type Value1, Type Value2>
 template <class ... Empty>
	 struct mulSatValue <Type, Value1, Value2> :: template
	 Implementation<true, true, true, Empty...>
 {
  private:
  constexpr const static Type const0 = zero <Type> :: value;
  constexpr const static Type const1 = identity <Type> :: value;
  constexpr const static Type max = std :: numeric_limits <Type> :: max();
  constexpr const static Type min = std :: numeric_limits <Type> :: min();
  constexpr const static Type delta = (min + max);
  constexpr const static bool morePositive = (const0 < delta);
  //Largest value safe to have absolute value.
  constexpr const static Type constSecMax = (morePositive ? (max - delta) : max);
  constexpr const static Type constSecDelta = (morePositive ? delta : const0);
  constexpr const static Type d = (constSecMax / Value2);
  constexpr const static bool fracUnder1 = ((Value2 - (constSecMax % Value2)) < (constSecDelta % Value2));
  //This may fail iff Value1 is 0, but here it is not
  constexpr const static bool overflow =
	  ((constSecDelta / Value2) > (fracUnder1 ? (Value1 - d) : (Value1 - d - const1)));
  public:
  constexpr const static auto value = (overflow ? std :: numeric_limits <Type> :: min() : (Value1 * Value2));
 };

 template <class Type, Type Value1, Type Value2>
 template <class ... Empty>
	 struct mulSatValue <Type, Value1, Value2> :: template
	 Implementation<true, true, false, Empty...>
 {
  private:
  constexpr const static bool underflow = (Value1 < (std :: numeric_limits <Type> :: min() / Value2));
  public:
  constexpr const static auto value = (underflow ? std :: numeric_limits <Type> :: min() : (Value1 * Value2));
 };

 template <class Type, Type Value1, Type Value2>
 template <class ... Empty>
	 struct mulSatValue <Type, Value1, Value2> :: template
	 Implementation<true, false, true, Empty...>
 {
  private:
  constexpr const static bool underflow = (Value2 < (std :: numeric_limits <Type> :: min() / Value1));
  public:
  constexpr const static auto value = (underflow ? std :: numeric_limits <Type> :: min() : (Value1 * Value2));
 };

 template <class Type, Type Value1, Type Value2>
 template <class ... Empty>
	 struct mulSatValue <Type, Value1, Value2> :: template
	 Implementation<true, false, false, Empty...>
 {
  private:
  constexpr const static bool overflow = (Value1 > (std :: numeric_limits <Type> :: max() / Value2));
  public:
  constexpr const static auto value = (overflow ? std :: numeric_limits <Type> :: max() : (Value1 * Value2));
 };

 template <class Type, Type Value1, Type Value2>
 template <bool Val1Neg, bool Val2Neg, class ... Empty>
	 struct mulSatValue <Type, Value1, Value2> :: template
	 Implementation<false, Val1Neg, Val2Neg, Empty...>
 {
  constexpr const static auto value = (Value1 * Value2);
 };
#endif
}
#if (crap_lib_saturation_arithmetic >= 202311L)
#else

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: mulSatValue <Type, Value1, Value2> :: operator
typename crap :: mulSatValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: mulSatValue <Type, Value1, Value2> :: value;
}
#endif

template <class Type, Type ... Values>
inline constexpr crap :: subSatValue <Type, Values...> :: operator
typename crap :: subSatValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: subSatValue <Type, Values...> :: value;
}
#endif


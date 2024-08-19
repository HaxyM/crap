#ifndef CRAP_NUMERIC_DIVSATVALUE
#define CRAP_NUMERIC_DIVSATVALUE

#include <type_traits>

#include "../numbers.d/identity.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/accumulatevalue.h"

#include "../version.d/char8t.h"
#include "../version.d/libintegralconstantcallable.h"
#include "../version.d/libsaturationarithmetic.h"
#include "../version.d/unicodecharacters.h"

#if (crap_lib_saturation_arithmetic >= 202311L)
#include <numeric>
#else
#include <limits>
#endif

namespace crap
{
 template <class Type, Type...> struct divSatValue;

 template <class Type, Type Value>
	 struct divSatValue<Type, Value> : std :: integral_constant<Type, Value>
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
	 struct divSatValue<Type, Value1, Value2>
	 : std :: integral_constatn<Type, std :: div_sat(Value1, Value2)> {};
#else
 template <class Type, Type Value1, Type Value2> struct divSatValue<Type, Value1, Value2>
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
  static_assert(Value2 != zero <Type> :: value, "Division by zero!");
  private:
  constexpr const static Type const0 = zero <Type> :: value;
  constexpr const static Type max = std :: numeric_limits <Type> :: max();
  constexpr const static Type min = std :: numeric_limits <Type> :: min();
  constexpr const static Type delta = (min + max);
  constexpr const static signed int rangeShift = ((delta < const0) ? -1 : ((const0 < delta) ? 1 : 0));
  template <int RangeShift, bool Val1Neg, bool Val2Neg, class ... Empty> struct Implementation;
  template <class ... Empty> struct Implementation<1, true, true, Empty...>;
  template <class ... Empty> struct Implementation<1, false, true, Empty...>;
  template <class ... Empty> struct Implementation<-1, true, true, Empty...>;
  template <class ... Empty> struct Implementation<-1, false, true, Empty...>;
  template <bool Val1Neg, class ... Empty>
	  struct Implementation<0, Val1Neg, false, Empty...>;
  template <int RangeShift, bool Val1Neg, class ... Empty>
	  struct Implementation<RangeShift, Val1Neg, false, Empty...>;
  public:
  constexpr const static Type value =
	  Implementation <rangeShift, (Value1 < const0), (Value2 < const0)> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
#endif

 template <class Type, Type First, Type ... Rest> struct divSatValue<Type, First, Rest...>
 {
  private:
  template <Type ... SubValues> using This = divSatValue<Type, SubValues...>;
  public:
  constexpr const static auto value = accumulateValue <Type, This, First, Rest...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
#if (crap_lib_saturation_arithmetic >= 202311L)
#else

 template <class Type, Type Value1, Type Value2>
 template <class ... Empty>
	 struct divSatValue <Type, Value1, Value2> ::
	 Implementation<1, true, true, Empty...>
 {
  constexpr const static auto value = (Value1 / Value2);
 };

 template <class Type, Type Value1, Type Value2>
 template <class ... Empty>
	 struct divSatValue <Type, Value1, Value2> ::
	 Implementation<1, false, true, Empty...>
 {
  private:
  constexpr const static bool underflow = ((-std :: numeric_limits <Type> :: min()) < (Value1 / (-Value2)));
  public:
  constexpr const static auto value = (underflow ? std :: numeric_limits <Type> :: min() : (Value1 / Value2));
 };

 template <class Type, Type Value1, Type Value2>
 template <class ... Empty>
	 struct divSatValue <Type, Value1, Value2> ::
	 Implementation<-1, true, true, Empty...>
 {
  private:
  constexpr const static bool overflow = ((Value1 / std :: numeric_limits <Type> :: max()) < Value2);
  public:
  constexpr const static auto value = (overflow ? std :: numeric_limits <Type> :: max() : (Value1 / Value2));
 };

 template <class Type, Type Value1, Type Value2>
 template <class ... Empty>
	 struct divSatValue <Type, Value1, Value2> ::
	 Implementation<-1, false, true, Empty...>
 {
  constexpr const static auto value = (Value1 / Value2);
 };

 template <class Type, Type Value1, Type Value2>
 template <bool Val1Neg, class ... Empty>
	 struct divSatValue <Type, Value1, Value2> ::
	 Implementation<0, Val1Neg, true, Empty...>
 {
  constexpr const static auto value = (Value1 / Value2);
 };

 template <class Type, Type Value1, Type Value2>
 template <int RangeShift, bool Val1Neg, class ... Empty>
	 struct divSatValue <Type, Value1, Value2> ::
	 Implementation<RangeShift, Val1Neg, false, Empty...>
 {
  constexpr const static auto value = (Value1 / Value2);
 };
#endif
}
#if (crap_lib_saturation_arithmetic >= 202311L)
#else

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: divSatValue <Type, Value1, Value2> :: operator
typename crap :: divSatValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: divSatValue <Type, Value1, Value2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type Value1, Type Value2>
inline constexpr typename crap :: divSatValue <Type, Value1, Value2> :: value_type
crap :: divSatValue <Type, Value1, Value2> :: operator () () const noexcept
{
 return crap :: divSatValue <Type, Value1, Value2> :: value;
}
#endif
#endif

template <class Type, Type First, Type ... Rest>
inline constexpr crap :: divSatValue <Type, First, Rest...> :: operator
typename crap :: divSatValue <Type, First, Rest...> :: value_type () const noexcept
{
 return crap :: divSatValue <Type, First, Rest...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type First, Type ... Rest>
inline constexpr typename crap :: divSatValue <Type, First, Rest...> :: value_type
crap :: divSatValue <Type, First, Rest...> :: operator () () const noexcept
{
 return crap :: divSatValue <Type, First, Rest...> :: value;
}
#endif
#endif


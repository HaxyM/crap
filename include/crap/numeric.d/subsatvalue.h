#ifndef CRAP_NUMERIC_SUBSATVALUE
#define CRAP_NUMERIC_SUBSATVALUE

#include <type_traits>

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
 template <class Type, Type...> struct subSatValue;

 template <class Type>
	 struct subSatValue<Type> : std :: integral_constant<Type, zero <Type> :: value>
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
	 struct subSatValue<Type, Value> : std :: integral_constant<Type, Value>
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
	 struct subSatValue<Type, Value1, Value2>
	 : std :: integral_constatn<Type, std :: sub_sat(Value1, Value2)> {};
#else
 template <class Type, Type Value1, Type Value2> struct subSatValue<Type, Value1, Value2>
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
  constexpr const static bool underflow =
	  ((Value2 > (zero <Type> :: value)) ?
	   (Value1 < (std :: numeric_limits <Type> :: min() + Value2)) : false);
  constexpr const static bool overflow =
	  ((Value2 < (zero <Type> :: value)) ?
	   (Value1 > (std :: numeric_limits <Type> :: max() + Value2)) : false);
  public:
  constexpr const static Type value =
	  (underflow ?
	   std :: numeric_limits <Type> :: min() :
	   (overflow ? std :: numeric_limits <Type> :: max() : (Value1 - Value2)));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
#endif

 template <class Type, Type ... Values> struct subSatValue
 {
  private:
  template <Type ... SubValues> using This = subSatValue<Type, SubValues...>;
  public:
  constexpr const static auto value = accumulateValue <Type, This, Values...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}
#if (crap_lib_saturation_arithmetic >= 202311L)
#else

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: subSatValue <Type, Value1, Value2> :: operator
typename crap :: subSatValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: subSatValue <Type, Value1, Value2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type Value1, Type Value2>
inline constexpr typename crap :: subSatValue <Type, Value1, Value2> :: value_type
crap :: subSatValue <Type, Value1, Value2> :: operator () () const noexcept
{
 return crap :: subSatValue <Type, Value1, Value2> :: value;
}
#endif
#endif

template <class Type, Type ... Values>
inline constexpr crap :: subSatValue <Type, Values...> :: operator
typename crap :: subSatValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: subSatValue <Type, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type ... Values>
inline constexpr typename crap :: subSatValue <Type, Values...> :: value_type
crap :: subSatValue <Type, Values...> :: operator () () const noexcept
{
 return crap :: subSatValue <Type, Values...> :: value;
}
#endif
#endif


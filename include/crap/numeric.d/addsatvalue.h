#ifndef CRAP_NUMERIC_ADDSATVALUE
#define CRAP_NUMERIC_ADDSATVALUE

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
 template <class Type, Type...> struct addSatValue;

 template <class Type>
	 struct addSatValue<Type> : std :: integral_constant<Type, zero <Type> :: value>
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
	 struct addSatValue<Type, Value> : std :: integral_constant<Type, Value>
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
	 struct addSatValue<Type, Value1, Value2>
	 : std :: integral_constatn<Type, std :: add_sat(Value1, Value2)> {};
#else
 template <class Type, Type Value1, Type Value2> struct addSatValue<Type, Value1, Value2>
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
	  ((Value1 < (zero <Type> :: value)) ?
	   (Value2 < (std :: numeric_limits <Type> :: min() - Value1)) : false);
  constexpr const static bool overflow =
	  ((Value1 > (zero <Type> :: value)) ?
	   (Value2 > (std :: numeric_limits <Type> :: max() - Value1)) : false);
  public:
  constexpr const static Type value =
	  (underflow ?
	   std :: numeric_limits <Type> :: min() :
	   (overflow ? std :: numeric_limits <Type> :: max() : (Value1 + Value2)));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type ... Values> struct addSatValue
 {
  private:
  template <Type ... SubValues> using This = addSatValue<Type, SubValues...>;
  public:
  constexpr const static auto value = accumulateValue <Type, This, Values...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
#endif
}
#if (crap_lib_saturation_arithmetic >= 202311L)
#else

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: addSatValue <Type, Value1, Value2> :: operator
typename crap :: addSatValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: addSatValue <Type, Value1, Value2> :: value;
}
#endif

template <class Type, Type ... Values>
inline constexpr crap :: addSatValue <Type, Values...> :: operator
typename crap :: addSatValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: addSatValue <Type, Values...> :: value;
}
#endif


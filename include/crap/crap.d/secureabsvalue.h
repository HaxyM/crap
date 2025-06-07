#ifndef CRAP_CRAP_SECUREABSVALUE
#define CRAP_CRAP_SECUREABSVALUE

#include <limits>
#include <type_traits>

#include "../numbers.d/zero.h"
#include "../utility.d/cmplessequalvalue.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, Type Value> struct secureAbsValue
 {
  using value_type = typename std :: make_unsigned <Type> :: type;
  private:
  constexpr const static Type min = std :: numeric_limits <Type> :: min();
  constexpr const static Type max = std :: numeric_limits <Type> :: max();
  constexpr const static value_type umax = std :: numeric_limits <value_type> :: max();
  static_assert(cmpLessEqualValue <Type, max, value_type, umax> :: value,
 		 "Unsigned type may not be able to store result.");
  constexpr const static bool moreNegative = ((min + max) < zero <Type> :: value);
  template <bool Signed, bool MoreNrgative, class ... Empty> struct Implementation;
  template <class ... Empty> struct Implementation<true, true, Empty...>;
  template <class ... Empty> struct Implementation<true, false, Empty...>;
  template <bool MoreNegative, class ... Empty> struct Implementation<false, MoreNegative, Empty...>;
  public:
  constexpr const static value_type value =
 	 Implementation <std :: is_signed <Type> :: value, moreNegative> :: value;
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, Type Value>
	 template <class ... Empty>
 struct secureAbsValue <Type, Value> :: template
	 Implementation<true, true, Empty...>
 {
  private:
  template <bool BelowMax, class ... Empty2> struct small;
  template <class ... Empty2> struct small<true, Empty2...>;
  template <class ... Empty2> struct small<false, Empty2...>;
  constexpr const static bool isBelowMax = (Value < -(std :: numeric_limits <Type> :: max()));
  public:
  constexpr const static typename std :: make_unsigned <Type> :: type value = small <isBelowMax> :: value;
 };

 template <class Type, Type Value>
	 template <class ... Empty>
 struct secureAbsValue <Type, Value> :: template
	 Implementation<true, false, Empty...>
 {
  using vale_type = typename std :: make_unsigned <Type> :: type;
  constexpr const static value_type value = ((Value < zero <Type> :: value) ? (-Value) : Value);
 };

 template <class Type, Type Value>
	 template <bool MoreNegative, class ... Empty>
 struct secureAbsValue <Type, Value> :: template
	 Implementation<false, MoreNegative, Empty...>
 {
  constexpr const static typename std :: make_unsigned <Type> :: type value = Value;
 };

 template <class Type, Type Value>
	 template <class ... Empty>
	 template <class ... Empty2>
 struct secureAbsValue <Type, Value> :: template
	 Implementation <true, true, Empty...> :: template small<true, Empty2...>
 {
  private:
  using value_type = typename std :: make_unsigned <Type> :: type;
  constexpr const static value_type signedMax =
	  static_cast<value_type>(std :: numeric_limits <Type> :: max());
  constexpr const static value_type unsignedMax =
	  std :: numeric_limits <value_type> :: max();
  static_assert(zero <value_type> :: value <= signedMax, "Must have posistive vales.");
  constexpr const static Type diff = Value + std :: numeric_limits <Type> :: max();
  static_assert((-static_cast<Type>(signedMax)) < diff, "Value very small.");
  static_assert(signedMax <= (unsignedMax + diff), "Result out of range");
  public:
  constexpr const static value_type value = signedMax + static_cast<value_type>(-diff);
 };

 template <class Type, Type Value>
	 template <class ... Empty>
	 template <class ... Empty2>
 struct secureAbsValue <Type, Value> :: template
	 Implementation <true, true, Empty...> :: template small<false, Empty2...>
 {
  using vale_type = typename std :: make_unsigned <Type> :: type;
  constexpr const static value_type value = ((Value < zero <Type> :: value) ? -Value : Value);
 };
}

template <class Type, Type Value>
inline constexpr crap :: secureAbsValue <Type, Value> :: operator
typename crap :: secureAbsValue <Type, Value> :: value_type () const noexcept
{
 return crap :: secureAbsValue <Type, Value> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type Value>
inline constexpr typename crap :: secureAbsValue <Type, Value> :: value_type
crap :: secureAbsValue <Type, Value> :: operator () () const noexcept
{
 return crap :: secureAbsValue <Type, Value> :: value;
}
#endif
#endif

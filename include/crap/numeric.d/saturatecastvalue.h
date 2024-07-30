#ifndef CRAP_UTILITY_SATURATECASTVALUE
#define CRAP_UTILITY_SATURATECASTVALUE

#include "../utility.d/cmpgreatervalue.h"
#include "../utility.d/cmplessvalue.h"
#include "../version.d/libsaturationarithmetic.h"

#if (crap_lib_saturation_arithmetic >= 202311L)
#include <numeric>
#else
#include <limits>
#include <type_traits>
#endif

namespace crap
{
#if (crap_lib_saturation_arithmetic >= 202311L)
 template <class TypeToFitIn, class Type, Type Value>
	 struct saturateCastValue
	 : std :: integral_constatn<TypeToFitIn, std :: saturate_cast<TypeToFitIn>(Value)> {};
#else
 template <class TypeToFitIn, class Type, Type Value> struct saturateCastValue
 {
  static_assert((std :: is_integral <Type> :: value), "Unsupported type.");
  private:
  constexpr const static bool underflow =
	  cmpLessValue <Type, Value, TypeToFitIn, std :: numeric_limits <TypeToFitIn> :: min()> :: value;
  constexpr const static bool overflow =
	  cmpGreaterValue <Type, Value, TypeToFitIn, std :: numeric_limits <TypeToFitIn> :: max()> :: value;
  public:
  constexpr const static TypeToFitIn value =
	  (underflow ?
	   std :: numeric_limits <TypeToFitIn> :: min() :
	   (overflow ? std :: numeric_limits <TypeToFitIn> :: max() :
	    static_cast<TypeToFitIn>(Value)));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
#endif
}
#if (crap_lib_saturation_arithmetic >= 202311L)
#else

template <class TypeToFitIn, class Type, Type Value>
inline constexpr crap :: saturateCastValue <TypeToFitIn, Type, Value> :: operator
typename crap :: saturateCastValue <TypeToFitIn, Type, Value> :: value_type () const noexcept
{
 return crap :: saturateCastValue <TypeToFitIn, Type, Value> :: value;
}
#endif
#endif


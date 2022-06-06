#ifndef CRAP_UTILITY_FRONTVALUE
#define CRAP_UTILITY_FRONTVALUE

namespace crap
{
 template <class Type, Type...> struct frontValue;

 template <class Type, Type First, Type ... Rest> struct frontValue<Type, First, Rest...>
 {
  constexpr const static Type value = First;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type ... Values> struct frontValue
 {
  static_assert(sizeof...(Values) != 0u, "Collection must not be empty.");
 };
}

template <class Type, Type Front, Type ... Rest>
	inline constexpr crap :: frontValue <Type, Front, Rest...> :: operator
	typename crap :: frontValue <Type, Front, Rest...> :: value_type () const noexcept
{
 return crap :: frontValue <Type, Front, Rest...> :: value;
};
#endif

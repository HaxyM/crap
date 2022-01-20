#ifndef CRAP_STRING_STRING
#define CRAP_STRING_STRING

#include "../utility.d/valuelist.h"

namespace crap
{
 template <class Char, Char ... Letters> struct string : valueList<Char, Letters...>
 {
  private:
  constexpr const static Char letters[sizeof...(Letters) + 1u] = {Letters..., static_cast<Char>('\0')};
  public:
  constexpr const static Char (& c_str() noexcept)[sizeof...(Letters) + 1u];
 };

 template <class Char, Char ... Letters> constexpr string<Char, Letters...> operator "" _string () noexcept;
}

template <class Char, Char ... Letters>
constexpr const Char crap :: string <Char, Letters...> :: letters[sizeof...(Letters) + 1u];

template <class Char, Char ... Letters> inline constexpr const Char (& crap :: string <Char, Letters...> :: c_str() noexcept)[sizeof...(Letters) + 1u]
{
 return crap :: string <Char, Letters...> :: letters;
}

template <class Char, Char ... Letters> inline constexpr crap :: string<Char, Letters...> crap :: operator "" _string () noexcept
{
 return {};
}
#endif


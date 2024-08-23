#ifndef CRAP_LOCALE_NUMPUNCT
#define CRAP_LOCALE_NUMPUNCT

#include <type_traits>

#include "../string.d/string.h"

namespace crap
{
 template <class> struct numpunct;

 template <> struct numpunct <char>
 { //Defaults for C standard.
  using char_type = char;
  template <char_type ... Chars> using string_type =  string<char_type, Chars...>;
  using decimalPoint_t = std :: integral_constant<char, '.'>;
  using thousandsSep_t = std :: integral_constant<char, ','>;
  using grouping_t = string<char>;
  using truename_t = string<char, 't', 'r', 'u', 'e'>;
  using falsename_t = string<char, 'f', 'a', 'l', 's', 'e'>;
  constexpr decimalPoint_t decimalPoint() const noexcept;
  constexpr thousandsSep_t thousandsSep() const noexcept;
  constexpr grouping_t grouping() const noexcept;
  constexpr truename_t truename() const noexcept;
  constexpr falsename_t falsename() const noexcept;
 };

 template <> struct numpunct <wchar_t>
 { //Defaults for C standard.
  using char_type = wchar_t;
  template <char_type ... Chars> using string_type =  string<char_type, Chars...>;
  using decimalPoint_t = std :: integral_constant<wchar_t, L'.'>;
  using thousandsSep_t = std :: integral_constant<wchar_t, L','>;
  using grouping_t = string<wchar_t>;
  using truename_t = string<wchar_t, L't', L'r', L'u', L'e'>;
  using falsename_t = string<wchar_t, L'f', L'a', L'l', L's', L'e'>;
  constexpr decimalPoint_t decimalPoint() const noexcept;
  constexpr thousandsSep_t thousandsSep() const noexcept;
  constexpr grouping_t grouping() const noexcept;
  constexpr truename_t truename() const noexcept;
  constexpr falsename_t falsename() const noexcept;
 };
}

inline constexpr typename crap :: numpunct <char> :: decimalPoint_t
crap :: numpunct <char> :: decimalPoint() const noexcept
{
 return {};
}

inline constexpr typename crap :: numpunct <char> :: thousandsSep_t
crap :: numpunct <char> :: thousandsSep() const noexcept
{
 return {};
}

inline constexpr typename crap :: numpunct <char> :: grouping_t
crap :: numpunct <char> :: grouping() const noexcept
{
 return {};
}

inline constexpr typename crap :: numpunct <char> :: truename_t
crap :: numpunct <char> :: truename() const noexcept
{
 return {};
}

inline constexpr typename crap :: numpunct <char> :: falsename_t
crap :: numpunct <char> :: falsename() const noexcept
{
 return {};
}

inline constexpr typename crap :: numpunct <wchar_t> :: decimalPoint_t
crap :: numpunct <wchar_t> :: decimalPoint() const noexcept
{
 return {};
}

inline constexpr typename crap :: numpunct <wchar_t> :: thousandsSep_t
crap :: numpunct <wchar_t> :: thousandsSep() const noexcept
{
 return {};
}

inline constexpr typename crap :: numpunct <wchar_t> :: grouping_t
crap :: numpunct <wchar_t> :: grouping() const noexcept
{
 return {};
}

inline constexpr typename crap :: numpunct <wchar_t> :: truename_t
crap :: numpunct <wchar_t> :: truename() const noexcept
{
 return {};
}

inline constexpr typename crap :: numpunct <wchar_t> :: falsename_t
crap :: numpunct <wchar_t> :: falsename() const noexcept
{
 return {};
}
#endif


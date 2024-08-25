#ifndef CRAP_LOCALE_MONEYPUNCT
#define CRAP_LOCALE_MONEYPUNCT

#include <locale>
#include <type_traits>

#include "../string.d/string.h"
#include "../utility.d/valuelist.h"

namespace crap
{
 template <class, bool> struct moneypunct;

 template <bool International> struct moneypunct <char, International>
 { //Defaults for C standard.
  using char_type = char;
  template <char_type ... Chars> using string_type =  string<char_type, Chars...>;
  using decimalPoint_t = std :: integral_constant<char_type, '.'>;
  using thousandsSep_t = std :: integral_constant<char_type, ','>;
  using grouping_t = string<char_type>;
  using currSymbol_t = string<char_type>;
  using fracDigits_t = std :: integral_constants<int, 0>;
  using positiveSign_t = string<char_type>;
  using negativeSign_t = string<char_type>;
  using posFormat_t = valueList<std :: money_base :: part,
	  std :: money_base :: part :: symbol,
	  std :: money_base :: part :: sign,
	  std :: money_base :: part :: none,
	  std :: money_base :: part :: value>;
  using negFormat_t = valueList<std :: money_base :: part,
	  std :: money_base :: part :: symbol,
	  std :: money_base :: part :: sign,
	  std :: money_base :: part :: none,
	  std :: money_base :: part :: value>;
  constexpr decimalPoint_t decimalPoint() const noexcept;
  constexpr thousandsSep_t thousandsSep() const noexcept;
  constexpr grouping_t grouping() const noexcept;
  constexpr currSymbol_t curr_symbol() const noexcept;
  constexpr fracDigits_t frac_digits() const noexcept;
  constexpr positiveSign_t positive_sign() const noexcept;
  constexpr negativeSign_t negative_sign() const noexcept;
  constexpr posFormat_t pos_format() const noexcept;
  constexpr negFormat_t neg_format() const noexcept;
 };

 template <bool International> struct moneypunct <wchar_t, International>
 { //Defaults for C standard.
  using char_type = wchar_t;
  template <char_type ... Chars> using string_type =  string<char_type, Chars...>;
  using decimalPoint_t = std :: integral_constant<char_type, L'.'>;
  using thousandsSep_t = std :: integral_constant<char_type, L','>;
  using grouping_t = string<char_type>;
  using currSymbol_t = string<char_type>;
  using fracDigits_t = std :: integral_constants<int, 0>;
  using positiveSign_t = string<char_type>;
  using negativeSign_t = string<char_type>;
  using posFormat_t = valueList<std :: money_base :: part,
	  std :: money_base :: part :: symbol,
	  std :: money_base :: part :: sign,
	  std :: money_base :: part :: none,
	  std :: money_base :: part :: value>;
  using negFormat_t = valueList<std :: money_base :: part,
	  std :: money_base :: part :: symbol,
	  std :: money_base :: part :: sign,
	  std :: money_base :: part :: none,
	  std :: money_base :: part :: value>;
  constexpr decimalPoint_t decimalPoint() const noexcept;
  constexpr thousandsSep_t thousandsSep() const noexcept;
  constexpr grouping_t grouping() const noexcept;
  constexpr currSymbol_t curr_symbol() const noexcept;
  constexpr fracDigits_t frac_digits() const noexcept;
  constexpr positiveSign_t positive_sign() const noexcept;
  constexpr negativeSign_t negative_sign() const noexcept;
  constexpr posFormat_t pos_format() const noexcept;
  constexpr negFormat_t neg_format() const noexcept;
 };
}

template <bool International>
inline constexpr typename crap :: moneypunct <char, International> :: decimalPoint_t
crap :: moneypunct <char, International> :: decimalPoint() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <char, International> :: thousandsSep_t
crap :: moneypunct <char, International> :: thousandsSep() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <char, International> :: grouping_t
crap :: moneypunct <char, International> :: grouping() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <char, International> :: currSymbol_t
crap :: moneypunct <char, International> :: currSymbol() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <char, International> :: fracDigits_t
crap :: moneypunct <char, International> :: fracDigits() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <char, International> :: positiveSign_t
crap :: moneypunct <char, International> :: positiveSign() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <char, International> :: negativeSign_t
crap :: moneypunct <char, International> :: negativeSign() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <char, International> :: posFormat_t
crap :: moneypunct <char, International> :: posFormat() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <char, International> :: negFormat_t
crap :: moneypunct <char, International> :: negFormat() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <wchar_t, International> :: decimalPoint_t
crap :: moneypunct <wchar_t, International> :: decimalPoint() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <wchar_t, International> :: thousandsSep_t
crap :: moneypunct <wchar_t, International> :: thousandsSep() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <wchar_t, International> :: grouping_t
crap :: moneypunct <wchar_t, International> :: grouping() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <wchar_t, International> :: currSymbol_t
crap :: moneypunct <wchar_t, International> :: currSymbol() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <wchar_t, International> :: fracDigits_t
crap :: moneypunct <wchar_t, International> :: fracDigits() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <wchar_t, International> :: positiveSign_t
crap :: moneypunct <wchar_t, International> :: positiveSign() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <wchar_t, International> :: negativeSign_t
crap :: moneypunct <wchar_t, International> :: negativeSign() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <wchar_t, International> :: posFromat_t
crap :: moneypunct <wchar_t, International> :: posFormat() const noexcept
{
 return {};
}

template <bool International>
inline constexpr typename crap :: moneypunct <wchar_t, International> :: negFormat_t
crap :: moneypunct <wchar_t, International> :: negFormat() const noexcept
{
 return {};
}
#endif


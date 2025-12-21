#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_HPROMAN8TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_HPROMAN8TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_HPRoman8_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: HPRoman8>;

 template <>
 struct textEncodingType<text_encoding_id_HPRoman8_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_HPRoman8_t;
  using name = string<char, 'h', 'p', '-', 'r', 'o', 'm', 'a', 'n', '8'>;
  using aliases = typeList<
      string<char, 'h', 'p', '-', 'r', 'o', 'm', 'a', 'n', '8'>,
      string<char, 'r', 'o', 'm', 'a', 'n', '8'>,
      string<char, 'r', '8'>,
      string<char, 'c', 's', 'H', 'P', 'R', 'o', 'm', 'a', 'n', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'H', 'P', 'R', 'o', 'm', 'a', 'n', '8'> >
 : textEncodingType<text_encoding_id_HPRoman8_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'h', 'p', '-', 'r', 'o', 'm', 'a', 'n', '8'> >
 : textEncodingType<text_encoding_id_HPRoman8_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'r', '8'> >
 : textEncodingType<text_encoding_id_HPRoman8_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'r', 'o', 'm', 'a', 'n', '8'> >
 : textEncodingType<text_encoding_id_HPRoman8_t>
 {
 };
}
#endif

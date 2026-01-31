#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM290TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM290TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM290_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM290>;

 template <>
 struct textEncodingType<text_encoding_id_IBM290_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM290_t;
  using name = string<char, 'I', 'B', 'M', '2', '9', '0'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '2', '9', '0'>,
      string<char, 'c', 'p', '2', '9', '0'>,
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'J', 'P', '-', 'k', 'a', 'n', 'a'>,
      string<char, 'c', 's', 'I', 'B', 'M', '2', '9', '0'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '2', '9', '0'> >
 : textEncodingType<text_encoding_id_IBM290_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '2', '9', '0'> >
 : textEncodingType<text_encoding_id_IBM290_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'J', 'P', '-', 'k', 'a', 'n', 'a'> >
 : textEncodingType<text_encoding_id_IBM290_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '2', '9', '0'> >
 : textEncodingType<text_encoding_id_IBM290_t>
 {
 };
}
#endif

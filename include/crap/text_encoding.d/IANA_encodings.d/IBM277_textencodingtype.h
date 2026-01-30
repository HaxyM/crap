#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM277TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM277TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM277_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM277>;

 template <>
 struct textEncodingType<text_encoding_id_IBM277_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM277_t;
  using name = string<char, 'I', 'B', 'M', '2', '7', '7'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '2', '7', '7'>,
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'C', 'P', '-', 'D', 'K'>,
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'C', 'P', '-', 'N', 'O'>,
      string<char, 'c', 's', 'I', 'B', 'M', '2', '7', '7'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '2', '7', '7'> >
 : textEncodingType<text_encoding_id_IBM277_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'C', 'P', '-', 'D', 'K'> >
 : textEncodingType<text_encoding_id_IBM277_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'C', 'P', '-', 'N', 'O'> >
 : textEncodingType<text_encoding_id_IBM277_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '2', '7', '7'> >
 : textEncodingType<text_encoding_id_IBM277_t>
 {
 };
}
#endif

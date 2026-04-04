#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM857TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM857TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM857_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM857>;

 template <>
 struct textEncodingType<text_encoding_id_IBM857_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM857_t;
  using name = string<char, 'I', 'B', 'M', '8', '5', '7'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '5', '7'>,
      string<char, 'c', 'p', '8', '5', '7'>,
      string<char, '8', '5', '7'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '5', '7'> >;
 };

 template <>
 struct textEncodingType<string<char, '8', '5', '7'> >
 : textEncodingType<text_encoding_id_IBM857_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '5', '7'> >
 : textEncodingType<text_encoding_id_IBM857_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '5', '7'> >
 : textEncodingType<text_encoding_id_IBM857_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '5', '7'> >
 : textEncodingType<text_encoding_id_IBM857_t>
 {
 };
}
#endif

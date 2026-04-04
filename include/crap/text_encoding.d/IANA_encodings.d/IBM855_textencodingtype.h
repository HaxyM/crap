#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM855TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM855TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM855_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM855>;

 template <>
 struct textEncodingType<text_encoding_id_IBM855_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM855_t;
  using name = string<char, 'I', 'B', 'M', '8', '5', '5'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '5', '5'>,
      string<char, 'c', 'p', '8', '5', '5'>,
      string<char, '8', '5', '5'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '5', '5'> >;
 };

 template <>
 struct textEncodingType<string<char, '8', '5', '5'> >
 : textEncodingType<text_encoding_id_IBM855_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '5', '5'> >
 : textEncodingType<text_encoding_id_IBM855_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '5', '5'> >
 : textEncodingType<text_encoding_id_IBM855_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '5', '5'> >
 : textEncodingType<text_encoding_id_IBM855_t>
 {
 };
}
#endif

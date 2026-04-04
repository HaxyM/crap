#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM860TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM860TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM860_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM860>;

 template <>
 struct textEncodingType<text_encoding_id_IBM860_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM860_t;
  using name = string<char, 'I', 'B', 'M', '8', '6', '0'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '6', '0'>,
      string<char, 'c', 'p', '8', '6', '0'>,
      string<char, '8', '6', '0'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '0'> >;
 };

 template <>
 struct textEncodingType<string<char, '8', '6', '0'> >
 : textEncodingType<text_encoding_id_IBM860_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '6', '0'> >
 : textEncodingType<text_encoding_id_IBM860_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '0'> >
 : textEncodingType<text_encoding_id_IBM860_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '6', '0'> >
 : textEncodingType<text_encoding_id_IBM860_t>
 {
 };
}
#endif

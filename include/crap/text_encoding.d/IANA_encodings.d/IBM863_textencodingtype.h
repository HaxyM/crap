#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM863TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM863TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM863_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM863>;

 template <>
 struct textEncodingType<text_encoding_id_IBM863_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM863_t;
  using name = string<char, 'I', 'B', 'M', '8', '6', '3'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '6', '3'>,
      string<char, 'c', 'p', '8', '6', '3'>,
      string<char, '8', '6', '3'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '3'> >;
 };

 template <>
 struct textEncodingType<string<char, '8', '6', '3'> >
 : textEncodingType<text_encoding_id_IBM863_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '6', '3'> >
 : textEncodingType<text_encoding_id_IBM863_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '3'> >
 : textEncodingType<text_encoding_id_IBM863_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '6', '3'> >
 : textEncodingType<text_encoding_id_IBM863_t>
 {
 };
}
#endif

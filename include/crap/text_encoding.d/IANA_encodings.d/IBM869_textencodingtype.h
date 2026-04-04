#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM869TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM869TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM869_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM869>;

 template <>
 struct textEncodingType<text_encoding_id_IBM869_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM869_t;
  using name = string<char, 'I', 'B', 'M', '8', '6', '9'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '6', '9'>,
      string<char, 'c', 'p', '8', '6', '9'>,
      string<char, '8', '6', '9'>,
      string<char, 'c', 'p', '-', 'g', 'r'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '9'> >;
 };

 template <>
 struct textEncodingType<string<char, '8', '6', '9'> >
 : textEncodingType<text_encoding_id_IBM869_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '-', 'g', 'r'> >
 : textEncodingType<text_encoding_id_IBM869_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '6', '9'> >
 : textEncodingType<text_encoding_id_IBM869_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '9'> >
 : textEncodingType<text_encoding_id_IBM869_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '6', '9'> >
 : textEncodingType<text_encoding_id_IBM869_t>
 {
 };
}
#endif

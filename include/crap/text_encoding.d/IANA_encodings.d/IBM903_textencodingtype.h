#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM903TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM903TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM903_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM903>;

 template <>
 struct textEncodingType<text_encoding_id_IBM903_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM903_t;
  using name = string<char, 'I', 'B', 'M', '9', '0', '3'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '9', '0', '3'>,
      string<char, 'c', 'p', '9', '0', '3'>,
      string<char, 'c', 's', 'I', 'B', 'M', '9', '0', '3'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '9', '0', '3'> >
 : textEncodingType<text_encoding_id_IBM903_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '9', '0', '3'> >
 : textEncodingType<text_encoding_id_IBM903_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '9', '0', '3'> >
 : textEncodingType<text_encoding_id_IBM903_t>
 {
 };
}
#endif

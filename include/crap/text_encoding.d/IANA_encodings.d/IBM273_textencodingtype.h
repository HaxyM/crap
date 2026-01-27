#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM273TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM273TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM273_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM273>;

 template <>
 struct textEncodingType<text_encoding_id_IBM273_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM273_t;
  using name = string<char, 'I', 'B', 'M', '2', '7', '3'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '2', '7', '3'>,
      string<char, 'C', 'P', '2', '7', '3'>,
      string<char, 'c', 's', 'I', 'B', 'M', '2', '7', '3'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '2', '7', '3'> >
 : textEncodingType<text_encoding_id_IBM273_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '2', '7', '3'> >
 : textEncodingType<text_encoding_id_IBM273_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '2', '7', '3'> >
 : textEncodingType<text_encoding_id_IBM273_t>
 {
 };
}
#endif

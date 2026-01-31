#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM281TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM281TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM281_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM281>;

 template <>
 struct textEncodingType<text_encoding_id_IBM281_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM281_t;
  using name = string<char, 'I', 'B', 'M', '2', '8', '1'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '2', '8', '1'>,
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'J', 'P', '-', 'E'>,
      string<char, 'c', 'p', '2', '8', '1'>,
      string<char, 'c', 's', 'I', 'B', 'M', '2', '8', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '2', '8', '1'> >
 : textEncodingType<text_encoding_id_IBM281_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '2', '8', '1'> >
 : textEncodingType<text_encoding_id_IBM281_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'J', 'P', '-', 'E'> >
 : textEncodingType<text_encoding_id_IBM281_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '2', '8', '1'> >
 : textEncodingType<text_encoding_id_IBM281_t>
 {
 };
}
#endif

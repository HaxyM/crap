#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM866TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM866TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM866_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM866>;

 template <>
 struct textEncodingType<text_encoding_id_IBM866_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM866_t;
  using name = string<char, 'I', 'B', 'M', '8', '6', '6'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '6', '6'>,
      string<char, 'c', 'p', '8', '6', '6'>,
      string<char, '8', '6', '6'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '6'> >;
 };

 template <>
 struct textEncodingType<string<char, '8', '6', '6'> >
 : textEncodingType<text_encoding_id_IBM866_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '6', '6'> >
 : textEncodingType<text_encoding_id_IBM866_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '6'> >
 : textEncodingType<text_encoding_id_IBM866_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '6', '6'> >
 : textEncodingType<text_encoding_id_IBM866_t>
 {
 };
}
#endif

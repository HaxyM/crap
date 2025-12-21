#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_WINDOWS31LATIN5TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_WINDOWS31LATIN5TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_Windows31Latin5_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: Windows31Latin5>;

 template <>
 struct textEncodingType<text_encoding_id_Windows31Latin5_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_Windows31Latin5_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '9', '-', 'W', 'i', 'n', 'd', 'o', 'w', 's', '-', 'L', 'a', 't', 'i', 'n', '-', '5'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '9', '-', 'W', 'i', 'n', 'd', 'o', 'w', 's', '-', 'L', 'a', 't', 'i', 'n', '-', '5'>,
      string<char, 'c', 's', 'W', 'i', 'n', 'd', 'o', 'w', 's', '3', '1', 'L', 'a', 't', 'i', 'n', '5'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'W', 'i', 'n', 'd', 'o', 'w', 's', '3', '1', 'L', 'a', 't', 'i', 'n', '5'> >
 : textEncodingType<text_encoding_id_Windows31Latin5_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '9', '-', 'W', 'i', 'n', 'd', 'o', 'w', 's', '-', 'L', 'a', 't', 'i', 'n', '-', '5'> >
 : textEncodingType<text_encoding_id_Windows31Latin5_t>
 {
 };
}
#endif

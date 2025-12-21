#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_WINDOWS31LATIN2TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_WINDOWS31LATIN2TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_Windows31Latin2_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: Windows31Latin2>;

 template <>
 struct textEncodingType<text_encoding_id_Windows31Latin2_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_Windows31Latin2_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '2', '-', 'W', 'i', 'n', 'd', 'o', 'w', 's', '-', 'L', 'a', 't', 'i', 'n', '-', '2'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '2', '-', 'W', 'i', 'n', 'd', 'o', 'w', 's', '-', 'L', 'a', 't', 'i', 'n', '-', '2'>,
      string<char, 'c', 's', 'W', 'i', 'n', 'd', 'o', 'w', 's', '3', '1', 'L', 'a', 't', 'i', 'n', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'W', 'i', 'n', 'd', 'o', 'w', 's', '3', '1', 'L', 'a', 't', 'i', 'n', '2'> >
 : textEncodingType<text_encoding_id_Windows31Latin2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '2', '-', 'W', 'i', 'n', 'd', 'o', 'w', 's', '-', 'L', 'a', 't', 'i', 'n', '-', '2'> >
 : textEncodingType<text_encoding_id_Windows31Latin2_t>
 {
 };
}
#endif

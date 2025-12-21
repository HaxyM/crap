#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_WINDOWS31LATIN1TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_WINDOWS31LATIN1TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_Windows31Latin1_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: Windows31Latin1>;

 template <>
 struct textEncodingType<text_encoding_id_Windows31Latin1_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_Windows31Latin1_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '-', 'W', 'i', 'n', 'd', 'o', 'w', 's', '-', '3', '.', '1', '-', 'L', 'a', 't', 'i', 'n', '-', '1'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '-', 'W', 'i', 'n', 'd', 'o', 'w', 's', '-', '3', '.', '1', '-', 'L', 'a', 't', 'i', 'n', '-', '1'>,
      string<char, 'c', 's', 'W', 'i', 'n', 'd', 'o', 'w', 's', '3', '1', 'L', 'a', 't', 'i', 'n', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'W', 'i', 'n', 'd', 'o', 'w', 's', '3', '1', 'L', 'a', 't', 'i', 'n', '1'> >
 : textEncodingType<text_encoding_id_Windows31Latin1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '-', 'W', 'i', 'n', 'd', 'o', 'w', 's', '-', '3', '.', '1', '-', 'L', 'a', 't', 'i', 'n', '-', '1'> >
 : textEncodingType<text_encoding_id_Windows31Latin1_t>
 {
 };
}
#endif

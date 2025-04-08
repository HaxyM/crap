#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO61NORWEGIAN2TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO61NORWEGIAN2TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO61Norwegian2_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO61Norwegian2>;

 template <>
 struct textEncodingType<text_encoding_id_ISO61Norwegian2_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO61Norwegian2_t;
  using name = string<char, 'N', 'S', '_', '4', '5', '5', '1', '-', '2'>;
  using aliases = typeList<
      string<char, 'N', 'S', '_', '4', '5', '5', '1', '-', '2'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'N', 'O', '2'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '6', '1'>,
      string<char, 'n', 'o', '2'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '6', '1', 'N', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '6', '1', 'N', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n', '2'> >
 : textEncodingType<text_encoding_id_ISO61Norwegian2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', '0', '6', '4', '6', '-', 'N', 'O', '2'> >
 : textEncodingType<text_encoding_id_ISO61Norwegian2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '6', '1'> >
 : textEncodingType<text_encoding_id_ISO61Norwegian2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'N', 'S', '_', '4', '5', '5', '1', '-', '2'> >
 : textEncodingType<text_encoding_id_ISO61Norwegian2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'n', 'o', '2'> >
 : textEncodingType<text_encoding_id_ISO61Norwegian2_t>
 {
 };
}
#endif

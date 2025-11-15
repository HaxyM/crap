#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO151CUBATEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO151CUBATEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO151Cuba_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO151Cuba>;

 template <>
 struct textEncodingType<text_encoding_id_ISO151Cuba_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO151Cuba_t;
  using name = string<char, 'N', 'C', '_', 'N', 'C', '0', '0', '-', '1', '0', ':', '8', '1'>;
  using aliases = typeList<
      string<char, 'N', 'C', '_', 'N', 'C', '0', '0', '-', '1', '0', ':', '8', '1'>,
      string<char, 'c', 'u', 'b', 'a'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '1'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'C', 'U'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '5', '1', 'C', 'u', 'b', 'a'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '5', '1', 'C', 'u', 'b', 'a'> >
 : textEncodingType<text_encoding_id_ISO151Cuba_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'u', 'b', 'a'> >
 : textEncodingType<text_encoding_id_ISO151Cuba_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'C', 'U'> >
 : textEncodingType<text_encoding_id_ISO151Cuba_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '1'> >
 : textEncodingType<text_encoding_id_ISO151Cuba_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'N', 'C', '_', 'N', 'C', '0', '0', '-', '1', '0', ':', '8', '1'> >
 : textEncodingType<text_encoding_id_ISO151Cuba_t>
 {
 };
}
#endif

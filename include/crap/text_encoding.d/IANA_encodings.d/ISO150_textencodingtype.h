#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO150TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO150TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO150_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO150>;

 template <>
 struct textEncodingType<text_encoding_id_ISO150_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO150_t;
  using name = string<char, 'g', 'r', 'e', 'e', 'k', '-', 'c', 'c', 'i', 't', 't'>;
  using aliases = typeList<
      string<char, 'g', 'r', 'e', 'e', 'k', '-', 'c', 'c', 'i', 't', 't'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '0'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '5', '0'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '5', '0', 'G', 'r', 'e', 'e', 'k', 'C', 'C', 'I', 'T', 'T'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '5', '0'> >
 : textEncodingType<text_encoding_id_ISO150_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '5', '0', 'G', 'r', 'e', 'e', 'k', 'C', 'C', 'I', 'T', 'T'> >
 : textEncodingType<text_encoding_id_ISO150_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'g', 'r', 'e', 'e', 'k', '-', 'c', 'c', 'i', 't', 't'> >
 : textEncodingType<text_encoding_id_ISO150_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '0'> >
 : textEncodingType<text_encoding_id_ISO150_t>
 {
 };
}
#endif

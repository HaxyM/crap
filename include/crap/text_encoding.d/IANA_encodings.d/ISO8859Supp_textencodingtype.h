#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO8859SUPPTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO8859SUPPTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO8859Supp_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO8859Supp>;

 template <>
 struct textEncodingType<text_encoding_id_ISO8859Supp_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO8859Supp_t;
  using name = string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', 's', 'u', 'p', 'p'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', 's', 'u', 'p', 'p'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '4'>,
      string<char, 'l', 'a', 't', 'i', 'n', '1', '-', '2', '-', '5'>,
      string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', 'S', 'u', 'p', 'p'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', 'S', 'u', 'p', 'p'> >
 : textEncodingType<text_encoding_id_ISO8859Supp_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', 'S', 'u', 'p', 'p'> >
 : textEncodingType<text_encoding_id_ISO8859Supp_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '4'> >
 : textEncodingType<text_encoding_id_ISO8859Supp_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', 'a', 't', 'i', 'n', '1', '-', '2', '-', '5'> >
 : textEncodingType<text_encoding_id_ISO8859Supp_t>
 {
 };
}
#endif

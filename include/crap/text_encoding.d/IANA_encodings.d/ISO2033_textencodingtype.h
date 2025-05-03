#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO2033TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO2033TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO2033_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO2033>;

 template <>
 struct textEncodingType<text_encoding_id_ISO2033_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO2033_t;
  using name = string<char, 'I', 'S', 'O', '_', '2', '0', '3', '3', '-', '1', '9', '8', '3'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '_', '2', '0', '3', '3', '-', '1', '9', '8', '3'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '8'>,
      string<char, 'e', '1', '3', 'b'>,
      string<char, 'c', 's', 'I', 'S', 'O', '2', '0', '3', '3'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '2', '0', '3', '3'> >
 : textEncodingType<text_encoding_id_ISO2033_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', '1', '3', 'b'> >
 : textEncodingType<text_encoding_id_ISO2033_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '2', '0', '3', '3', '-', '1', '9', '8', '3'> >
 : textEncodingType<text_encoding_id_ISO2033_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '8'> >
 : textEncodingType<text_encoding_id_ISO2033_t>
 {
 };
}
#endif

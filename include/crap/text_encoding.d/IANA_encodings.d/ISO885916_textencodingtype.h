#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO885916TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO885916TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO885916_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO885916>;

 template <>
 struct textEncodingType<text_encoding_id_ISO885916_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO885916_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '6'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '6'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '2', '2', '6'>,
      string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '1', '6', ':', '2', '0', '0', '1'>,
      string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '1', '6'>,
      string<char, 'l', 'a', 't', 'i', 'n', '1', '0'>,
      string<char, 'l', '1', '0'>,
      string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '1', '6'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '1', '6'> >
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '1', '6'> >
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '1', '6', ':', '2', '0', '0', '1'> >
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '6'> >
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '2', '2', '6'> >
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', '1', '0'> >
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', 'a', 't', 'i', 'n', '1', '0'> >
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };
}
#endif

#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO85SPANISH2TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO85SPANISH2TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO85Spanish2_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO85Spanish2>;

 template <>
 struct textEncodingType<text_encoding_id_ISO85Spanish2_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO85Spanish2_t;
  using name = string<char, 'E', 'S', '2'>;
  using aliases = typeList<
      string<char, 'E', 'S', '2'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '5'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'E', 'S', '2'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '8', '5', 'S', 'p', 'a', 'n', 'i', 's', 'h', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '5', 'S', 'p', 'a', 'n', 'i', 's', 'h', '2'> >
 : textEncodingType<text_encoding_id_ISO85Spanish2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'S', '2'> >
 : textEncodingType<text_encoding_id_ISO85Spanish2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'E', 'S', '2'> >
 : textEncodingType<text_encoding_id_ISO85Spanish2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '5'> >
 : textEncodingType<text_encoding_id_ISO85Spanish2_t>
 {
 };
}
#endif

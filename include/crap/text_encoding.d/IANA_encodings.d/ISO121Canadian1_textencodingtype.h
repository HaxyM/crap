#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO121CANADIAN1TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO121CANADIAN1TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO121Canadian1_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO121Canadian1>;

 template <>
 struct textEncodingType<text_encoding_id_ISO121Canadian1_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO121Canadian1_t;
  using name = string<char, 'C', 'S', 'A', '_', 'Z', '2', '4', '3', '.', '4', '-', '1', '9', '8', '5', '-', '1'>;
  using aliases = typeList<
      string<char, 'C', 'S', 'A', '_', 'Z', '2', '4', '3', '.', '4', '-', '1', '9', '8', '5', '-', '1'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '2', '1'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'C', 'A'>,
      string<char, 'c', 's', 'a', '7', '-', '1'>,
      string<char, 'c', 's', 'a', '7', '1'>,
      string<char, 'c', 'a'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '2', '1', 'C', 'a', 'n', 'a', 'd', 'i', 'a', 'n', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'a'> >
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'C', 'S', 'A', '_', 'Z', '2', '4', '3', '.', '4', '-', '1', '9', '8', '5', '-', '1'> >
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'a', '7', '-', '1'> >
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'a', '7', '1'> >
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '2', '1', 'C', 'a', 'n', 'a', 'd', 'i', 'a', 'n', '1'> >
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'C', 'A'> >
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '2', '1'> >
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };
}
#endif

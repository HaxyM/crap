#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO122CANADIAN2TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO122CANADIAN2TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO122Canadian2_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO122Canadian2>;

 template <>
 struct textEncodingType<text_encoding_id_ISO122Canadian2_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO122Canadian2_t;
  using name = string<char, 'C', 'S', 'A', '_', 'Z', '2', '4', '3', '.', '4', '-', '1', '9', '8', '5', '-', '2'>;
  using aliases = typeList<
      string<char, 'C', 'S', 'A', '_', 'Z', '2', '4', '3', '.', '4', '-', '1', '9', '8', '5', '-', '2'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '2', '2'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'C', 'A', '2'>,
      string<char, 'c', 's', 'a', '7', '-', '2'>,
      string<char, 'c', 's', 'a', '7', '2'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '2', '2', 'C', 'a', 'n', 'a', 'd', 'i', 'a', 'n', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'S', 'A', '_', 'Z', '2', '4', '3', '.', '4', '-', '1', '9', '8', '5', '-', '2'> >
 : textEncodingType<text_encoding_id_ISO122Canadian2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'a', '7', '-', '2'> >
 : textEncodingType<text_encoding_id_ISO122Canadian2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'a', '7', '2'> >
 : textEncodingType<text_encoding_id_ISO122Canadian2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '2', '2', 'C', 'a', 'n', 'a', 'd', 'i', 'a', 'n', '2'> >
 : textEncodingType<text_encoding_id_ISO122Canadian2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'C', 'A', '2'> >
 : textEncodingType<text_encoding_id_ISO122Canadian2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '2', '2'> >
 : textEncodingType<text_encoding_id_ISO122Canadian2_t>
 {
 };
}
#endif

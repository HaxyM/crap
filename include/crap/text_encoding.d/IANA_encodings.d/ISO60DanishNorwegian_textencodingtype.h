#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO60DANISHNORWEGIANTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO60DANISHNORWEGIANTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO60DanishNorwegian_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO60DanishNorwegian>;

 template <>
 struct textEncodingType<text_encoding_id_ISO60DanishNorwegian_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO60DanishNorwegian_t;
  using name = string<char, 'N', 'S', '_', '4', '5', '5', '1', '-', '1'>;
  using aliases = typeList<
  	  string<char, 'N', 'S', '_', '4', '5', '5', '1', '-', '1'>,
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '6', '0'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'N', 'O'>,
      string<char, 'n', 'o'>,
      string<char, 'c', 's', 'I', 'S', 'O', '6', '0', 'D', 'a', 'n', 'i', 's', 'h', 'N', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '6', '0', 'N', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '6', '0', 'D', 'a', 'n', 'i', 's', 'h', 'N', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n'> >
 : textEncodingType<text_encoding_id_ISO60DanishNorwegian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '6', '0', 'N', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n', '1'> >
 : textEncodingType<text_encoding_id_ISO60DanishNorwegian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'N', 'S', '_', '4', '5', '5', '1', '-', '1'> >
 : textEncodingType<text_encoding_id_ISO60DanishNorwegian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'n', 'o'> >
 : textEncodingType<text_encoding_id_ISO60DanishNorwegian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'N', 'O'> >
 : textEncodingType<text_encoding_id_ISO60DanishNorwegian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '6', '0'> >
 : textEncodingType<text_encoding_id_ISO60DanishNorwegian_t>
 {
 };
}
#endif

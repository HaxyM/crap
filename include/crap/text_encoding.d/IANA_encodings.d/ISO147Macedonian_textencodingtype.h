#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO147MACEDONIANTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO147MACEDONIANTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO147Macedonian_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO147Macedonian>;

 template <>
 struct textEncodingType<text_encoding_id_ISO147Macedonian_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO147Macedonian_t;
  using name = string<char, 'J', 'U', 'S', '_', 'I', '.', 'B', '1', '.', '0', '0', '3', '-', 'm', 'a', 'c'>;
  using aliases = typeList<
      string<char, 'J', 'U', 'S', '_', 'I', '.', 'B', '1', '.', '0', '0', '3', '-', 'm', 'a', 'c'>,
      string<char, 'm', 'a', 'c', 'e', 'd', 'o', 'n', 'i', 'a', 'n'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '7'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '4', '7', 'M', 'a', 'c', 'e', 'd', 'o', 'n', 'i', 'a', 'n'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '4', '7', 'M', 'a', 'c', 'e', 'd', 'o', 'n', 'i', 'a', 'n'> >
 : textEncodingType<text_encoding_id_ISO147Macedonian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '7'> >
 : textEncodingType<text_encoding_id_ISO147Macedonian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'U', 'S', '_', 'I', '.', 'B', '1', '.', '0', '0', '3', '-', 'm', 'a', 'c'> >
 : textEncodingType<text_encoding_id_ISO147Macedonian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'm', 'a', 'c', 'e', 'd', 'o', 'n', 'i', 'a', 'n'> >
 : textEncodingType<text_encoding_id_ISO147Macedonian_t>
 {
 };
}
#endif

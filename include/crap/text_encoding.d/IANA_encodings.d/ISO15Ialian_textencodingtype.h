#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO15ITALIANTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO15ITALIANTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO15Italian_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO15Italian>;

 template <>
 struct textEncodingType<text_encoding_id_ISO15Italian_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO15Italian_t;
  using name = string<char, 'I', 'T'>;
  using aliases = typeList<
	  string<char, 'I', 'T'>,
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5'>,
	  string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'I', 'T'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '1', '5', 'I', 't', 'a', 'l', 'i', 'a', 'n'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '5', 'I', 't', 'a', 'l', 'i', 'a', 'n'> >
 : textEncodingType<text_encoding_id_ISO15Italian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'I', 'T'> >
 : textEncodingType<text_encoding_id_ISO15Italian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'T'> >
 : textEncodingType<text_encoding_id_ISO15Italian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5'> >
 : textEncodingType<text_encoding_id_ISO15Italian_t>
 {
 };
}
#endif

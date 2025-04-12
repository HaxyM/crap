#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO86HUNGARIANTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO86HUNGARIANTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO86Hungarian_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO86Hungarian>;

 template <>
 struct textEncodingType<text_encoding_id_ISO86Hungarian_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO86Hungarian_t;
  using name = string<char, 'M', 'S', 'Z', '_', '7', '7', '9', '5', '.', '3'>;
  using aliases = typeList<
      string<char, 'M', 'S', 'Z', '_', '7', '7', '9', '5', '.', '3'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '6'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'H', 'U'>,
      string<char, 'h', 'u'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '8', '6', 'H', 'u', 'n', 'g', 'a', 'r', 'i', 'a', 'n'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '6', 'H', 'u', 'n', 'g', 'a', 'r', 'i', 'a', 'n'> >
 : textEncodingType<text_encoding_id_ISO86Hungarian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'h', 'u'> >
 : textEncodingType<text_encoding_id_ISO86Hungarian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'H', 'U'> >
 : textEncodingType<text_encoding_id_ISO86Hungarian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '6'> >
 : textEncodingType<text_encoding_id_ISO86Hungarian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'M', 'S', 'Z', '_', '7', '7', '9', '5', '.', '3'> >
 : textEncodingType<text_encoding_id_ISO86Hungarian_t>
 {
 };
}
#endif

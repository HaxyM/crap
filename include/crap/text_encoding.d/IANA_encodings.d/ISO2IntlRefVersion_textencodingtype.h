#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO2INTLREFVERSIONTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO2INTLREFVERSIONTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO2IntlRefVersion_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO2IntlRefVersion>;

 template <>
 struct textEncodingType<text_encoding_id_ISO2IntlRefVersion_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO2IntlRefVersion_t;
  using name = string<char, 'I', 'S', 'O', '_', '6', '4', '6', '.', 'i', 'r', 'v', ':', '1', '9', '8', '3'>;
  using aliases = typeList<
  	  string<char, 'I', 'S', 'O', '_', '6', '4', '6', '.', 'i', 'r', 'v', ':', '1', '9', '8', '3'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '2'>,
      string<char, 'i', 'r', 'v'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '2', 'I', 'n', 't', 'l', 'R', 'e', 'f', 'V', 'e', 'r', 's', 'i', 'o', 'n'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '2', 'I', 'n', 't', 'l', 'R', 'e', 'f', 'V', 'e', 'r', 's', 'i', 'o', 'n'> >
 : textEncodingType<text_encoding_id_ISO2IntlRefVersion_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '6', '4', '6', '.', 'i', 'r', 'v', ':', '1', '9', '8', '3'> >
 : textEncodingType<text_encoding_id_ISO2IntlRefVersion_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 'r', 'v'> >
 : textEncodingType<text_encoding_id_ISO2IntlRefVersion_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '2'> >
 : textEncodingType<text_encoding_id_ISO2IntlRefVersion_t>
 {
 };
}
#endif

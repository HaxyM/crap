#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO90TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO90TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO90_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO90>;

 template <>
 struct textEncodingType<text_encoding_id_ISO90_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO90_t;
  using name = string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '0'>;
  using aliases = typeList<
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '0'>,
      string<char, 'c', 's', 'I', 'S', 'O', '9', '0'> >;
	  
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '9', '0'> >
 : textEncodingType<text_encoding_id_ISO90_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '0'> >
 : textEncodingType<text_encoding_id_ISO90_t>
 {
 };
}
#endif

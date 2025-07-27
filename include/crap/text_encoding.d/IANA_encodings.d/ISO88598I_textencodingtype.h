#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO88598ITEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO88598ITEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO88598I_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO88598I>;

 template <>
 struct textEncodingType<text_encoding_id_ISO88598I_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO88598I_t;
  using name = string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '8', '-', 'I'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '8', '-', 'I'>,
      string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '8', 'I'>,
      string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '8', '-', 'I'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '8', 'I'> >
 : textEncodingType<text_encoding_id_ISO88598I_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '8', '-', 'I'> >
 : textEncodingType<text_encoding_id_ISO88598I_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '8', '-', 'I'> >
 : textEncodingType<text_encoding_id_ISO88598I_t>
 {
 };
}
#endif

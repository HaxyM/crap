#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO88598ETEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO88598ETEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO88598E_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO88598E>;

 template <>
 struct textEncodingType<text_encoding_id_ISO88598E_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO88598E_t;
  using name = string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '8', '-', 'E'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '8', '-', 'E'>,
      string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '8', 'E'>,
      string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '8', '-', 'E'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '8', 'E'> >
 : textEncodingType<text_encoding_id_ISO88598E_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '8', '-', 'E'> >
 : textEncodingType<text_encoding_id_ISO88598E_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '8', '-', 'E'> >
 : textEncodingType<text_encoding_id_ISO88598E_t>
 {
 };
}
#endif

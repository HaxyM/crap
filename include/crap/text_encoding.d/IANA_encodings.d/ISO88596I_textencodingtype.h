#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO88596ITEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO88596ITEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO88596I_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO88596I>;

 template <>
 struct textEncodingType<text_encoding_id_ISO88596I_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO88596I_t;
  using name = string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '6', '-', 'I'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '6', '-', 'I'>,
      string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '6', 'I'>,
      string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '6', '-', 'I'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '6', 'I'> >
 : textEncodingType<text_encoding_id_ISO88596I_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '6', '-', 'I'> >
 : textEncodingType<text_encoding_id_ISO88596I_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '6', '-', 'I'> >
 : textEncodingType<text_encoding_id_ISO88596I_t>
 {
 };
}
#endif

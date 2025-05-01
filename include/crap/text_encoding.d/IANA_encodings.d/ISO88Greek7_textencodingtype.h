#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO88GREEK7TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO88GREEK7TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO88Greek7_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO88Greek7>;

 template <>
 struct textEncodingType<text_encoding_id_ISO88Greek7_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO88Greek7_t;
  using name = string<char, 'g', 'r', 'e', 'e', 'k', '7'>;
  using aliases = typeList<
      string<char, 'g', 'r', 'e', 'e', 'k', '7'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '8'>,
      string<char, 'c', 's', 'I', 'S', 'O', '8', '8', 'G', 'r', 'e', 'e', 'k', '7'> >;
	  
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '8', 'G', 'r', 'e', 'e', 'k', '7'> >
 : textEncodingType<text_encoding_id_ISO88Greek7_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'g', 'r', 'e', 'e', 'k', '7'> >
 : textEncodingType<text_encoding_id_ISO88Greek7_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '8'> >
 : textEncodingType<text_encoding_id_ISO88Greek7_t>
 {
 };
}
#endif

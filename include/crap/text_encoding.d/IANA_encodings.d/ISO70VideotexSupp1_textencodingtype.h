#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO70VIDEOTEXSUPP1TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO70VIDEOTEXSUPP1TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO70VideotexSupp1_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO70VideotexSupp1>;

 template <>
 struct textEncodingType<text_encoding_id_ISO70VideotexSupp1_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO70VideotexSupp1_t;
  using name = string<char, 'v', 'i', 'd', 'e', 'o', 't', 'e', 'x', '-', 's', 'u', 'p', 'p', 'l'>;
  using aliases = typeList<
      string<char, 'v', 'i', 'd', 'e', 'o', 't', 'e', 'x', '-', 's', 'u', 'p', 'p', 'l'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '7', '0'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '7', '0', 'V', 'i', 'd', 'e', 'o', 't', 'e', 'x', 'S', 'u', 'p', 'p', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '7', '0', 'V', 'i', 'd', 'e', 'o', 't', 'e', 'x', 'S', 'u', 'p', 'p', '1'> >
 : textEncodingType<text_encoding_id_ISO70VideotexSupp1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '7', '0'> >
 : textEncodingType<text_encoding_id_ISO70VideotexSupp1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'v', 'i', 'd', 'e', 'o', 't', 'e', 'x', '-', 's', 'u', 'p', 'p', 'l'> >
 : textEncodingType<text_encoding_id_ISO70VideotexSupp1_t>
 {
 };
}
#endif

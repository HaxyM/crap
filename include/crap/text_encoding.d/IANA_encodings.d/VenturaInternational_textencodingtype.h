#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_VENTURAINTERNATIONALTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_VENTURAINTERNATIONALTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_VenturaInternational_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: VenturaInternational>;

 template <>
 struct textEncodingType<text_encoding_id_VenturaInternational_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_VenturaInternational_t;
  using name = string<char, 'V', 'e', 'n', 't', 'u', 'r', 'a', '-', 'I', 'n', 't', 'e', 'r', 'n', 'a', 't', 'i', 'o', 'n', 'a', 'l'>;
  using aliases = typeList<
      string<char, 'V', 'e', 'n', 't', 'u', 'r', 'a', '-', 'I', 'n', 't', 'e', 'r', 'n', 'a', 't', 'i', 'o', 'n', 'a', 'l'>,
      string<char, 'c', 's', 'V', 'e', 'n', 't', 'u', 'r', 'a', 'I', 'n', 't', 'e', 'r', 'n', 'a', 't', 'i', 'o', 'n', 'a', 'l'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'V', 'e', 'n', 't', 'u', 'r', 'a', 'I', 'n', 't', 'e', 'r', 'n', 'a', 't', 'i', 'o', 'n', 'a', 'l'> >
 : textEncodingType<text_encoding_id_VenturaInternational_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'V', 'e', 'n', 't', 'u', 'r', 'a', '-', 'I', 'n', 't', 'e', 'r', 'n', 'a', 't', 'i', 'o', 'n', 'a', 'l'> >
 : textEncodingType<text_encoding_id_VenturaInternational_t>
 {
 };
}
#endif

#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO646DANISHTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO646DANISHTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO646Danish_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO646Danish>;

 template <>
 struct textEncodingType<text_encoding_id_ISO646Danish_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO646Danish_t;
  using name = string<char, 'D', 'S', '_', '2', '0', '8', '9'>;
  using aliases = typeList<
      string<char, 'D', 'S', '_', '2', '0', '8', '9'>,
      string<char, 'D', 'S', '2', '0', '8', '9'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'D', 'K'>,
      string<char, 'd', 'k'>,
      string<char, 'c', 's', 'I', 'S', 'O', '6', '4', '6', 'D', 'a', 'n', 'i', 's', 'h'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '6', '4', '6', 'D', 'a', 'n', 'i', 's', 'h'> >
 : textEncodingType<text_encoding_id_ISO646Danish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'd', 'k'> >
 : textEncodingType<text_encoding_id_ISO646Danish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'D', 'S', '2', '0', '8', '9'> >
 : textEncodingType<text_encoding_id_ISO646Danish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'D', 'S', '_', '2', '0', '8', '9'> >
 : textEncodingType<text_encoding_id_ISO646Danish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'D', 'K'> >
 : textEncodingType<text_encoding_id_ISO646Danish_t>
 {
 };
}
#endif

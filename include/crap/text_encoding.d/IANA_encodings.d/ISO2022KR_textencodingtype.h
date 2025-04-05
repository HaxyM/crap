#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO2022KRTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO2022KRTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO2022KR_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO2022KR>;

 template <>
 struct textEncodingType<text_encoding_id_ISO2022KR_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO2022KR_t;
  using name = string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'K', 'R'>;
  using aliases = typeList<
  	  string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'K', 'R'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '2', '0', '2', '2', 'K', 'R'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '2', '0', '2', '2', 'K', 'R'> >
 : textEncodingType<text_encoding_id_ISO2022KR_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'K', 'R'> >
 : textEncodingType<text_encoding_id_ISO2022KR_t>
 {
 };
}
#endif

#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO2022JP2TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO2022JP2TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO2022JP2_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO2022JP2>;

 template <>
 struct textEncodingType<text_encoding_id_ISO2022JP2_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO2022JP2_t;
  using name = string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'J', 'P', '-', '2'>;
  using aliases = typeList<
  	  string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'J', 'P', '-', '2'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '2', '0', '2', '2', 'J', 'P', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '2', '0', '2', '2', 'J', 'P', '2'> >
 : textEncodingType<text_encoding_id_ISO2022JP2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'J', 'P', '-', '2'> >
 : textEncodingType<text_encoding_id_ISO2022JP2_t>
 {
 };
}
#endif

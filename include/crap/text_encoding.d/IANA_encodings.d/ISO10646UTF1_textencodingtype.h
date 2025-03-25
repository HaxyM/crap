#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO10646UTF1TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO10646UTF1TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO10646UTF1_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO10646UTF1>;

 template <>
 struct textEncodingType<text_encoding_id_ISO10646UTF1_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO10646UTF1_t;
  using name = string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'T', 'F', '-', '1'>;
  using aliases = typeList<
  	  string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'T', 'F', '-', '1'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '1', '0', '6', '4', '6', 'U', 'T', 'F', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '0', '6', '4', '6', 'U', 'T', 'F', '1'> >
 : textEncodingType<text_encoding_id_ISO10646UTF1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'T', 'F', '-', '1'> >
 : textEncodingType<text_encoding_id_ISO10646UTF1_t>
 {
 };
}
#endif

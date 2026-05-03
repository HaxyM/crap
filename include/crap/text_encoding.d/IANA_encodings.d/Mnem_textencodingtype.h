#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_MNEMTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_MNEMTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_Mnem_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: Mnem>;

 template <>
 struct textEncodingType<text_encoding_id_Mnem_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_Mnem_t;
  using name = string<char, 'M', 'N', 'E', 'M'>;
  using aliases = typeList<
      string<char, 'M', 'N', 'E', 'M'>,
      string<char, 'c', 's', 'M', 'n', 'e', 'm'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'M', 'n', 'e', 'm'> >
 : textEncodingType<text_encoding_id_Mnem_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'M', 'N', 'E', 'M'> >
 : textEncodingType<text_encoding_id_Mnem_t>
 {
 };
}
#endif

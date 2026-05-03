#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_MNEMONICTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_MNEMONICTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_Mnemonic_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: Mnemonic>;

 template <>
 struct textEncodingType<text_encoding_id_Mnemonic_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_Mnemonic_t;
  using name = string<char, 'M', 'N', 'E', 'M', 'O', 'N', 'I', 'C'>;
  using aliases = typeList<
      string<char, 'M', 'N', 'E', 'M', 'O', 'N', 'I', 'C'>,
      string<char, 'c', 's', 'M', 'n', 'e', 'm', 'o', 'n', 'i', 'c'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'M', 'n', 'e', 'm', 'o', 'n', 'i', 'c'> >
 : textEncodingType<text_encoding_id_Mnemonic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'M', 'N', 'E', 'M', 'O', 'N', 'I', 'C'> >
 : textEncodingType<text_encoding_id_Mnemonic_t>
 {
 };
}
#endif

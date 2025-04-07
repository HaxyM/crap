#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO51INISCYRILLICTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO51INISCYRILLICTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO51INISCyrillic_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO51INISCyrillic>;

 template <>
 struct textEncodingType<text_encoding_id_ISO51INISCyrillic_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO51INISCyrillic_t;
  using name = string<char, 'I', 'N', 'I', 'S', '-', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>;
  using aliases = typeList<
      string<char, 'I', 'N', 'I', 'S', '-', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '5', '1'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '5', '1', 'I', 'N', 'I', 'S', 'C', 'y', 'r', 'i', 'l', 'l', 'i', 'c'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '5', '1', 'I', 'N', 'I', 'S', 'C', 'y', 'r', 'i', 'l', 'l', 'i', 'c'> >
 : textEncodingType<text_encoding_id_ISO51INISCyrillic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'N', 'I', 'S', '-', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'> >
 : textEncodingType<text_encoding_id_ISO51INISCyrillic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '5', '1'> >
 : textEncodingType<text_encoding_id_ISO51INISCyrillic_t>
 {
 };
}
#endif

#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO111ECMACYRILLICITTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO111ECMACYRILLICITTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO111ECMACyrillic_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO111ECMACyrillic>;

 template <>
 struct textEncodingType<text_encoding_id_ISO111ECMACyrillic_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO111ECMACyrillic_t;
  using name = string<char, 'E', 'C', 'M', 'A', '-', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>;
  using aliases = typeList<
      string<char, 'E', 'C', 'M', 'A', '-', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '1', '1'>,
      string<char, 'K', 'O', 'I', '8', '-', 'E'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '1', '1', 'E', 'C', 'M', 'A', 'C', 'y', 'r', 'i', 'l', 'l', 'i', 'c'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '1', '1', 'E', 'C', 'M', 'A', 'C', 'y', 'r', 'i', 'l', 'l', 'i', 'c'> >
 : textEncodingType<text_encoding_id_ISO111ECMACyrillic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'C', 'M', 'A', '-', 'c', 'y', 'r', 'i', 'l', 'i', 'c'> >
 : textEncodingType<text_encoding_id_ISO111ECMACyrillic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '1', '1'> >
 : textEncodingType<text_encoding_id_ISO111ECMACyrillic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'K', 'O', 'I', '8', '-', 'E'> >
 : textEncodingType<text_encoding_id_ISO111ECMACyrillic_t>
 {
 };
}
#endif

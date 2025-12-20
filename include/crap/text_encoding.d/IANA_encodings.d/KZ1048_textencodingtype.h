#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_KZ1048TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_KZ1048TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_KZ1048_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: KZ1048>;

 template <>
 struct textEncodingType<text_encoding_id_KZ1048_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_KZ1048_t;
  using name = string<char, 'K', 'Z', '-', '1', '0', '4', '8'>;
  using aliases = typeList<
      string<char, 'K', 'Z', '-', '1', '0', '4', '8'>,
      string<char, 'S', 'T', 'R', 'K', '1', '0', '4', '8', '-', '2', '0', '0', '2'>,
      string<char, 'R', 'K', '1', '0', '4', '8'>,
      string<char, 'c', 's', 'K', 'Z', '1', '0', '4', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'K', 'Z', '1', '0', '4', '8'> >
 : textEncodingType<text_encoding_id_KZ1048_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'K', 'Z', '-', '1', '0', '4', '8'> >
 : textEncodingType<text_encoding_id_KZ1048_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'R', 'K', '1', '0', '4', '8'> >
 : textEncodingType<text_encoding_id_KZ1048_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'S', 'T', 'R', 'K', '1', '0', '4', '8', '-', '2', '0', '0', '2'> >
 : textEncodingType<text_encoding_id_KZ1048_t>
 {
 };
}
#endif

#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO128T101G2TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO128T101G2TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO128T101G2_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO128T101G2>;

 template <>
 struct textEncodingType<text_encoding_id_ISO128T101G2_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO128T101G2_t;
  using name = string<char, 'T', '.', '1', '0', '1', '-', 'G', '2'>;
  using aliases = typeList<
      string<char, 'T', '.', '1', '0', '1', '-', 'G', '2'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '2', '8'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '2', '8', 'T', '1', '0', '1', 'G', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '2', '8', 'T', '1', '0', '1', 'G', '2'> >
 : textEncodingType<text_encoding_id_ISO128T101G2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '2', '8'> >
 : textEncodingType<text_encoding_id_ISO128T101G2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'T', '.', '1', '0', '1', '-', 'G', '2'> >
 : textEncodingType<text_encoding_id_ISO128T101G2_t>
 {
 };
}
#endif

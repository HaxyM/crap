#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UNICODELATIN1TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UNICODELATIN1TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UnicodeLatin1_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UnicodeLatin1>;

 template <>
 struct textEncodingType<text_encoding_id_UnicodeLatin1_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UnicodeLatin1_t;
  using name = string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'L', 'a', 't', 'i', 'n', '1'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'L', 'a', 't', 'i', 'n', '1'>,
      string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'L', 'a', 't', 'i', 'n', '1'>,
      string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'L', 'a', 't', 'i', 'n', '1'> >
 : textEncodingType<text_encoding_id_UnicodeLatin1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6'> >
 : textEncodingType<text_encoding_id_UnicodeLatin1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'L', 'a', 't', 'i', 'n', '1'> >
 : textEncodingType<text_encoding_id_UnicodeLatin1_t>
 {
 };
}
#endif

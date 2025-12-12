#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO2022CNEXTTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO2022CNEXTTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO2022CNEXT_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO2022CNEXT>;

 template <>
 struct textEncodingType<text_encoding_id_ISO2022CNEXT_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO2022CNEXT_t;
  using name = string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'C', 'N', '-', 'E', 'X', 'T'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'C', 'N', '-', 'E', 'X', 'T'>,
      string<char, 'c', 's', 'I', 'S', 'O', '2', '0', '2', '2', 'C', 'N', 'E', 'X', 'T'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '2', '0', '2', '2', 'C', 'N', 'E', 'X', 'T'> >
 : textEncodingType<text_encoding_id_ISO2022CNEXT_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'C', 'N', '-', 'E', 'X', 'T'> >
 : textEncodingType<text_encoding_id_ISO2022CNEXT_t>
 {
 };
}
#endif

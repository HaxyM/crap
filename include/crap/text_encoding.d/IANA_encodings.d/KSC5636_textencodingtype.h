#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_KSC5636TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_KSC5636TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_KSC5636_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: KSC5636>;

 template <>
 struct textEncodingType<text_encoding_id_KSC5636_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_KSC5636_t;
  using name = string<char, 'K', 'S', 'C', '5', '6', '3', '6'>;
  using aliases = typeList<
      string<char, 'K', 'S', 'C', '5', '6', '3', '6'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'K', 'R'>,
      string<char, 'c', 's', 'K', 'S', 'C', '5', '6', '3', '6'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'K', 'S', 'C', '5', '6', '3', '6'> >
 : textEncodingType<text_encoding_id_KSC5636_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'K', 'R'> >
 : textEncodingType<text_encoding_id_KSC5636_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'K', 'S', 'C', '5', '6', '3', '6'> >
 : textEncodingType<text_encoding_id_KSC5636_t>
 {
 };
}
#endif

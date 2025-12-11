#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO2022CNTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO2022CNTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO2022CN_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO2022CN>;

 template <>
 struct textEncodingType<text_encoding_id_ISO2022CN_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO2022CN_t;
  using name = string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'C', 'N'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'C', 'N'>,
      string<char, 'c', 's', 'I', 'S', 'O', '2', '0', '2', '2', 'C', 'N'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '2', '0', '2', '2', 'C', 'N'> >
 : textEncodingType<text_encoding_id_ISO2022CN_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'C', 'N'> >
 : textEncodingType<text_encoding_id_ISO2022CN_t>
 {
 };
}
#endif

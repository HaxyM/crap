#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM864TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM864TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM864_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM864>;

 template <>
 struct textEncodingType<text_encoding_id_IBM864_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM864_t;
  using name = string<char, 'I', 'B', 'M', '8', '6', '4'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '6', '4'>,
      string<char, 'c', 'p', '8', '6', '4'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '4'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '6', '4'> >
 : textEncodingType<text_encoding_id_IBM864_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '4'> >
 : textEncodingType<text_encoding_id_IBM864_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '6', '4'> >
 : textEncodingType<text_encoding_id_IBM864_t>
 {
 };
}
#endif

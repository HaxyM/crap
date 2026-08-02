#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM1047TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM1047TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM1047_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM1047>;

 template <>    
 struct textEncodingType<text_encoding_id_IBM1047_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM1047_t;
  using name = string<char, 'I', 'B', 'M', '1', '0', '4', '7'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '1', '0', '4', '7'>,
      string<char, 'I', 'B', 'M', '-', '1', '0', '4', '7'>,
      string<char, 'c', 's', 'I', 'B', 'M', '1', '0', '4', '7'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '1', '0', '4', '7'> >
 : textEncodingType<text_encoding_id_IBM1047_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '-', '1', '0', '4', '7'> >
 : textEncodingType<text_encoding_id_IBM1047_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '1', '0', '4', '7'> >
 : textEncodingType<text_encoding_id_IBM1047_t>
 {
 };
}
#endif

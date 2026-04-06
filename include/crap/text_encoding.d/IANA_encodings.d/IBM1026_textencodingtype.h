#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM1026TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM1026TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM1026_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM1026>;

 template <>
 struct textEncodingType<text_encoding_id_IBM1026_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM1026_t;
  using name = string<char, 'I', 'B', 'M', '1', '0', '2', '6'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '1', '0', '2', '6'>,
      string<char, 'C', 'P', '1', '0', '2', '6'>,
      string<char, 'c', 's', 'I', 'B', 'M', '1', '0', '2', '6'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '1', '0', '2', '6'> >
 : textEncodingType<text_encoding_id_IBM1026_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '1', '0', '2', '6'> >
 : textEncodingType<text_encoding_id_IBM1026_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '1', '0', '2', '6'> >
 : textEncodingType<text_encoding_id_IBM1026_t>
 {
 };
}
#endif

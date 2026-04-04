#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM868TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM868TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM868_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM868>;

 template <>
 struct textEncodingType<text_encoding_id_IBM868_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM868_t;
  using name = string<char, 'I', 'B', 'M', '8', '6', '8'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '6', '8'>,
      string<char, 'C', 'P', '8', '6', '8'>,
      string<char, 'c', 'p', '-', 'a', 'r'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '-', 'a', 'r'> >
 : textEncodingType<text_encoding_id_IBM868_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '8', '6', '8'> >
 : textEncodingType<text_encoding_id_IBM868_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '8'> >
 : textEncodingType<text_encoding_id_IBM868_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '6', '8'> >
 : textEncodingType<text_encoding_id_IBM868_t>
 {
 };
}
#endif

#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM038TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM038TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM038_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM038>;

 template <>
 struct textEncodingType<text_encoding_id_IBM038_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM038_t;
  using name = string<char, 'I', 'B', 'M', '0', '3', '8'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '0', '3', '8'>,
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'I', 'N', 'T'>,
      string<char, 'c', 'p', '0', '3', '8'>,
      string<char, 'c', 's', 'I', 'B', 'M', '0', '3', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '0', '3', '8'> >
 : textEncodingType<text_encoding_id_IBM038_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '0', '3', '8'> >
 : textEncodingType<text_encoding_id_IBM038_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'I', 'N', 'T'> >
 : textEncodingType<text_encoding_id_IBM038_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '0', '3', '8'> >
 : textEncodingType<text_encoding_id_IBM038_t>
 {
 };
}
#endif

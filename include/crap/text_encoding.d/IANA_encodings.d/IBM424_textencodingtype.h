#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM424TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM424TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM424_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM424>;

 template <>
 struct textEncodingType<text_encoding_id_IBM424_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM424_t;
  using name = string<char, 'I', 'B', 'M', '4', '2', '4'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '4', '2', '4'>,
      string<char, 'c', 'p', '4', '2', '4'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'h', 'e'>,
      string<char, 'c', 's', 'I', 'B', 'M', '4', '2', '4'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '4', '2', '4'> >
 : textEncodingType<text_encoding_id_IBM424_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '4', '2', '4'> >
 : textEncodingType<text_encoding_id_IBM424_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'h', 'e'> >
 : textEncodingType<text_encoding_id_IBM424_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '4', '2', '4'> >
 : textEncodingType<text_encoding_id_IBM424_t>
 {
 };
}
#endif

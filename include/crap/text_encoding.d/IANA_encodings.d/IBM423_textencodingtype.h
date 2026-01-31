#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM423TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM423TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM423_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM423>;

 template <>
 struct textEncodingType<text_encoding_id_IBM423_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM423_t;
  using name = string<char, 'I', 'B', 'M', '4', '2', '3'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '4', '2', '3'>,
      string<char, 'c', 'p', '4', '2', '3'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'g', 'r'>,
      string<char, 'c', 's', 'I', 'B', 'M', '4', '2', '3'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '4', '2', '3'> >
 : textEncodingType<text_encoding_id_IBM423_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '4', '2', '3'> >
 : textEncodingType<text_encoding_id_IBM423_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'g', 'r'> >
 : textEncodingType<text_encoding_id_IBM423_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '4', '2', '3'> >
 : textEncodingType<text_encoding_id_IBM423_t>
 {
 };
}
#endif

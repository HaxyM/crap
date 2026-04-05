#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM871TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM871TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM871_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM871>;

 template <>
 struct textEncodingType<text_encoding_id_IBM871_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM871_t;
  using name = string<char, 'I', 'B', 'M', '8', '7', '1'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '7', '1'>,
      string<char, 'C', 'P', '8', '7', '1'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'i', 's'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '7', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '8', '7', '1'> >
 : textEncodingType<text_encoding_id_IBM871_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '7', '1'> >
 : textEncodingType<text_encoding_id_IBM871_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'i', 's'> >
 : textEncodingType<text_encoding_id_IBM871_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '7', '1'> >
 : textEncodingType<text_encoding_id_IBM871_t>
 {
 };
}
#endif

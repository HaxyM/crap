#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM297TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM297TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM297_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM297>;

 template <>
 struct textEncodingType<text_encoding_id_IBM297_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM297_t;
  using name = string<char, 'I', 'B', 'M', '2', '9', '7'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '2', '9', '7'>,
      string<char, 'c', 'p', '2', '9', '7'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'f', 'r'>,
      string<char, 'c', 's', 'I', 'B', 'M', '2', '9', '7'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '2', '9', '7'> >
 : textEncodingType<text_encoding_id_IBM297_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '2', '9', '7'> >
 : textEncodingType<text_encoding_id_IBM297_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'f', 'r'> >
 : textEncodingType<text_encoding_id_IBM297_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '2', '9', '7'> >
 : textEncodingType<text_encoding_id_IBM297_t>
 {
 };
}
#endif

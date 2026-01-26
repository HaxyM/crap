#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM037TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM037TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM037_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM037>;

 template <>
 struct textEncodingType<text_encoding_id_IBM037_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM037_t;
  using name = string<char, 'I', 'B', 'M', '0', '3', '7'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '0', '3', '7'>,
      string<char, 'c', 'p', '0', '3', '7'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'u', 's'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'c', 'a'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'w', 't'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'n', 'l'>,
      string<char, 'c', 's', 'I', 'B', 'M', '0', '3', '7'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '0', '3', '7'> >
 : textEncodingType<text_encoding_id_IBM037_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '0', '3', '7'> >
 : textEncodingType<text_encoding_id_IBM037_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'c', 'a'> >
 : textEncodingType<text_encoding_id_IBM037_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'n', 'l'> >
 : textEncodingType<text_encoding_id_IBM037_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'u', 's'> >
 : textEncodingType<text_encoding_id_IBM037_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'w', 't'> >
 : textEncodingType<text_encoding_id_IBM037_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '0', '3', '7'> >
 : textEncodingType<text_encoding_id_IBM037_t>
 {
 };
}
#endif

#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM01142TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM01142TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM01142_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM01142>;

 template <>    
 struct textEncodingType<text_encoding_id_IBM01142_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM01142_t;
  using name = string<char, 'I', 'B', 'M', '0', '1', '1', '4', '2'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '0', '1', '1', '4', '2'>,
      string<char, 'C', 'C', 'S', 'I', 'D', '0', '1', '1', '4', '2'>,
      string<char, 'C', 'P', '0', '1', '1', '4', '2'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'd', 'k', '-', '2', '7', '7', '+', 'e', 'u', 'r', 'o'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'n', 'o', '-', '2', '7', '7', '+', 'e', 'u', 'r', 'o'>,
      string<char, 'c', 's', 'I', 'B', 'M', '0', '1', '1', '4', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'C', 'S', 'I', 'D', '0', '1', '1', '4', '2'> >
 : textEncodingType<text_encoding_id_IBM01142_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '0', '1', '1', '4', '2'> >
 : textEncodingType<text_encoding_id_IBM01142_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '0', '1', '1', '4', '2'> >
 : textEncodingType<text_encoding_id_IBM01142_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'd', 'k', '-', '2', '7', '7', '+', 'e', 'u', 'r', 'o'> >
 : textEncodingType<text_encoding_id_IBM01142_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'n', 'o', '-', '2', '7', '7', '+', 'e', 'u', 'r', 'o'> >
 : textEncodingType<text_encoding_id_IBM01142_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '0', '1', '1', '4', '2'> >
 : textEncodingType<text_encoding_id_IBM01142_t>
 {
 };
}
#endif

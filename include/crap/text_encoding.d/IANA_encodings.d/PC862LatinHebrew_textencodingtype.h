#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_PC862LATINHEBREWTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_PC862LATINHEBREWTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_PC862LatinHebrew_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: PC862LatinHebrew>;

 template <>
 struct textEncodingType<text_encoding_id_PC862LatinHebrew_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_PC862LatinHebrew_t;
  using name = string<char, 'I', 'B', 'M', '8', '6', '2'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '6', '2'>,
      string<char, 'c', 'p', '8', '6', '2'>,
      string<char, '8', '6', '2'>,
      string<char, 'c', 's', 'P', 'C', '8', '6', '2', 'L', 'a', 't', 'i', 'n', 'H', 'e', 'b', 'r', 'e', 'w'> >;
 };

 template <>
 struct textEncodingType<string<char, '8', '6', '2'> >
 : textEncodingType<text_encoding_id_PC862LatinHebrew_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '6', '2'> >
 : textEncodingType<text_encoding_id_PC862LatinHebrew_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'P', 'C', '8', '6', '2', 'L', 'a', 't', 'i', 'n', 'H', 'e', 'b', 'r', 'e', 'w'> >
 : textEncodingType<text_encoding_id_PC862LatinHebrew_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '6', '2'> >
 : textEncodingType<text_encoding_id_PC862LatinHebrew_t>
 {
 };
}
#endif

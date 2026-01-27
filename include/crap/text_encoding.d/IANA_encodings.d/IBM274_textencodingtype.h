#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM274TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM274TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM274_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM274>;

 template <>
 struct textEncodingType<text_encoding_id_IBM274_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM274_t;
  using name = string<char, 'I', 'B', 'M', '2', '7', '4'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '2', '7', '4'>,
      string<char, 'C', 'P', '2', '7', '4'>,
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'B', 'E'>,
      string<char, 'c', 's', 'I', 'B', 'M', '2', '7', '4'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '2', '7', '4'> >
 : textEncodingType<text_encoding_id_IBM274_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '2', '7', '4'> >
 : textEncodingType<text_encoding_id_IBM274_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'B', 'E'> >
 : textEncodingType<text_encoding_id_IBM274_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '2', '7', '4'> >
 : textEncodingType<text_encoding_id_IBM274_t>
 {
 };
}
#endif

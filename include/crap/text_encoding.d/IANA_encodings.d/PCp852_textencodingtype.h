#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_PCP852TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_PCP852TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_PCp852_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: PCp852>;

 template <>
 struct textEncodingType<text_encoding_id_PCp852_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_PCp852_t;
  using name = string<char, 'I', 'B', 'M', '8', '5', '2'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '5', '2'>,
      string<char, 'c', 'p', '8', '5', '2'>,
      string<char, '8', '5', '2'>,
      string<char, 'c', 's', 'P', 'C', 'p', '8', '5', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, '8', '5', '2'> >
 : textEncodingType<text_encoding_id_PCp852_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '5', '2'> >
 : textEncodingType<text_encoding_id_PCp852_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'P', 'C', 'p', '8', '5', '2'> >
 : textEncodingType<text_encoding_id_PCp852_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '5', '2'> >
 : textEncodingType<text_encoding_id_PCp852_t>
 {
 };
}
#endif

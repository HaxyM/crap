#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM865TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM865TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM865_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM865>;

 template <>
 struct textEncodingType<text_encoding_id_IBM865_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM865_t;
  using name = string<char, 'I', 'B', 'M', '8', '6', '5'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '6', '5'>,
      string<char, 'c', 'p', '8', '6', '5'>,
      string<char, '8', '6', '5'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '5'> >;
 };

 template <>
 struct textEncodingType<string<char, '8', '6', '5'> >
 : textEncodingType<text_encoding_id_IBM865_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '6', '5'> >
 : textEncodingType<text_encoding_id_IBM865_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '6', '5'> >
 : textEncodingType<text_encoding_id_IBM865_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '6', '5'> >
 : textEncodingType<text_encoding_id_IBM865_t>
 {
 };
}
#endif

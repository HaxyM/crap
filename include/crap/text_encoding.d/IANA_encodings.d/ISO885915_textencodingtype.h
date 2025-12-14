#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO885915TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO885915TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO885915_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO885915>;

 template <>
 struct textEncodingType<text_encoding_id_ISO885915_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO885915_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '5'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '5'>,
      string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '1', '5'>,
      string<char, 'L', 'a', 't', 'i', 'n', '-', '9'>,
      string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '1', '5'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '1', '5'> >
 : textEncodingType<text_encoding_id_ISO885915_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '1', '5'> >
 : textEncodingType<text_encoding_id_ISO885915_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '5'> >
 : textEncodingType<text_encoding_id_ISO885915_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'L', 'a', 't', 'i', 'n', '-', '9'> >
 : textEncodingType<text_encoding_id_ISO885915_t>
 {
 };
}
#endif

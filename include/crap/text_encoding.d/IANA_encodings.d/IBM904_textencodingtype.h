#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM904TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM904TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM904_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM904>;

 template <>
 struct textEncodingType<text_encoding_id_IBM904_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM904_t;
  using name = string<char, 'I', 'B', 'M', '9', '0', '4'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '9', '0', '4'>,
      string<char, 'c', 'p', '9', '0', '4'>,
      string<char, '9', '0', '4'>,
      string<char, 'c', 's', 'I', 'B', 'M', '9', '0', '4'> >;
 };

 template <>
 struct textEncodingType<string<char, '9', '0', '4'> >
 : textEncodingType<text_encoding_id_IBM904_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '9', '0', '4'> >
 : textEncodingType<text_encoding_id_IBM904_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '9', '0', '4'> >
 : textEncodingType<text_encoding_id_IBM904_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '9', '0', '4'> >
 : textEncodingType<text_encoding_id_IBM904_t>
 {
 };
}
#endif

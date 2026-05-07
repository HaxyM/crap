#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM00924TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM00924TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM00924_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM00924>;

 template <>    
 struct textEncodingType<text_encoding_id_IBM00924_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM00924_t;
  using name = string<char, 'I', 'B', 'M', '0', '0', '9', '2', '4'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '0', '0', '9', '2', '4'>,
      string<char, 'C', 'C', 'S', 'I', 'D', '0', '0', '9', '2', '4'>,
      string<char, 'C', 'P', '0', '0', '9', '2', '4'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'L', 'a', 't', 'i', 'n', '9', '-', '-', 'e', 'u', 'r', 'o'>,
      string<char, 'c', 's', 'I', 'B', 'M', '0', '0', '9', '2', '4'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'C', 'S', 'I', 'D', '0', '0', '9', '2', '4'> >
 : textEncodingType<text_encoding_id_IBM00924_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '0', '0', '9', '2', '4'> >
 : textEncodingType<text_encoding_id_IBM00924_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '0', '0', '9', '2', '4'> >
 : textEncodingType<text_encoding_id_IBM00924_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'L', 'a', 't', 'i', 'n', '9', '-', '-', 'e', 'u', 'r', 'o'> >
 : textEncodingType<text_encoding_id_IBM00924_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '0', '0', '9', '2', '4'> >
 : textEncodingType<text_encoding_id_IBM00924_t>
 {
 };
}
#endif

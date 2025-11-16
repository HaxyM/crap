#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO6937ADDTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO6937ADDTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO6937Add_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO6937Add>;

 template <>
 struct textEncodingType<text_encoding_id_ISO6937Add_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO6937Add_t;
  using name = string<char, 'I', 'S', 'O', '_', '6', '9', '3', '7', '-', '2', '-', '2', '5'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '_', '6', '9', '3', '7', '-', '2', '-', '2', '5'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '2'>,
      string<char, 'c', 's', 'I', 'S', 'O', '6', '9', '3', '7', 'A', 'd', 'd'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '6', '9', '3', '7', 'A', 'd', 'd'> >
 : textEncodingType<text_encoding_id_ISO6937Add_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '6', '9', '3', '7', '-', '2', '-', '2', '5'> >
 : textEncodingType<text_encoding_id_ISO6937Add_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '2'> >
 : textEncodingType<text_encoding_id_ISO6937Add_t>
 {
 };
}
#endif

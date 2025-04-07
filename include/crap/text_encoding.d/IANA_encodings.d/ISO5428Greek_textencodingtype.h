#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO5428GREEKTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO5428GREEKTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO5428Greek_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO5428Greek>;

 template <>
 struct textEncodingType<text_encoding_id_ISO5428Greek_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO5428Greek_t;
  using name = string<char, 'I', 'S', 'O', '_', '5', '4', '2', '8', ':', '1', '9', '8', '0'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '_', '5', '4', '2', '8', ':', '1', '9', '8', '0'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '5', '5'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '5', '4', '2', '8', 'G', 'r', 'e', 'e', 'k'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '5', '4', '2', '8', 'G', 'r', 'e', 'e', 'k'> >
 : textEncodingType<text_encoding_id_ISO5428Greek_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '5', '4', '2', '8', ':', '1', '9', '8', '0'> >
 : textEncodingType<text_encoding_id_ISO5428Greek_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '5', '5'> >
 : textEncodingType<text_encoding_id_ISO5428Greek_t>
 {
 };
}
#endif

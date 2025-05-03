#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO123CSAZ24341985GRTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO123CSAZ24341985GRTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO123CSAZ24341985gr_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO123CSAZ24341985gr>;

 template <>
 struct textEncodingType<text_encoding_id_ISO123CSAZ24341985gr_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO123CSAZ24341985gr_t;
  using name = string<char, 'C', 'S', 'A', '_', 'Z', '2', '4', '3', '.', '4', '-', '1', '9', '8', '5', '-', 'g', 'r'>;
  using aliases = typeList<
      string<char, 'C', 'S', 'A', '_', 'Z', '2', '4', '3', '.', '4', '-', '1', '9', '8', '5', '-', 'g', 'r'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '2', '3'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '2', '3', 'C', 'S', 'A', 'Z', '2', '4', '3', '4', '1', '9', '8', '5', 'g', 'r'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'S', 'A', '_', 'Z', '2', '4', '3', '.', '4', '-', '1', '9', '8', '5', '-', 'g', 'r'> >
 : textEncodingType<text_encoding_id_ISO123CSAZ24341985gr_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '2', '3', 'C', 'S', 'A', 'Z', '2', '4', '3', '4', '1', '9', '8', '5', 'g', 'r'> >
 : textEncodingType<text_encoding_id_ISO123CSAZ24341985gr_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '2', '3'> >
 : textEncodingType<text_encoding_id_ISO123CSAZ24341985gr_t>
 {
 };
}
#endif

#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO42JISC62261978TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO42JISC62261978TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO42JISC62261978_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO42JISC62261978>;

 template <>
 struct textEncodingType<text_encoding_id_ISO42JISC62261978_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO42JISC62261978_t;
  using name = string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '6', '-', '1', '9', '7', '8'>;
  using aliases = typeList<
      string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '6', '-', '1', '9', '7', '8'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '4', '2'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '4', '2', 'J', 'I', 'S', 'C', '6', '2', '2', '6', '1', '9', '7', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '4', '2', 'J', 'I', 'S', 'C', '6', '2', '2', '6', '1', '9', '7', '8'> >
 : textEncodingType<text_encoding_id_ISO42JISC62261978_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '4', '2'> >
 : textEncodingType<text_encoding_id_ISO42JISC62261978_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '6', '-', '1', '9', '7', '8'> >
 : textEncodingType<text_encoding_id_ISO42JISC62261978_t>
 {
 };
}
#endif

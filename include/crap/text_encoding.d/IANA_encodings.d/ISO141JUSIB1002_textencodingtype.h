#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO141JUSIB1002TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO141JUSIB1002TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO141JUSIB1002_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO141JUSIB1002>;

 template <>
 struct textEncodingType<text_encoding_id_ISO141JUSIB1002_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO141JUSIB1002_t;
  using name = string<char, 'J', 'U', 'S', '_', 'I', '.', 'B', '1', '.', '0', '0', '2'>;
  using aliases = typeList<
      string<char, 'J', 'U', 'S', '_', 'I', '.', 'B', '1', '.', '0', '0', '2'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '1'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'Y', 'U'>,
      string<char, 'j', 's'>,
      string<char, 'y', 'u'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '4', '1', 'J', 'U', 'S', 'I', 'B', '1', '0', '0', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '4', '1', 'J', 'U', 'S', 'I', 'B', '1', '0', '0', '2'> >
 : textEncodingType<text_encoding_id_ISO141JUSIB1002_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'Y', 'U'> >
 : textEncodingType<text_encoding_id_ISO141JUSIB1002_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '1'> >
 : textEncodingType<text_encoding_id_ISO141JUSIB1002_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'j', 's'> >
 : textEncodingType<text_encoding_id_ISO141JUSIB1002_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'U', 'S', '_', 'I', '.', 'B', '1', '.', '0', '0', '2'> >
 : textEncodingType<text_encoding_id_ISO141JUSIB1002_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'y', 'u'> >
 : textEncodingType<text_encoding_id_ISO141JUSIB1002_t>
 {
 };
}
#endif

#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO159JISX02121990TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO159JISX02121990TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO159JISX02121990_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO159JISX02121990>;

 template <>
 struct textEncodingType<text_encoding_id_ISO159JISX02121990_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO159JISX02121990_t;
  using name = string<char, 'J', 'I', 'S', '_', 'X', '0', '2', '1', '2', '-', '1', '9', '9', '0'>;
  using aliases = typeList<
      string<char, 'J', 'I', 'S', '_', 'X', '0', '2', '1', '2', '-', '1', '9', '9', '0'>,
      string<char, 'x', '0', '2', '1', '2'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '9'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '5', '9', 'J', 'I', 'S', 'X', '0', '2', '1', '2', '1', '9', '9', '0'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '5', '9', 'J', 'I', 'S', 'X', '0', '2', '1', '2', '1', '9', '9', '0'> >
 : textEncodingType<text_encoding_id_ISO159JISX02121990_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '9'> >
 : textEncodingType<text_encoding_id_ISO159JISX02121990_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'X', '0', '2', '1', '2', '-', '1', '9', '9', '0'> >
 : textEncodingType<text_encoding_id_ISO159JISX02121990_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'x', '0', '2', '1', '2'> >
 : textEncodingType<text_encoding_id_ISO159JISX02121990_t>
 {
 };
}
#endif

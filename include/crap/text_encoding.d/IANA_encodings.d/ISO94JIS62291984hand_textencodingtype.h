#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO94JIS62291984HANDTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO94JIS62291984HANDTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO94JIS62291984hand_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO94JIS62291984hand>;

 template <>
 struct textEncodingType<text_encoding_id_ISO94JIS62291984hand_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO94JIS62291984hand_t;
  using name = string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'h', 'a', 'n', 'd'>;
  using aliases = typeList<
      string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'h', 'a', 'n', 'd'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '4'>,
      string<char, 'j', 'p', '-', 'o', 'c', 'r', '-', 'h', 'a', 'n', 'd'>,
      string<char, 'c', 's', 'I', 'S', 'O', '9', '4', 'J', 'I', 'S', '6', '2', '2', '9', '1', '9', '8', '4', 'h', 'a', 'n', 'd'> >; //Looks like typo by IANA (C6229 vs 6229)
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '9', '4', 'J', 'I', 'S', '6', '2', '2', '9', '1', '9', '8', '4', 'h', 'a', 'n', 'd'> >
 : textEncodingType<text_encoding_id_ISO94JIS62291984hand_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '4'> >
 : textEncodingType<text_encoding_id_ISO94JIS62291984hand_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'h', 'a', 'n', 'd'> >
 : textEncodingType<text_encoding_id_ISO94JIS62291984hand_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'j', 'p', '-', 'o', 'c', 'r', '-', 'h', 'a', 'n', 'd'> >
 : textEncodingType<text_encoding_id_ISO94JIS62291984hand_t>
 {
 };
}
#endif

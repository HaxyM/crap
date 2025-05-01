#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO93JIS62291984BADDTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO93JIS62291984BADDTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO93JIS62291984badd_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO93JIS62291984badd>;

 template <>
 struct textEncodingType<text_encoding_id_ISO93JIS62291984badd_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO93JIS62291984badd_t;
  using name = string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'b', '-', 'a', 'd', 'd'>;
  using aliases = typeList<
      string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'b', '-', 'a', 'd', 'd'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '3'>,
      string<char, 'j', 'p', '-', 'o', 'c', 'r', '-', 'b', '-', 'a', 'd', 'd'>,
      string<char, 'c', 's', 'I', 'S', 'O', '9', '3', 'J', 'I', 'S', '6', '2', '2', '9', '1', '9', '8', '4', 'b', 'a', 'd', 'd'> >; //Looks like typo by IANA (C6229 vs 6229)
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '9', '3', 'J', 'I', 'S', '6', '2', '2', '9', '1', '9', '8', '4', 'b', 'a', 'd', 'd'> >
 : textEncodingType<text_encoding_id_ISO93JIS62291984badd_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '3'> >
 : textEncodingType<text_encoding_id_ISO93JIS62291984badd_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'b', '-', 'a', 'd', 'd'> >
 : textEncodingType<text_encoding_id_ISO93JIS62291984badd_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'j', 'p', '-', 'o', 'c', 'r', '-', 'b', '-', 'a', 'd', 'd'> >
 : textEncodingType<text_encoding_id_ISO93JIS62291984badd_t>
 {
 };
}
#endif

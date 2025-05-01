#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO95JIS62291984HANDADDTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO95JIS62291984HANDADDTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO95JIS62291984handadd_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO95JIS62291984handadd>;

 template <>
 struct textEncodingType<text_encoding_id_ISO95JIS62291984handadd_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO95JIS62291984handadd_t;
  using name = string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'h', 'a', 'n', 'd', '-', 'a', 'd', 'd'>;
  using aliases = typeList<
      string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'h', 'a', 'n', 'd', '-', 'a', 'd', 'd'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '5'>,
      string<char, 'j', 'p', '-', 'o', 'c', 'r', '-', 'h', 'a', 'n', 'd', '-', 'a', 'd', 'd'>,
      string<char, 'c', 's', 'I', 'S', 'O', '9', '5', 'J', 'I', 'S', '6', '2', '2', '9', '1', '9', '8', '4', 'h', 'a', 'n', 'd', 'a', 'd', 'd'> >; //Looks like typo by IANA (C6229 vs 6229)
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '9', '5', 'J', 'I', 'S', '6', '2', '2', '9', '1', '9', '8', '4', 'h', 'a', 'n', 'd', 'a', 'd', 'd'> >
 : textEncodingType<text_encoding_id_ISO95JIS62291984handadd_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '5'> >
 : textEncodingType<text_encoding_id_ISO95JIS62291984handadd_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'h', 'a', 'n', 'd', '-', 'a', 'd', 'd'> >
 : textEncodingType<text_encoding_id_ISO95JIS62291984handadd_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'j', 'p', '-', 'o', 'c', 'r', '-', 'h', 'a', 'n', 'd', '-', 'a', 'd', 'd'> >
 : textEncodingType<text_encoding_id_ISO95JIS62291984handadd_t>
 {
 };
}
#endif

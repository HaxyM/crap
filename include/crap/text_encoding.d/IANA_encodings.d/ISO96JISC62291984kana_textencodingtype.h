#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO96JISC62291984KANATEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO96JISC62291984KANATEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO96JISC62291984kana_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO96JISC62291984kana>;

 template <>
 struct textEncodingType<text_encoding_id_ISO96JISC62291984kana_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO96JISC62291984kana_t;
  using name = string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'k', 'a', 'n', 'a'>;
  using aliases = typeList<
      string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'k', 'a', 'n', 'a'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '6'>,
      string<char, 'c', 's', 'I', 'S', 'O', '9', '6', 'J', 'I', 'S', 'C', '6', '2', '2', '9', '1', '9', '8', '4', 'k', 'a', 'n', 'a'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '9', '6', 'J', 'I', 'S', 'C', '6', '2', '2', '9', '1', '9', '8', '4', 'k', 'a', 'n', 'a'> >
 : textEncodingType<text_encoding_id_ISO96JISC62291984kana_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '6'> >
 : textEncodingType<text_encoding_id_ISO96JISC62291984kana_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'k', 'a', 'n', 'a'> >
 : textEncodingType<text_encoding_id_ISO96JISC62291984kana_t>
 {
 };
}
#endif

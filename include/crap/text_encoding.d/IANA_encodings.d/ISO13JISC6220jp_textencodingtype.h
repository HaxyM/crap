#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO13JISC6220JPTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO13JISC6220JPTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO13JISC6220jp_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO13JISC6220jp>;

 template <>
 struct textEncodingType<text_encoding_id_ISO13JISC6220jp_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO13JISC6220jp_t;
  using name = string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '0', '-', '1', '9', '6', '9', '-', 'j', 'p'>;
  using aliases = typeList<
  	  string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '0', '-', '1', '9', '6', '9', '-', 'j', 'p'>,
      string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '0', '-', '1', '9', '6', '9'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '3'>,
      string<char, 'k', 'a', 't', 'a', 'k', 'a', 'n', 'a'>,
      string<char, 'x', '0', '2', '0', '1', '-', '7'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '1', '3', 'J', 'I', 'S', 'C', '6', '2', '2', '0', 'j', 'p'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '3', 'J', 'I', 'S', 'C', '6', '2', '2', '0', 'j', 'p'> >
 : textEncodingType<text_encoding_id_ISO13JISC6220jp_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '3'> >
 : textEncodingType<text_encoding_id_ISO13JISC6220jp_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '0', '-', '1', '9', '6', '9'> >
 : textEncodingType<text_encoding_id_ISO13JISC6220jp_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '0', '-', '1', '9', '6', '9', '-', 'j', 'p'> >
 : textEncodingType<text_encoding_id_ISO13JISC6220jp_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'k', 'a', 't', 'a', 'k', 'a', 'n', 'a'> >
 : textEncodingType<text_encoding_id_ISO13JISC6220jp_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'x', '0', '2', '0', '1', '-', '7'> >
 : textEncodingType<text_encoding_id_ISO13JISC6220jp_t>
 {
 };
}
#endif

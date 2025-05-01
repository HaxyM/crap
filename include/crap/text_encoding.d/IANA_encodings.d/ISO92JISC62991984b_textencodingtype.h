#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO92JISC62991984BTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO92JISC62991984BTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO92JISC62991984b_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO92JISC62991984b>;

 template <>
 struct textEncodingType<text_encoding_id_ISO92JISC62991984b_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO92JISC62991984b_t;
  using name = string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'b'>;
  using aliases = typeList<
      string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'b'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '2'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'J', 'P', '-', 'O', 'C', 'R', '-', 'B'>,
      string<char, 'j', 'p', '-', 'o', 'c', 'r', '-', 'b'>,
      string<char, 'c', 's', 'I', 'S', 'O', '9', '2', 'J', 'I', 'S', 'C', '6', '2', '9', '9', '1', '9', '8', '4', 'b'> >; //Looks like typo by IANA (C6229 vs C6299)
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '9', '2', 'J', 'I', 'S', 'C', '6', '2', '9', '9', '1', '9', '8', '4', 'b'> >
 : textEncodingType<text_encoding_id_ISO92JISC62991984b_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'J', 'P', '-', 'O', 'C', 'R', '-', 'B'> >
 : textEncodingType<text_encoding_id_ISO92JISC62991984b_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '2'> >
 : textEncodingType<text_encoding_id_ISO92JISC62991984b_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'b'> >
 : textEncodingType<text_encoding_id_ISO92JISC62991984b_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'j', 'p', '-', 'o', 'c', 'r', '-', 'b'> >
 : textEncodingType<text_encoding_id_ISO92JISC62991984b_t>
 {
 };
}
#endif

#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO14JISC6220ROTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO14JISC6220ROTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO14JISC6220ro_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO14JISC6220ro>;

 template <>
 struct textEncodingType<text_encoding_id_ISO14JISC6220ro_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO14JISC6220ro_t;
  using name = string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '0', '-', '1', '9', '6', '9', '-', 'r', 'o'>;
  using aliases = typeList<
  	  string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '0', '-', '1', '9', '6', '9', '-', 'r', 'o'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4'>,
      string<char, 'j', 'p'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'J', 'P'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '1', '4', 'J', 'I', 'S', 'C', '6', '2', '2', '0', 'r', 'o'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '4', 'J', 'I', 'S', 'C', '6', '2', '2', '0', 'r', 'o'> >
 : textEncodingType<text_encoding_id_ISO14JISC6220ro_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'J', 'P'> >
 : textEncodingType<text_encoding_id_ISO14JISC6220ro_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4'> >
 : textEncodingType<text_encoding_id_ISO14JISC6220ro_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '0', '-', '1', '9', '6', '9', '-', 'r', 'o'> >
 : textEncodingType<text_encoding_id_ISO14JISC6220ro_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'j', 'p'> >
 : textEncodingType<text_encoding_id_ISO14JISC6220ro_t>
 {
 };
}
#endif

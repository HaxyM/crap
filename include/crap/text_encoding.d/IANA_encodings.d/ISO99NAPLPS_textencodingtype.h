#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO99NAPLPSTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO99NAPLPSTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO99NAPLPS_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO99NAPLPS>;

 template <>
 struct textEncodingType<text_encoding_id_ISO99NAPLPS_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO99NAPLPS_t;
  using name = string<char, 'A', 'N', 'S', 'I', '_', 'X', '3', '.', '1', '1', '0', '-', '1', '9', '8', '3'>;
  using aliases = typeList<
      string<char, 'A', 'N', 'S', 'I', '_', 'X', '3', '.', '1', '1', '0', '-', '1', '9', '8', '3'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '9'>,
      string<char, 'C', 'S', 'A', '_', 'T', '5', '0', '0', '-', '1', '9', '8', '3'>,
      string<char, 'N', 'A', 'P', 'L', 'P', 'S'>,
      string<char, 'c', 's', 'I', 'S', 'O', '9', '9', 'N', 'A', 'P', 'L', 'P', 'S'> >;
 };

 template <>
 struct textEncodingType<string<char, 'A', 'N', 'S', 'I', '_', 'X', '3', '.', '1', '1', '0', '-', '1', '9', '8', '3'> >
 : textEncodingType<text_encoding_id_ISO99NAPLPS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'C', 'S', 'A', '_', 'T', '5', '0', '0', '-', '1', '9', '8', '3'> >
 : textEncodingType<text_encoding_id_ISO99NAPLPS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '9', '9', 'N', 'A', 'P', 'L', 'P', 'S'> >
 : textEncodingType<text_encoding_id_ISO99NAPLPS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '9'> >
 : textEncodingType<text_encoding_id_ISO99NAPLPS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'N', 'A', 'P', 'L', 'P', 'S'> >
 : textEncodingType<text_encoding_id_ISO99NAPLPS_t>
 {
 };
}
#endif

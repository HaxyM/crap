#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO84PORTUGUESE2TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO84PORTUGUESE2TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO84Portuguese2_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO84Portuguese2>;

 template <>
 struct textEncodingType<text_encoding_id_ISO84Portuguese2_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO84Portuguese2_t;
  using name = string<char, 'P', 'T', '2'>;
  using aliases = typeList<
      string<char, 'P', 'T', '2'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '4'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'P', 'T', '2'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '8', '4', 'P', 'o', 'r', 't', 'u', 'g', 'u', 'e', 's', 'e', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '4', 'P', 'o', 'r', 't', 'u', 'g', 'u', 'e', 's', 'e', '2'> >
 : textEncodingType<text_encoding_id_ISO84Portuguese2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'P', 'T', '2'> >
 : textEncodingType<text_encoding_id_ISO84Portuguese2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '4'> >
 : textEncodingType<text_encoding_id_ISO84Portuguese2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'P', 'T', '2'> >
 : textEncodingType<text_encoding_id_ISO84Portuguese2_t>
 {
 };
}
#endif

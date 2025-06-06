#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO103T618BITTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO103T618BITTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO103T618bit_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO103T618bit>;

 template <>
 struct textEncodingType<text_encoding_id_ISO103T618bit_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO103T618bit_t;
  using name = string<char, 'T', '.', '6', '1', '-', '8', 'b', 'i', 't'>;
  using aliases = typeList<
      string<char, 'T', '.', '6', '1', '-', '8', 'b', 'i', 't'>,
      string<char, 'T', '.', '6', '1'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '0', '3'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '0', '3', 'T', '6', '1', '8', 'b', 'i', 't'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '0', '3', 'T', '6', '1', '8', 'b', 'i', 't'> >
 : textEncodingType<text_encoding_id_ISO103T618bit_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '0', '3'> >
 : textEncodingType<text_encoding_id_ISO103T618bit_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'T', '.', '6', '1'> >
 : textEncodingType<text_encoding_id_ISO103T618bit_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'T', '.', '6', '1', '-', '8', 'b', 'i', 't'> >
 : textEncodingType<text_encoding_id_ISO103T618bit_t>
 {
 };
}
#endif

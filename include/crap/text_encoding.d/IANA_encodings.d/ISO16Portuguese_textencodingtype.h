#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO16PORTUGUESETEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO16PORTUGUESETEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO16Portuguese_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO16Portuguese>;

 template <>
 struct textEncodingType<text_encoding_id_ISO16Portuguese_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO16Portuguese_t;
  using name = string<char, 'P', 'T'>;
  using aliases = typeList<
  	  string<char, 'P', 'T'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '6'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'P', 'T'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '1', '6', 'P', 'o', 'r', 't', 'u', 'g', 'u', 'e', 's', 'e'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '6', 'P', 'o', 'r', 't', 'u', 'g', 'u', 'e', 's', 'e'> >
 : textEncodingType<text_encoding_id_ISO16Portuguese_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'P', 'T'> >
 : textEncodingType<text_encoding_id_ISO16Portuguese_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '6'> >
 : textEncodingType<text_encoding_id_ISO16Portuguese_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'P', 'T'> >
 : textEncodingType<text_encoding_id_ISO16Portuguese_t>
 {
 };
}
#endif

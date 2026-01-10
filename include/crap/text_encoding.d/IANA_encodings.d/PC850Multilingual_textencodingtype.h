#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_PC850MULTILINGUALTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_PC850MULTILINGUALTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_PC850Multilingual_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: PC850Multilingual>;

 template <>
 struct textEncodingType<text_encoding_id_PC850Multilingual_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_PC850Multilingual_t;
  using name = string<char, 'I', 'B', 'M', '8', '5', '0'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '5', '0'>,
      string<char, 'c', 'p', '8', '5', '0'>,
      string<char, '8', '5', '0'>,
      string<char, 'c', 's', 'P', 'C', '8', '5', '0', 'M', 'u', 'l', 't', 'i', 'l', 'i', 'n', 'g', 'u', 'a', 'l'> >;
 };

 template <>
 struct textEncodingType<string<char, '8', '5', '0'> >
 : textEncodingType<text_encoding_id_PC850Multilingual_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '5', '0'> >
 : textEncodingType<text_encoding_id_PC850Multilingual_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'P', 'C', '8', '5', '0', 'M', 'u', 'l', 't', 'i', 'l', 'i', 'n', 'g', 'u', 'a', 'l'> >
 : textEncodingType<text_encoding_id_PC850Multilingual_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '5', '0'> >
 : textEncodingType<text_encoding_id_PC850Multilingual_t>
 {
 };
}
#endif

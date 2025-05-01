#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO91JISC62291984ATEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO91JISC62291984ATEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO91JISC62291984a_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO91JISC62291984a>;

 template <>
 struct textEncodingType<text_encoding_id_ISO91JISC62291984a_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO91JISC62291984a_t;
  using name = string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'a'>;
  using aliases = typeList<
      string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'a'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '1'>,
      string<char, 'j', 'p', '-', 'o', 'c', 'r', '-', 'a'>,
      string<char, 'c', 's', 'I', 'S', 'O', '9', '1', 'J', 'I', 'S', 'C', '6', '2', '2', '9', '1', '9', '8', '4', 'a'> >;
	  
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '9', '1', 'J', 'I', 'S', 'C', '6', '2', '2', '9', '1', '9', '8', '4', 'a'> >
 : textEncodingType<text_encoding_id_ISO91JISC62291984a_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '9', '1'> >
 : textEncodingType<text_encoding_id_ISO91JISC62291984a_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '9', '-', '1', '9', '8', '4', '-', 'a'> >
 : textEncodingType<text_encoding_id_ISO91JISC62291984a_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'j', 'p', '-', 'o', 'c', 'r', '-', 'a'> >
 : textEncodingType<text_encoding_id_ISO91JISC62291984a_t>
 {
 };
}
#endif

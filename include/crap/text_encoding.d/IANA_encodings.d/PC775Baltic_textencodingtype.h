#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_PC775BALTICTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_PC775BALTICTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_PC775Baltic_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: PC775Baltic>;

 template <>    
 struct textEncodingType<text_encoding_id_PC775Baltic_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_PC775Baltic_t;
  using name = string<char, 'I', 'B', 'M', '7', '7', '5'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '7', '7', '5'>,
      string<char, 'c', 'p', '7', '7', '5'>,
      string<char, 'c', 's', 'P', 'C', '7', '7', '5', 'B', 'a', 'l', 't', 'i', 'c'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '7', '7', '5'> >
 : textEncodingType<text_encoding_id_PC775Baltic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'P', 'C', '7', '7', '5', 'B', 'a', 'l', 't', 'i', 'c'> >
 : textEncodingType<text_encoding_id_PC775Baltic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '7', '7', '5'> >
 : textEncodingType<text_encoding_id_PC775Baltic_t>
 {
 };
}
#endif

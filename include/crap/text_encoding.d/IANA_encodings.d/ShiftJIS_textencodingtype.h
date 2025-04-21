#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_SHIFTJISTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_SHIFTJISTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ShiftJIS_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ShiftJIS>;

 template <>
 struct textEncodingType<text_encoding_id_ShiftJIS_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ShiftJIS_t;
  using name = string<char, 'S', 'h', 'i', 'f', 't', '_', 'J', 'I', 'S'>;
  using aliases = typeList<
	  string<char, 'S', 'h', 'i', 'f', 't', '_', 'J', 'I', 'S'>,
	  string<char, 'M', 'S', '_', 'K', 'a', 'n', 'j', 'i'>,
      string<char, 'c', 's', 'S', 'h', 'i', 'f', 't', 'J', 'I', 'S'> >;
	  
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'S', 'h', 'i', 'f', 't', 'J', 'I', 'S'> >
 : textEncodingType<text_encoding_id_ShiftJIS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'M', 'S', '_', 'K', 'a', 'n', 'j', 'i'> >
 : textEncodingType<text_encoding_id_ShiftJIS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'S', 'h', 'i', 'f', 't', '_', 'J', 'I', 'S'> >
 : textEncodingType<text_encoding_id_ShiftJIS_t>
 {
 };
}
#endif

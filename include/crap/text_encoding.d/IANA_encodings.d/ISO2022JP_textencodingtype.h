#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO2022JPTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO2022JPTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO2022JP_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO2022JP>;

 template <>
 struct textEncodingType<text_encoding_id_ISO2022JP_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO2022JP_t;
  using name = string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'J', 'P'>;
  using aliases = typeList<
  	  string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'J', 'P'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '2', '0', '2', '2', 'J', 'P'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '2', '0', '2', '2', 'J', 'P'> >
 : textEncodingType<text_encoding_id_ISO2022JP_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '2', '0', '2', '2', '-', 'J', 'P'> >
 : textEncodingType<text_encoding_id_ISO2022JP_t>
 {
 };
}
#endif

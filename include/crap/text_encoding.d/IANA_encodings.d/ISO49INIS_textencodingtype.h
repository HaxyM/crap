#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO49INISTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO49INISTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO49INIS_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO49INIS>;

 template <>
 struct textEncodingType<text_encoding_id_ISO49INIS_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO49INIS_t;
  using name = string<char, 'I', 'N', 'I', 'S'>;
  using aliases = typeList<
      string<char, 'I', 'N', 'I', 'S'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '4', '9'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '4', '9', 'I', 'N', 'I', 'S'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '4', '9', 'I', 'N', 'I', 'S'> >
 : textEncodingType<text_encoding_id_ISO49INIS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'N', 'I', 'S'> >
 : textEncodingType<text_encoding_id_ISO49INIS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '4', '9'> >
 : textEncodingType<text_encoding_id_ISO49INIS_t>
 {
 };
}
#endif

#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO47BSVIEWDATATEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO47BSVIEWDATATEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO47BSViewdata_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO47BSViewdata>;

 template <>
 struct textEncodingType<text_encoding_id_ISO47BSViewdata_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO47BSViewdata_t;
  using name = string<char, 'B', 'S', '_', 'v', 'i', 'e', 'w', 'd', 'a', 't', 'a'>;
  using aliases = typeList<
      string<char, 'B', 'S', '_', 'v', 'i', 'e', 'w', 'd', 'a', 't', 'a'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '4', '7'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '4', '7', 'B', 'S', 'V', 'i', 'e', 'w', 'd', 'a', 't', 'a'> >;
 };

 template <>
 struct textEncodingType<string<char, 'B', 'S', '_', 'v', 'i', 'e', 'w', 'd', 'a', 't', 'a'> >
 : textEncodingType<text_encoding_id_ISO47BSViewdata_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '4', '7', 'B', 'S', 'V', 'i', 'e', 'w', 'd', 'a', 't', 'a'> >
 : textEncodingType<text_encoding_id_ISO47BSViewdata_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '4', '7'> >
 : textEncodingType<text_encoding_id_ISO47BSViewdata_t>
 {
 };
}
#endif

#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO21GERMANTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO21GERMANTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO21German_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO21German>;

 template <>
 struct textEncodingType<text_encoding_id_ISO21German_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO21German_t;
  using name = string<char, 'D', 'I', 'N', '_', '6', '6', '0', '0', '3'>;
  using aliases = typeList<
  	  string<char, 'D', 'I', 'N', '_', '6', '6', '0', '0', '3'>,
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '2', '1'>,
      string<char, 'd', 'e'>,
	  string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'D', 'E'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '2', '1', 'G', 'e', 'r', 'm', 'a', 'n'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '2', '1', 'G', 'e', 'r', 'm', 'a', 'n'> >
 : textEncodingType<text_encoding_id_ISO21German_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'd', 'e'> >
 : textEncodingType<text_encoding_id_ISO21German_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'D', 'I', 'N', '_', '6', '6', '0', '0', '3'> >
 : textEncodingType<text_encoding_id_ISO21German_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'D', 'E'> >
 : textEncodingType<text_encoding_id_ISO21German_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '2', '1'> >
 : textEncodingType<text_encoding_id_ISO21German_t>
 {
 };
}
#endif

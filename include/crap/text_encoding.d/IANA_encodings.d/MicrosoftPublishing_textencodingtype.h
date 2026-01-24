#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_MICROSOFTPUBLISHINGTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_MICROSOFTPUBLISHINGTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_MicrosoftPublishing_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: MicrosoftPublishing>;

 template <>
 struct textEncodingType<text_encoding_id_MicrosoftPublishing_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_MicrosoftPublishing_t;
  using name = string<char, 'M', 'i', 'c', 'r', 'o', 's', 'o', 'f', 't', '-', 'P', 'u', 'b', 'l', 'i', 's', 'h', 'i', 'n', 'g'>;
  using aliases = typeList<
      string<char, 'M', 'i', 'c', 'r', 'o', 's', 'o', 'f', 't', '-', 'P', 'u', 'b', 'l', 'i', 's', 'h', 'i', 'n', 'g'>,
      string<char, 'c', 's', 'M', 'i', 'c', 'r', 'o', 's', 'o', 'f', 't', 'P', 'u', 'b', 'l', 'i', 's', 'h', 'i', 'n', 'g'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'M', 'i', 'c', 'r', 'o', 's', 'o', 'f', 't', 'P', 'u', 'b', 'l', 'i', 's', 'h', 'i', 'n', 'g'> >
 : textEncodingType<text_encoding_id_MicrosoftPublishing_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'M', 'i', 'c', 'r', 'o', 's', 'o', 'f', 't', '-', 'P', 'u', 'b', 'l', 'i', 's', 'h', 'i', 'n', 'g'> >
 : textEncodingType<text_encoding_id_MicrosoftPublishing_t>
 {
 };
}
#endif

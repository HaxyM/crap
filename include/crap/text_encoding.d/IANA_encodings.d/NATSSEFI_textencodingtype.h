#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_NATSSEFITEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_NATSSEFITEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_NATSSEFI_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: NATSSEFI>;

 template <>
 struct textEncodingType<text_encoding_id_NATSSEFI_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_NATSSEFI_t;
  using name = string<char, 'N', 'A', 'T', 'S', '-', 'S', 'E', 'F', 'I'>;
  using aliases = typeList<
  	  string<char, 'N', 'A', 'T', 'S', '-', 'S', 'E', 'F', 'I'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '-', '1'>,
	  string<char, 'c', 's', 'N', 'A', 'T', 'S', 'S', 'E', 'F', 'I'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'N', 'A', 'T', 'S', 'S', 'E', 'F', 'I'> >
 : textEncodingType<text_encoding_id_NATSSEFI_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '-', '1'> >
 : textEncodingType<text_encoding_id_NATSSEFI_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'N', 'A', 'T', 'S', '-', 'S', 'E', 'F', 'I'> >
 : textEncodingType<text_encoding_id_NATSSEFI_t>
 {
 };
}
#endif

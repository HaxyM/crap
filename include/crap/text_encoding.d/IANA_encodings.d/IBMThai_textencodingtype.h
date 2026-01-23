#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBMTHAITEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBMTHAITEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBMThai_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBMThai>;

 template <>
 struct textEncodingType<text_encoding_id_IBMThai_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBMThai_t;
  using name = string<char, 'I', 'B', 'M', '-', 'T', 'h', 'a', 'i'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '-', 'T', 'h', 'a', 'i'>,
      string<char, 'c', 's', 'I', 'B', 'M', 'T', 'h', 'a', 'i'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', 'T', 'h', 'a', 'i'> >
 : textEncodingType<text_encoding_id_IBMThai_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '-', 'T', 'h', 'a', 'i'> >
 : textEncodingType<text_encoding_id_IBMThai_t>
 {
 };
}
#endif

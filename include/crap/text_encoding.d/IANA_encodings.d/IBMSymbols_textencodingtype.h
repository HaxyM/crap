#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBMSYMBOLSTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBMSYMBOLSTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBMSymbols_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBMSymbols>;

 template <>
 struct textEncodingType<text_encoding_id_IBMSymbols_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBMSymbols_t;
  using name = string<char, 'I', 'B', 'M', '-', 'S', 'y', 'm', 'b', 'o', 'l', 's'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '-', 'S', 'y', 'm', 'b', 'o', 'l', 's'>,
      string<char, 'c', 's', 'I', 'B', 'M', 'S', 'y', 'm', 'b', 'o', 'l', 's'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', 'S', 'y', 'm', 'b', 'o', 'l', 's'> >
 : textEncodingType<text_encoding_id_IBMSymbols_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '-', 'S', 'y', 'm', 'b', 'o', 'l', 's'> >
 : textEncodingType<text_encoding_id_IBMSymbols_t>
 {
 };
}
#endif

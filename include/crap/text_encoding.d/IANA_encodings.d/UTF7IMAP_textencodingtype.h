#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UTF7IMAPTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UTF7IMAPTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UTF7IMAP_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UTF7IMAP>;

 template <>
 struct textEncodingType<text_encoding_id_UTF7IMAP_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UTF7IMAP_t;
  using name = string<char, 'U', 'T', 'F', '-', '7', '-', 'I', 'M', 'A', 'P'>;
  using aliases = typeList<
      string<char, 'U', 'T', 'F', '-', '7', '-', 'I', 'M', 'A', 'P'>,
      string<char, 'c', 's', 'U', 'T', 'F', '7', 'I', 'M', 'A', 'P'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'T', 'F', '7', 'I', 'M', 'A', 'P'> >
 : textEncodingType<text_encoding_id_UTF7IMAP_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'U', 'T', 'F', '-', '7', '-', 'I', 'M', 'A', 'P'> >
 : textEncodingType<text_encoding_id_UTF7IMAP_t>
 {
 };
}
#endif

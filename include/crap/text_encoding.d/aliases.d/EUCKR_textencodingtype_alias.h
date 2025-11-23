#include <type_traits>

#include "../IANA_encodings.d/EUCKR_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_EUCKRTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_EUCKRTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'e', 'u', 'c', 'k', 'r'>
 : textEncodingType<text_encoding_id_EUCKR_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'u', 'c', 'k', 'r'>
 : textEncodingType<text_encoding_id_EUCKR_t>
 {
 };
}
#endif

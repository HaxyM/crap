#include <type_traits>

#include "../IANA_encodings.d/EBCDICFR_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_EBCDICFRTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_EBCDICFRTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'e', 'b', 'c', 'd', 'i', 'c', 'f', 'r'>
 : textEncodingType<text_encoding_id_EBCDICFR_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'f', 'r'>
 : textEncodingType<text_encoding_id_EBCDICFR_t>
 {
 };
}
#endif

#include <type_traits>

#include "../IANA_encodings.d/EBCDICUS_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_EBCDICUSTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_EBCDICUSTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'e', 'b', 'c', 'd', 'i', 'c', 'u', 's'>
 : textEncodingType<text_encoding_id_EBCDICUS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'u', 's'>
 : textEncodingType<text_encoding_id_EBCDICUS_t>
 {
 };
}
#endif

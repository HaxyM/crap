#include <type_traits>

#include "../IANA_encodings.d/EBCDICIT_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_EBCDICITTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_EBCDICITTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'e', 'b', 'c', 'd', 'i', 'c', 'i', 't'>
 : textEncodingType<text_encoding_id_EBCDICIT_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'i', 't'>
 : textEncodingType<text_encoding_id_EBCDICIT_t>
 {
 };
}
#endif

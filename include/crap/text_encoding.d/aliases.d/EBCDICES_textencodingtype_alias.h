#include <type_traits>

#include "../IANA_encodings.d/EBCDICES_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_EBCDICESTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_EBCDICESTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'e', 'b', 'c', 'd', 'i', 'c', 'e', 's'>
 : textEncodingType<text_encoding_id_EBCDICES_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'e', 's'>
 : textEncodingType<text_encoding_id_EBCDICES_t>
 {
 };
}
#endif

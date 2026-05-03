#include <type_traits>

#include "../IANA_encodings.d/EBCDICESA_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_EBCDICESATEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_EBCDICESATEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'e', 'b', 'c', 'd', 'i', 'c', 'e', 's', 'a'>
 : textEncodingType<text_encoding_id_EBCDICESA_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'e', 's', 'a'>
 : textEncodingType<text_encoding_id_EBCDICESA_t>
 {
 };
}
#endif

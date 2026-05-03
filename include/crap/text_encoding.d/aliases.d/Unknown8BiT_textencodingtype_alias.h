#include <type_traits>

#include "../IANA_encodings.d/Unknown8BiT_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UNKNOWN8BITTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UNKNOWN8BITTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 'n', 'k', 'n', 'o', 'w', 'n', '8', 'b', 'i', 't'>
 : textEncodingType<text_encoding_id_Unknown8BiT_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 'n', 'k', 'n', 'o', 'w', 'n', '8', 'b', 'i', 't'>
 : textEncodingType<text_encoding_id_Unknown8BiT_t>
 {
 };
}
#endif

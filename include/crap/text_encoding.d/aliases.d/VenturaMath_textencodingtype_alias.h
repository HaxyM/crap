#include <type_traits>

#include "../IANA_encodings.d/VenturaMath_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_VENTURAMATHTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_VENTURAMATHTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'v', 'e', 'n', 't', 'u', 'r', 'a', 'm', 'a', 't', 'h'>
 : textEncodingType<text_encoding_id_VenturaMath_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'v', 'e', 'n', 't', 'u', 'r', 'a', 'm', 'a', 't', 'h'>
 : textEncodingType<text_encoding_id_VenturaMath_t>
 {
 };
}
#endif

#include <type_traits>

#include "../IANA_encodings.d/OSDEBCDICDF041_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_OSDEBCDICDF041TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_OSDEBCDICDF041TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'o', 's', 'd', 'e', 'b', 'c', 'd', 'i', 'c', 'd', 'f', '4', '1'>
 : textEncodingType<text_encoding_id_OSDEBCDICDF041_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'o', 's', 'd', 'e', 'b', 'c', 'd', 'i', 'c', 'd', 'f', '4', '1'>
 : textEncodingType<text_encoding_id_OSDEBCDICDF041_t>
 {
 };
}
#endif

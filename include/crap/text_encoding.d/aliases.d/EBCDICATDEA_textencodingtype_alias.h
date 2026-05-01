#include <type_traits>

#include "../IANA_encodings.d/EBCDICATDEA_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_EBCDICATDEATEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_EBCDICATDEATEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'e', 'b', 'c', 'd', 'i', 'c', 'a', 't', 'd', 'e', 'a'>
 : textEncodingType<text_encoding_id_EBCDICATDEA_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'a', 't', 'd', 'e', 'a'>
 : textEncodingType<text_encoding_id_EBCDICATDEA_t>
 {
 };
}
#endif

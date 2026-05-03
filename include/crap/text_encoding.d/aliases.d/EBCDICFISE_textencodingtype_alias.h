#include <type_traits>

#include "../IANA_encodings.d/EBCDICFISE_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_EBCDICFISETEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_EBCDICFISETEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'e', 'b', 'c', 'd', 'i', 'c', 'f', 'i', 's', 'e'>
 : textEncodingType<text_encoding_id_EBCDICFISE_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'f', 'i', 's', 'e'>
 : textEncodingType<text_encoding_id_EBCDICFISE_t>
 {
 };
}
#endif

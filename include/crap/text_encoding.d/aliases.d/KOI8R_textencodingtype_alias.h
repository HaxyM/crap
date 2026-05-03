#include <type_traits>

#include "../IANA_encodings.d/KOI8R_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_KOI8RTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_KOI8RTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'k', 'o', 'i', '8', 'r'>
 : textEncodingType<text_encoding_id_KOI8R_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'k', 'o', 'i', '8', 'r'>
 : textEncodingType<text_encoding_id_KOI8R_t>
 {
 };
}
#endif

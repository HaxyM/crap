#include <type_traits>

#include "../IANA_encodings.d/KOI8U_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_KOI8UTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_KOI8UTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'k', 'o', 'i', '8', 'u'>
 : textEncodingType<text_encoding_id_KOI8U_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'k', 'o', 'i', '8', 'u'>
 : textEncodingType<text_encoding_id_KOI8U_t>
 {
 };
}
#endif

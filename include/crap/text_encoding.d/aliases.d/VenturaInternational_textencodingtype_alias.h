#include <type_traits>

#include "../IANA_encodings.d/VenturaInternational_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_VENTURAINTERNATIONALTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_VENTURAINTERNATIONALTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'v', 'e', 'n', 't', 'u', 'r', 'a', 'i', 'n', 't', 'e', 'r', 'n', 'a', 't', 'i', 'o', 'n', 'a', 'l'>
 : textEncodingType<text_encoding_id_VenturaInternational_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'v', 'e', 'n', 't', 'u', 'r', 'a', 'i', 'n', 't', 'e', 'r', 'n', 'a', 't', 'i', 'o', 'n', 'a', 'l'>
 : textEncodingType<text_encoding_id_VenturaInternational_t>
 {
 };
}
#endif

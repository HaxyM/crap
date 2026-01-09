#include <type_traits>

#include "../IANA_encodings.d/VenturaUS_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_VENTURAUSTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_VENTURAUSTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'v', 'e', 'n', 't', 'u', 'r', 'a', 'u', 's'>
 : textEncodingType<text_encoding_id_VenturaUS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'v', 'e', 'n', 't', 'u', 'r', 'a', 'u', 's'>
 : textEncodingType<text_encoding_id_VenturaUS_t>
 {
 };
}
#endif

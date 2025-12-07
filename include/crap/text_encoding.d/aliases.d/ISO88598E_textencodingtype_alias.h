#include <type_traits>

#include "../IANA_encodings.d/ISO88598E_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO88598ETEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO88598ETEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '8', '8', '5', '9', '8', 'e'>
 : textEncodingType<text_encoding_id_ISO88598E_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '8', 'e'>
 : textEncodingType<text_encoding_id_ISO88598E_t>
 {
 };
}
#endif

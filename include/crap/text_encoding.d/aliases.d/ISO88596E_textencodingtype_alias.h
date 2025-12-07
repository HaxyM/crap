#include <type_traits>

#include "../IANA_encodings.d/ISO88596E_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO88596ETEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO88596ETEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '8', '8', '5', '9', '6', 'e'>
 : textEncodingType<text_encoding_id_ISO88596E_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '6', 'e'>
 : textEncodingType<text_encoding_id_ISO88596E_t>
 {
 };
}
#endif

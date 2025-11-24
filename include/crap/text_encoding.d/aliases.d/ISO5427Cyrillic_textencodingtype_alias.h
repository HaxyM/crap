#include <type_traits>

#include "../IANA_encodings.d/ISO5427Cyrillic_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO5427CYRILLICTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO5427CYRILLICTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '5', '4', '2', '7', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>
 : textEncodingType<text_encoding_id_ISO5427Cyrillic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '5', '4', '2', '7'>
 : textEncodingType<text_encoding_id_ISO5427Cyrillic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '3', '7'>
 : textEncodingType<text_encoding_id_ISO5427Cyrillic_t>
 {
 };
}
#endif

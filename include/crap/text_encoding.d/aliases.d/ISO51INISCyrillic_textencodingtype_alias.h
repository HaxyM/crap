#include <type_traits>

#include "../IANA_encodings.d/ISO51INISCyrillic_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO51INISCYRILLICTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO51INISCYRILLICTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '5', '1', 'i', 'n', 'i', 's', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>
 : textEncodingType<text_encoding_id_ISO51INISCyrillic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'n', 'i', 's', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>
 : textEncodingType<text_encoding_id_ISO51INISCyrillic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '5', '1'>
 : textEncodingType<text_encoding_id_ISO51INISCyrillic_t>
 {
 };
}
#endif

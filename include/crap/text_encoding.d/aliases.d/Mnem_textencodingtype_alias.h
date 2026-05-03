#include <type_traits>

#include "../IANA_encodings.d/Mnem_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_MNEMTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_MNEMTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'm', 'n', 'e', 'm'>
 : textEncodingType<text_encoding_id_Mnem_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'm', 'n', 'e', 'm'>
 : textEncodingType<text_encoding_id_Mnem_t>
 {
 };
}
#endif

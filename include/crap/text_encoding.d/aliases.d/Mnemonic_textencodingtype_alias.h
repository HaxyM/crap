#include <type_traits>

#include "../IANA_encodings.d/Mnemonic_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_MNEMONICTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_MNEMONICTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'm', 'n', 'e', 'm', 'o', 'n', 'i', 'c'>
 : textEncodingType<text_encoding_id_Mnemonic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'm', 'n', 'e', 'm', 'o', 'n', 'i', 'c'>
 : textEncodingType<text_encoding_id_Mnemonic_t>
 {
 };
}
#endif

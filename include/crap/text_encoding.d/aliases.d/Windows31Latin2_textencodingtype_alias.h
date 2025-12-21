#include <type_traits>

#include "../IANA_encodings.d/Windows31Latin2_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_WINDOWS31LATIN2TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_WINDOWS31LATIN2TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'w', 'i', 'n', 'd', 'o', 'w', 's', '3', '1', 'l', 'a', 't', 'i', 'n', '2'>
 : textEncodingType<text_encoding_id_Windows31Latin2_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '2', 'w', 'i', 'n', 'd', 'o', 'w', 's', 'l', 'a', 't', 'i', 'n', '2'>
 : textEncodingType<text_encoding_id_Windows31Latin2_t>
 {
 };
}
#endif

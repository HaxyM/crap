#include <type_traits>

#include "../IANA_encodings.d/PC8DanishNorwegian_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_PC8DANISHNORWEGIANTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_PC8DANISHNORWEGIANTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'p', 'c', '8', 'd', 'a', 'n', 'i', 's', 'h', 'n', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n'>
 : textEncodingType<text_encoding_id_PC8DanishNorwegian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'p', 'c', '8', 'd', 'a', 'n', 'i', 's', 'h', 'n', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n'>
 : textEncodingType<text_encoding_id_PC8DanishNorwegian_t>
 {
 };
}
#endif

#include <type_traits>

#include "../IANA_encodings.d/KSC5636_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_KSC5636TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_KSC5636TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'k', 's', 'c', '5', '6', '3', '6'>
 : textEncodingType<text_encoding_id_KSC5636_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'k', 'r'>
 : textEncodingType<text_encoding_id_KSC5636_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'k', 's', 'c', '5', '6', '3', '6'>
 : textEncodingType<text_encoding_id_KSC5636_t>
 {
 };
}
#endif

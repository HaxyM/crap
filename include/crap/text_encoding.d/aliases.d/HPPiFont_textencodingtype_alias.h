#include <type_traits>

#include "../IANA_encodings.d/HPPiFont_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_HPPIFONTTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_HPPIFONTTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'h', 'p', 'p', 'i', 'f', 'o', 'n', 't'>
 : textEncodingType<text_encoding_id_HPPiFont_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'h', 'p', 'p', 'i', 'f', 'o', 'n', 't'>
 : textEncodingType<text_encoding_id_HPPiFont_t>
 {
 };
}
#endif

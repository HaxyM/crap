#include <type_traits>

#include "../IANA_encodings.d/ISO90_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO90TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO90TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '9', '0'>
 : textEncodingType<text_encoding_id_ISO90_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '9', '0'>
 : textEncodingType<text_encoding_id_ISO90_t>
 {
 };
}
#endif

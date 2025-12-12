#include <type_traits>

#include "../IANA_encodings.d/ISO885913_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO885913TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO885913TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '8', '8', '5', '9', '1', '3'>
 : textEncodingType<text_encoding_id_ISO885913_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '1', '3'>
 : textEncodingType<text_encoding_id_ISO885913_t>
 {
 };
}
#endif

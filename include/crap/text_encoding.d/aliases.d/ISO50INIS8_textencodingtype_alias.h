#include <type_traits>

#include "../IANA_encodings.d/ISO50INIS8_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO50INIS8TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO50INIS8TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '5', '0', 'i', 'n', 'i', 's', '8'>
 : textEncodingType<text_encoding_id_ISO50INIS8_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'n', 'i', 's', '8'>
 : textEncodingType<text_encoding_id_ISO50INIS8_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '5', '0'>
 : textEncodingType<text_encoding_id_ISO50INIS8_t>
 {
 };
}
#endif

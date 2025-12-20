#include <type_traits>

#include "../IANA_encodings.d/ISO115481_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO115481TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO115481TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '1', '5', '4', '8', '1'>
 : textEncodingType<text_encoding_id_ISO115481_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '1', '1', '5', '4', '8', '1'>
 : textEncodingType<text_encoding_id_ISO115481_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 't', 'r', '1', '1', '5', '4', '8', '1'>
 : textEncodingType<text_encoding_id_ISO115481_t>
 {
 };
}
#endif

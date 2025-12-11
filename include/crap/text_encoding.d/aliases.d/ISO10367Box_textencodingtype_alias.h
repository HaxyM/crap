#include <type_traits>

#include "../IANA_encodings.d/ISO10367Box_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO10367BOXTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO10367BOXTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '0', '3', '6', '7', 'b', 'o', 'x'>
 : textEncodingType<text_encoding_id_ISO10367Box_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '1', '0', '3', '6', '7', 'b', 'o', 'x'>
 : textEncodingType<text_encoding_id_ISO10367Box_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '5', '5'>
 : textEncodingType<text_encoding_id_ISO10367Box_t>
 {
 };
}
#endif

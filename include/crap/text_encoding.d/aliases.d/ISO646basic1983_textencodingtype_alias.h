#include <type_traits>

#include "../IANA_encodings.d/ISO646basic1983_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO646BASIC1983TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO646BASIC1983TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '6', '4', '6', 'b', 'a', 's', 'i', 'c', '1', '9', '8', '3'>
 : textEncodingType<text_encoding_id_ISO646basic1983_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'b', 'a', 's', 'i', 'c', '1', '9', '8', '3'>
 : textEncodingType<text_encoding_id_ISO646basic1983_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'r', 'e', 'f'>
 : textEncodingType<text_encoding_id_ISO646basic1983_t>
 {
 };
}
#endif

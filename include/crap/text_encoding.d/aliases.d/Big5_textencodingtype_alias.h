#include <type_traits>

#include "../IANA_encodings.d/Big5_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_BIG5TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_BIG5TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'b', 'i', 'g', '5'>
 : textEncodingType<text_encoding_id_Big5_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'b', 'i', 'g', '5'>
 : textEncodingType<text_encoding_id_Big5_t>
 {
 };
}
#endif

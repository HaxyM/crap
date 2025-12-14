#include <type_traits>

#include "../IANA_encodings.d/ISO885915_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO885915TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO885915TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '8', '8', '5', '9', '1', '5'>
 : textEncodingType<text_encoding_id_ISO885915_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '1', '5'>
 : textEncodingType<text_encoding_id_ISO885915_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', 'a', 't', 'i', 'n', '9'>
 : textEncodingType<text_encoding_id_ISO885915_t>
 {
 };
}
#endif

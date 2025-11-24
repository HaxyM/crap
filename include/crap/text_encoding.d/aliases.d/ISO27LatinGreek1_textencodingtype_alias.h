#include <type_traits>

#include "../IANA_encodings.d/ISO27LatinGreek1_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO27LATINGREEK1TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO27LATINGREEK1TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '2', '7', 'l', 'a', 't', 'i', 'n', 'g', 'r', 'e', 'e', 'k', '1'>
 : textEncodingType<text_encoding_id_ISO27LatinGreek1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '2', '7'>
 : textEncodingType<text_encoding_id_ISO27LatinGreek1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', 'a', 't', 'i', 'n', 'g', 'r', 'e', 'e', 'k', '1'>
 : textEncodingType<text_encoding_id_ISO27LatinGreek1_t>
 {
 };
}
#endif

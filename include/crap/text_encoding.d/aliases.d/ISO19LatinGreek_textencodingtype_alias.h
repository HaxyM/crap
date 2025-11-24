#include <type_traits>

#include "../IANA_encodings.d/ISO19LatinGreek_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO19LATINGREEKTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO19LATINGREEKTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '9', 'l', 'a', 't', 'i', 'n', 'g', 'r', 'e', 'e', 'k'>
 : textEncodingType<text_encoding_id_ISO19LatinGreek_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '9'>
 : textEncodingType<text_encoding_id_ISO19LatinGreek_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', 'a', 't', 'i', 'n', 'g', 'r', 'e', 'e', 'k'>
 : textEncodingType<text_encoding_id_ISO19LatinGreek_t>
 {
 };
}
#endif

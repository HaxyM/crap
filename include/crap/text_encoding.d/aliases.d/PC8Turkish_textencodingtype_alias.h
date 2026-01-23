#include <type_traits>

#include "../IANA_encodings.d/PC8Turkish_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_PC8TURKISHTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_PC8TURKISHTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'p', 'c', '8', 't', 'u', 'r', 'k', 'i', 's', 'h'>
 : textEncodingType<text_encoding_id_PC8Turkish_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'p', 'c', '8', 't', 'u', 'r', 'k', 'i', 's', 'h'>
 : textEncodingType<text_encoding_id_PC8Turkish_t>
 {
 };
}
#endif

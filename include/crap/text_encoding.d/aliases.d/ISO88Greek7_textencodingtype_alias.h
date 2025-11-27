#include <type_traits>

#include "../IANA_encodings.d/ISO88Greek7_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO88GREEK7TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO88GREEK7TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '8', '8', 'g', 'r', 'e', 'e', 'k', '7'>
 : textEncodingType<text_encoding_id_ISO88Greek7_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'g', 'r', 'e', 'e', 'k', '7'>
 : textEncodingType<text_encoding_id_ISO88Greek7_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '8', '8'>
 : textEncodingType<text_encoding_id_ISO88Greek7_t>
 {
 };
}
#endif

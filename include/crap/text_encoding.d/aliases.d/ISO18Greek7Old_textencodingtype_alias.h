#include <type_traits>

#include "../IANA_encodings.d/ISO18Greek7Old_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO18GREEK7OLDTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO18GREEK7OLDTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '8', 'g', 'r', 'e', 'e', 'k', '7', 'o', 'l', 'd'>
 : textEncodingType<text_encoding_id_ISO18Greek7Old_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'g', 'r', 'e', 'e', 'k', '7', 'o', 'l', 'd'>
 : textEncodingType<text_encoding_id_ISO18Greek7Old_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '8'>
 : textEncodingType<text_encoding_id_ISO18Greek7Old_t>
 {
 };
}
#endif

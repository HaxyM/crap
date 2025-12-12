#include <type_traits>

#include "../IANA_encodings.d/ISO2022CNEXT_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO2022CNEXTTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO2022CNEXTTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '2', '0', '2', '2', 'c', 'n', 'e', 'x', 't'>
 : textEncodingType<text_encoding_id_ISO2022CNEXT_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '2', '0', '2', '2', 'c', 'n', 'e', 'x', 't'>
 : textEncodingType<text_encoding_id_ISO2022CNEXT_t>
 {
 };
}
#endif

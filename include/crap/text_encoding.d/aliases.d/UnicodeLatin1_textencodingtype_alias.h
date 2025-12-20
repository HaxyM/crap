#include <type_traits>

#include "../IANA_encodings.d/UnicodeLatin1_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UNICODELATIN1TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UNICODELATIN1TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 'n', 'i', 'c', 'o', 'd', 'e', 'l', 'a', 't', 'i', 'n', '1'>
 : textEncodingType<text_encoding_id_UnicodeLatin1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '1', '0', '6', '4', '6'>
 : textEncodingType<text_encoding_id_UnicodeLatin1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '1', '0', '6', '4', '6', 'u', 'n', 'i', 'c', 'o', 'd', 'e', 'l', 'a', 't', 'i', 'n', '1'>
 : textEncodingType<text_encoding_id_UnicodeLatin1_t>
 {
 };
}
#endif

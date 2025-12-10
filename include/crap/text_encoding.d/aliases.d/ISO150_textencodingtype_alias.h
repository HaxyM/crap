#include <type_traits>

#include "../IANA_encodings.d/ISO150_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO150TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO150TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '5', '0'>
 : textEncodingType<text_encoding_id_ISO150_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '5', '0', 'g', 'r', 'e', 'e', 'k', 'c', 'c', 'i', 't', 't'>
 : textEncodingType<text_encoding_id_ISO150_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'g', 'r', 'e', 'e', 'k', 'c', 'c', 'i', 't', 't'>
 : textEncodingType<text_encoding_id_ISO150_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '5', '0'>
 : textEncodingType<text_encoding_id_ISO150_t>
 {
 };
}
#endif

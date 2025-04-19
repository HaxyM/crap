#include <type_traits>

#include "../IANA_encodings.d/ISOLatin6_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISOLATIN6TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISOLATIN6TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', 'l', 'a', 't', 'i', 'n', '6'>
 : textEncodingType<text_encoding_id_ISOLatin6_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '1', '0'>
 : textEncodingType<text_encoding_id_ISOLatin6_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '1', '0', '1', '9', '9', '2'>
 : textEncodingType<text_encoding_id_ISOLatin6_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '5', '7'>
 : textEncodingType<text_encoding_id_ISOLatin6_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', '6'>
 : textEncodingType<text_encoding_id_ISOLatin6_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', 'a', 't', 'i', 'n', '6'>
 : textEncodingType<text_encoding_id_ISOLatin6_t>
 {
 };
}
#endif

#include <type_traits>

#include "../IANA_encodings.d/ISOLatin5_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISOLATIN5TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISOLATIN5TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', 'l', 'a', 't', 'i', 'n', '5'>
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '9'>
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '9', '1', '9', '8', '9'>
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '4', '8'>
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', '5'>
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', 'a', 't', 'i', 'n', '5'>
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };
}
#endif

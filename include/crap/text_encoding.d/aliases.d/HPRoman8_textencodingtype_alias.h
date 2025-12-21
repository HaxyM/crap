#include <type_traits>

#include "../IANA_encodings.d/HPRoman8_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_HPROMAN8TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_HPROMAN8TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'h', 'p', 'r', 'o', 'm', 'a', 'n', '8'>
 : textEncodingType<text_encoding_id_HPRoman8_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'h', 'p', 'r', 'o', 'm', 'a', 'n', '8'>
 : textEncodingType<text_encoding_id_HPRoman8_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'r', '8'>
 : textEncodingType<text_encoding_id_HPRoman8_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'r', 'o', 'm', 'a', 'n', '8'>
 : textEncodingType<text_encoding_id_HPRoman8_t>
 {
 };
}
#endif

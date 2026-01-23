#include <type_traits>

#include "../IANA_encodings.d/PC862LatinHebrew_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_PC862LATINHEBREWTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_PC862LATINHEBREWTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, '8', '6', '2'>
 : textEncodingType<text_encoding_id_PC862LatinHebrew_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '8', '6', '2'>
 : textEncodingType<text_encoding_id_PC862LatinHebrew_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'p', 'c', '8', '6', '2', 'l', 'a', 't', 'i', 'n', 'h', 'e', 'b', 'r', 'e', 'w'>
 : textEncodingType<text_encoding_id_PC862LatinHebrew_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '8', '6', '2'>
 : textEncodingType<text_encoding_id_PC862LatinHebrew_t>
 {
 };
}
#endif

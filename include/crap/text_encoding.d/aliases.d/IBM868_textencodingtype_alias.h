#include <type_traits>

#include "../IANA_encodings.d/IBM868_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM868TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM868TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '8', '6', '8'>
 : textEncodingType<text_encoding_id_IBM868_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', 'a', 'r'>
 : textEncodingType<text_encoding_id_IBM868_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '6', '8'>
 : textEncodingType<text_encoding_id_IBM868_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '8', '6', '8'>
 : textEncodingType<text_encoding_id_IBM868_t>
 {
 };
}
#endif

#include <type_traits>

#include "../IANA_encodings.d/IBM918_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM918TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM918TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '9', '1', '8'>
 : textEncodingType<text_encoding_id_IBM918_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '9', '1', '8'>
 : textEncodingType<text_encoding_id_IBM918_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'p', 'a', 'r', '2'>
 : textEncodingType<text_encoding_id_IBM918_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '9', '1', '8'>
 : textEncodingType<text_encoding_id_IBM918_t>
 {
 };
}
#endif

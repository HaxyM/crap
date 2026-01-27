#include <type_traits>

#include "../IANA_encodings.d/IBM274_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM274TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM274TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '2', '7', '4'>
 : textEncodingType<text_encoding_id_IBM274_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '2', '7', '4'>
 : textEncodingType<text_encoding_id_IBM274_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'b', 'e'>
 : textEncodingType<text_encoding_id_IBM274_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '2', '7', '4'>
 : textEncodingType<text_encoding_id_IBM274_t>
 {
 };
}
#endif

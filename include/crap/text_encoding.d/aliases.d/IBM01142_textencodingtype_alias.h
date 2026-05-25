#include <type_traits>

#include "../IANA_encodings.d/IBM01142_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM01142TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM01142TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'c', 's', 'i', 'd', '1', '1', '4', '2'>
 : textEncodingType<text_encoding_id_IBM01142_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '1', '1', '4', '2'>
 : textEncodingType<text_encoding_id_IBM01142_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '1', '1', '4', '2'>
 : textEncodingType<text_encoding_id_IBM01142_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'd', 'k', '2', '7', '7', 'e', 'u', 'r', 'o'>
 : textEncodingType<text_encoding_id_IBM01142_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'n', 'o', '2', '7', '7', 'e', 'u', 'r', 'o'>
 : textEncodingType<text_encoding_id_IBM01142_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '1', '1', '4', '2'>
 : textEncodingType<text_encoding_id_IBM01142_t>
 {
 };
}
#endif

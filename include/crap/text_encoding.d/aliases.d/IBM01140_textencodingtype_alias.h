#include <type_traits>

#include "../IANA_encodings.d/IBM01140_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM01140TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM01140TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'c', 's', 'i', 'd', '1', '1', '4', '0'>
 : textEncodingType<text_encoding_id_IBM01140_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '1', '1', '4', '0'>
 : textEncodingType<text_encoding_id_IBM01140_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '1', '1', '4', '0'>
 : textEncodingType<text_encoding_id_IBM01140_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'u', 's', '3', '7', 'e', 'u', 'r', 'o'>
 : textEncodingType<text_encoding_id_IBM01140_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '1', '1', '4', '0'>
 : textEncodingType<text_encoding_id_IBM01140_t>
 {
 };
}
#endif

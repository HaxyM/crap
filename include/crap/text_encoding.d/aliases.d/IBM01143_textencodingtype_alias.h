#include <type_traits>

#include "../IANA_encodings.d/IBM01143_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM01143TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM01143TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'c', 's', 'i', 'd', '1', '1', '4', '3'>
 : textEncodingType<text_encoding_id_IBM01143_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '1', '1', '4', '3'>
 : textEncodingType<text_encoding_id_IBM01143_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '1', '1', '4', '3'>
 : textEncodingType<text_encoding_id_IBM01143_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'f', 'i', '2', '7', '8', 'e', 'u', 'r', 'o'>
 : textEncodingType<text_encoding_id_IBM01143_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 's', 'e', '2', '7', '8', 'e', 'u', 'r', 'o'>
 : textEncodingType<text_encoding_id_IBM01143_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '1', '1', '4', '3'>
 : textEncodingType<text_encoding_id_IBM01143_t>
 {
 };
}
#endif

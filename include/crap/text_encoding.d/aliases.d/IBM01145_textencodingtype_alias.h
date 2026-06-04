#include <type_traits>

#include "../IANA_encodings.d/IBM01145_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM01145TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM01145TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'c', 's', 'i', 'd', '1', '1', '4', '5'>
 : textEncodingType<text_encoding_id_IBM01145_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '1', '1', '4', '5'>
 : textEncodingType<text_encoding_id_IBM01145_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '1', '1', '4', '5'>
 : textEncodingType<text_encoding_id_IBM01145_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'e', 's', '2', '8', '4', 'e', 'u', 'r', 'o'>
 : textEncodingType<text_encoding_id_IBM01145_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '1', '1', '4', '5'>
 : textEncodingType<text_encoding_id_IBM01145_t>
 {
 };
}
#endif

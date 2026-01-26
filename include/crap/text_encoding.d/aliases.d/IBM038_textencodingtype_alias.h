#include <type_traits>

#include "../IANA_encodings.d/IBM038_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM038TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM038TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '3', '8'>
 : textEncodingType<text_encoding_id_IBM038_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '3', '8'>
 : textEncodingType<text_encoding_id_IBM038_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'i', 'n', 't'>
 : textEncodingType<text_encoding_id_IBM038_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '3', '8'>
 : textEncodingType<text_encoding_id_IBM038_t>
 {
 };
}
#endif

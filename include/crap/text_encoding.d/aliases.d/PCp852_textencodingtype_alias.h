#include <type_traits>

#include "../IANA_encodings.d/PCp852_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_PCP852TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_PCP852TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, '8', '5', '2'>
 : textEncodingType<text_encoding_id_PCp852_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '8', '5', '2'>
 : textEncodingType<text_encoding_id_PCp852_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'p', 'c', 'p', '8', '5', '2'>
 : textEncodingType<text_encoding_id_PCp852_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '8', '5', '2'>
 : textEncodingType<text_encoding_id_PCp852_t>
 {
 };
}
#endif

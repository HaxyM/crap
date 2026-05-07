#include <type_traits>

#include "../IANA_encodings.d/IBM00858_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM00858TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM00858TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'c', 's', 'i', 'd', '8', '5', '8'>
 : textEncodingType<text_encoding_id_IBM00858_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '8', '5', '8'>
 : textEncodingType<text_encoding_id_IBM00858_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '5', '8'>
 : textEncodingType<text_encoding_id_IBM00858_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '8', '5', '8'>
 : textEncodingType<text_encoding_id_IBM00858_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'p', 'c', 'm', 'u', 'l', 't', 'i', 'l', 'i', 'n', 'g', 'u', 'a', 'l', '8', '5', '0', 'e', 'u', 'r', 'o'>
 : textEncodingType<text_encoding_id_IBM00858_t>
 {
 };
}
#endif

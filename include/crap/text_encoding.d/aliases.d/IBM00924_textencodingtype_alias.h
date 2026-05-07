#include <type_traits>

#include "../IANA_encodings.d/IBM00924_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM00924TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM00924TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'c', 's', 'i', 'd', '9', '2', '4'>
 : textEncodingType<text_encoding_id_IBM00924_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '9', '2', '4'>
 : textEncodingType<text_encoding_id_IBM00924_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '9', '2', '4'>
 : textEncodingType<text_encoding_id_IBM00924_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'l', 'a', 't', 'i', 'n', '9', 'e', 'u', 'r', 'o'>
 : textEncodingType<text_encoding_id_IBM00924_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '9', '2', '4'>
 : textEncodingType<text_encoding_id_IBM00924_t>
 {
 };
}
#endif

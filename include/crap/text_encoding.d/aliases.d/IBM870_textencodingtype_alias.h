#include <type_traits>

#include "../IANA_encodings.d/IBM870_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM870TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM870TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '8', '7', '0'>
 : textEncodingType<text_encoding_id_IBM870_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '7', '0'>
 : textEncodingType<text_encoding_id_IBM870_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'p', 'r', 'o', 'e', 'c', 'e'>
 : textEncodingType<text_encoding_id_IBM870_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'p', 'y', 'u'>
 : textEncodingType<text_encoding_id_IBM870_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '8', '7', '0'>
 : textEncodingType<text_encoding_id_IBM870_t>
 {
 };
}
#endif

#include <type_traits>

#include "../IANA_encodings.d/IBM01144_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM01144TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM01144TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'c', 's', 'i', 'd', '1', '1', '4', '4'>
 : textEncodingType<text_encoding_id_IBM01144_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '1', '1', '4', '4'>
 : textEncodingType<text_encoding_id_IBM01144_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '1', '1', '4', '4'>
 : textEncodingType<text_encoding_id_IBM01144_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'i', 't', '2', '8', '0', 'e', 'u', 'r', 'o'>
 : textEncodingType<text_encoding_id_IBM01144_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '1', '1', '4', '4'>
 : textEncodingType<text_encoding_id_IBM01144_t>
 {
 };
}
#endif

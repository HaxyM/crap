#include <type_traits>

#include "../IANA_encodings.d/ISO89ASMO449_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO89ASMO449TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO89ASMO449TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'a', 's', 'm', 'o', '4', '4', '9'>
 : textEncodingType<text_encoding_id_ISO89ASMO449_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'a', 'r', 'a', 'b', 'i', 'c', '7'>
 : textEncodingType<text_encoding_id_ISO89ASMO449_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '8', '9', 'a', 's', 'm', 'o', '4', '4', '9'>
 : textEncodingType<text_encoding_id_ISO89ASMO449_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '9', '0', '3', '6'>
 : textEncodingType<text_encoding_id_ISO89ASMO449_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '8', '9'>
 : textEncodingType<text_encoding_id_ISO89ASMO449_t>
 {
 };
}
#endif

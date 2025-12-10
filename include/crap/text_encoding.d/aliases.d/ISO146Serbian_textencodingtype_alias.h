#include <type_traits>

#include "../IANA_encodings.d/ISO146Serbian_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO146SERBIANTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO146SERBIANTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '4', '6', 's', 'e', 'r', 'b', 'i', 'a', 'n'>
 : textEncodingType<text_encoding_id_ISO146Serbian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '4', '6'>
 : textEncodingType<text_encoding_id_ISO146Serbian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'u', 's', 'i', 'b', '1', '0', '0', '3', 's', 'e', 'r', 'b'>
 : textEncodingType<text_encoding_id_ISO146Serbian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 's', 'e', 'r', 'b', 'i', 'a', 'n'>
 : textEncodingType<text_encoding_id_ISO146Serbian_t>
 {
 };
}
#endif

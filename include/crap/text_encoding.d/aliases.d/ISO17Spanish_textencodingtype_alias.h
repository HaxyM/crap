#include <type_traits>

#include "../IANA_encodings.d/ISO17Spanish_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO17SPANISHTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO17SPANISHTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '7', 's', 'p', 'a', 'n', 'i', 's', 'h'>
 : textEncodingType<text_encoding_id_ISO17Spanish_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 's'>
 : textEncodingType<text_encoding_id_ISO17Spanish_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'e', 's'>
 : textEncodingType<text_encoding_id_ISO17Spanish_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '7'>
 : textEncodingType<text_encoding_id_ISO17Spanish_t>
 {
 };
}
#endif

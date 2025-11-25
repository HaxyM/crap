#include <type_traits>

#include "../IANA_encodings.d/ISO58GB231280_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO58GB231280TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO58GB231280TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'h', 'i', 'n', 'e', 's', 'e'>
 : textEncodingType<text_encoding_id_ISO58GB231280_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '5', '8', 'g', 'b', '2', '3', '1', '2', '8', '0'>
 : textEncodingType<text_encoding_id_ISO58GB231280_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'g', 'b', '2', '3', '1', '2', '8', '0'>
 : textEncodingType<text_encoding_id_ISO58GB231280_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '5', '8'>
 : textEncodingType<text_encoding_id_ISO58GB231280_t>
 {
 };
}
#endif

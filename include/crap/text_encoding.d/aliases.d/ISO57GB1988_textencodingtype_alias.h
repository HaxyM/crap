#include <type_traits>

#include "../IANA_encodings.d/ISO57GB1988_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO57GB1988TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO57GB1988TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'n'>
 : textEncodingType<text_encoding_id_ISO57GB1988_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '5', '7', 'g', 'b', '1', '9', '8', '8'>
 : textEncodingType<text_encoding_id_ISO57GB1988_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'g', 'b', '1', '9', '8', '8', '8', '0'>
 : textEncodingType<text_encoding_id_ISO57GB1988_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'c', 'n'>
 : textEncodingType<text_encoding_id_ISO57GB1988_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '5', '7'>
 : textEncodingType<text_encoding_id_ISO57GB1988_t>
 {
 };
}
#endif

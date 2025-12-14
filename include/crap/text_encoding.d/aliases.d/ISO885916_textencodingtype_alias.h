#include <type_traits>

#include "../IANA_encodings.d/ISO885916_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO885916TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO885916TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '8', '8', '5', '9', '1', '6'>
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '1', '6'>
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '1', '6', '2', '0', '0', '1'>
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '2', '2', '6'>
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', '1', '0'>
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', 'a', 't', 'i', 'n', '1', '0'>
 : textEncodingType<text_encoding_id_ISO885916_t>
 {
 };
}
#endif

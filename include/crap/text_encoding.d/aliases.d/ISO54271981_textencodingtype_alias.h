#include <type_traits>

#include "../IANA_encodings.d/ISO54271981_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO54271981TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO54271981TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '5', '4', '2', '7', '1', '9', '8', '1'>
 : textEncodingType<text_encoding_id_ISO54271981_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '5', '4', '2', '7', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c', '1', '9', '8', '1'>
 : textEncodingType<text_encoding_id_ISO54271981_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '5', '4', '2', '7', '1', '9', '8', '1'>
 : textEncodingType<text_encoding_id_ISO54271981_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '5', '4'>
 : textEncodingType<text_encoding_id_ISO54271981_t>
 {
 };
}
#endif

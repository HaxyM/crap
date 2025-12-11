#include <type_traits>

#include "../IANA_encodings.d/ISO153GOST1976874_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO153GOST1976874TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO153GOST1976874TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '5', '3', 'g', 'o', 's', 't', '1', '9', '7', '6', '8', '7', '4'>
 : textEncodingType<text_encoding_id_ISO153GOST1976874_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'g', 'o', 's', 't', '1', '9', '7', '6', '8', '7', '4'>
 : textEncodingType<text_encoding_id_ISO153GOST1976874_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '5', '3'>
 : textEncodingType<text_encoding_id_ISO153GOST1976874_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 's', 't', 's', 'e', 'v', '3', '5', '8', '8', '8'>
 : textEncodingType<text_encoding_id_ISO153GOST1976874_t>
 {
 };
}
#endif

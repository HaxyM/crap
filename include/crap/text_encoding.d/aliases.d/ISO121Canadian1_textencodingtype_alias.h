#include <type_traits>

#include "../IANA_encodings.d/ISO121Canadian1_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO121CANADIAN1TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO121CANADIAN1TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'a'>
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'a', 'z', '2', '4', '3', '4', '1', '9', '8', '5', '1'>
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'a', '7', '1'>
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '2', '1', 'c', 'a', 'n', 'a', 'd', 'i', 'a', 'n', '1'>
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'c', 'a'>
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '2', '1'>
 : textEncodingType<text_encoding_id_ISO121Canadian1_t>
 {
 };
}
#endif

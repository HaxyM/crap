#include <type_traits>

#include "../IANA_encodings.d/ISO141JUSIB1002_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO141JUSIB1002TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO141JUSIB1002TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '4', '1', 'j', 'u', 's', 'i', 'b', '1', '0', '0', '2'>
 : textEncodingType<text_encoding_id_ISO141JUSIB1002_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'y', 'u'>
 : textEncodingType<text_encoding_id_ISO141JUSIB1002_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '4', '1'>
 : textEncodingType<text_encoding_id_ISO141JUSIB1002_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 's'>
 : textEncodingType<text_encoding_id_ISO141JUSIB1002_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'u', 's', 'i', 'b', '1', '0', '0', '2'>
 : textEncodingType<text_encoding_id_ISO141JUSIB1002_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'y', 'u'>
 : textEncodingType<text_encoding_id_ISO141JUSIB1002_t>
 {
 };
}
#endif

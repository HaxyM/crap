#include <type_traits>

#include "../IANA_encodings.d/ISO86Hungarian_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO86HUNGARIANTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO86HUNGARIANTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '8', '6', 'h', 'u', 'n', 'g', 'a', 'r', 'i', 'a', 'n'>
 : textEncodingType<text_encoding_id_ISO86Hungarian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'h', 'u'>
 : textEncodingType<text_encoding_id_ISO86Hungarian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'h', 'u'>
 : textEncodingType<text_encoding_id_ISO86Hungarian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '8', '6'>
 : textEncodingType<text_encoding_id_ISO86Hungarian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'm', 's', 'z', '7', '7', '9', '5', '3'>
 : textEncodingType<text_encoding_id_ISO86Hungarian_t>
 {
 };
}
#endif

#include <type_traits>

#include "../IANA_encodings.d/ISO147Macedonian_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO147MACEDONIANTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO147MACEDONIANTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '4', '7', 'm', 'a', 'c', 'e', 'd', 'o', 'n', 'i', 'a', 'n'>
 : textEncodingType<text_encoding_id_ISO147Macedonian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '4', '7'>
 : textEncodingType<text_encoding_id_ISO147Macedonian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'u', 's', 'i', 'b', '1', '0', '0', '3', 'm', 'a', 'c'>
 : textEncodingType<text_encoding_id_ISO147Macedonian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'm', 'a', 'c', 'e', 'd', 'o', 'n', 'i', 'a', 'n'>
 : textEncodingType<text_encoding_id_ISO147Macedonian_t>
 {
 };
}
#endif

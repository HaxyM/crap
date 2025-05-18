#include <type_traits>

#include "../IANA_encodings.d/ISO60DanishNorwegian_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO60DANISHNORWEGIANTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO60DANISHNORWEGIANTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '6', '0', 'd', 'a', 'n', 'i', 's', 'h', 'n', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n'>
 : textEncodingType<text_encoding_id_ISO60DanishNorwegian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '6', '0', 'n', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n', '1'>
 : textEncodingType<text_encoding_id_ISO60DanishNorwegian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'n', 'o'>
 : textEncodingType<text_encoding_id_ISO60DanishNorwegian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '6', '0'>
 : textEncodingType<text_encoding_id_ISO60DanishNorwegian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'n', 'o'>
 : textEncodingType<text_encoding_id_ISO60DanishNorwegian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'n', 's', '4', '5', '5', '1', '1'>
 : textEncodingType<text_encoding_id_ISO60DanishNorwegian_t>
 {
 };
}
#endif

#include <type_traits>

#include "../IANA_encodings.d/ISO885914_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO885914TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO885914TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '8', '8', '5', '9', '1', '4'>
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '1', '4'>
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '1', '4', '1', '9', '9', '8'>
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'c', 'e', 'l', 't', 'i', 'c'>
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '9', '9'>
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', '8'>
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', 'a', 't', 'i', 'n', '8'>
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };
}
#endif

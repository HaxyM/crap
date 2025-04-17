#include <type_traits>

#include "../IANA_encodings.d/ISOLatin4_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISOLATIN4TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISOLATIN4TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', 'l', 'a', 't', 'i', 'n', '4'>
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '4'>
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '4', '1', '9', '8', '8'>
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '1', '0'>
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', '4'>
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', 'a', 't', 'i', 'n', '4'>
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };
}
#endif

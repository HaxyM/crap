#include <type_traits>

#include "../IANA_encodings.d/ISO2033_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO2033TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO2033TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '2', '0', '3', '3'>
 : textEncodingType<text_encoding_id_ISO2033_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', '1', '3', 'b'>
 : textEncodingType<text_encoding_id_ISO2033_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '2', '0', '3', '3', '1', '9', '8', '3'>
 : textEncodingType<text_encoding_id_ISO2033_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '9', '8'>
 : textEncodingType<text_encoding_id_ISO2033_t>
 {
 };
}
#endif

#include <type_traits>

#include "../IANA_encodings.d/IBM869_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM869TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM869TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, '8', '6', '9'>
 : textEncodingType<text_encoding_id_IBM869_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '8', '6', '9'>
 : textEncodingType<text_encoding_id_IBM869_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', 'g', 'r'>
 : textEncodingType<text_encoding_id_IBM869_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '6', '9'>
 : textEncodingType<text_encoding_id_IBM869_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '8', '6', '9'>
 : textEncodingType<text_encoding_id_IBM869_t>
 {
 };
}
#endif

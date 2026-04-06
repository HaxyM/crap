#include <type_traits>

#include "../IANA_encodings.d/IBM904_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM904TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM904TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, '9', '0', '4'>
 : textEncodingType<text_encoding_id_IBM904_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '9', '0', '4'>
 : textEncodingType<text_encoding_id_IBM904_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '9', '0', '4'>
 : textEncodingType<text_encoding_id_IBM904_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '9', '0', '4'>
 : textEncodingType<text_encoding_id_IBM904_t>
 {
 };
}
#endif

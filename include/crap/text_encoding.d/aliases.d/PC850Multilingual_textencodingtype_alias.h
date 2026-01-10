#include <type_traits>

#include "../IANA_encodings.d/PC850Multilingual_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_PC850MULTILINGUALTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_PC850MULTILINGUALTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, '8', '5', '0'>
 : textEncodingType<text_encoding_id_PC850Multilingual_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '8', '5', '0'>
 : textEncodingType<text_encoding_id_PC850Multilingual_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'p', 'c', '8', '5', '0', 'm', 'u', 'l', 't', 'i', 'l', 'i', 'n', 'g', 'u', 'a', 'l'>
 : textEncodingType<text_encoding_id_PC850Multilingual_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '8', '5', '0'>
 : textEncodingType<text_encoding_id_PC850Multilingual_t>
 {
 };
}
#endif

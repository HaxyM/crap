#include <type_traits>

#include "../IANA_encodings.d/GBK_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_GBKTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_GBKTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '9', '3', '6'>
 : textEncodingType<text_encoding_id_GBK_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'g', 'b', 'k'>
 : textEncodingType<text_encoding_id_GBK_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'g', 'b', 'k'>
 : textEncodingType<text_encoding_id_GBK_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'm', 's', '9', '3', '6'>
 : textEncodingType<text_encoding_id_GBK_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'w', 'i', 'n', 'd', 'o', 'w', 's', '9', '3', '6'>
 : textEncodingType<text_encoding_id_GBK_t>
 {
 };
}
#endif

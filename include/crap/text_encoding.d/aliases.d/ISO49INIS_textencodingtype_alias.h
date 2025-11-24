#include <type_traits>

#include "../IANA_encodings.d/ISO49INIS_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO49INISTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO49INISTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '4', '9', 'i', 'n', 'i', 's'>
 : textEncodingType<text_encoding_id_ISO49INIS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'n', 'i', 's'>
 : textEncodingType<text_encoding_id_ISO49INIS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '4', '9'>
 : textEncodingType<text_encoding_id_ISO49INIS_t>
 {
 };
}
#endif

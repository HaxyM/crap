#include <type_traits>

#include "../IANA_encodings.d/ISO96JISC62291984kana_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO96JISC62291984KANATEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO96JISC62291984KANATEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '9', '6', 'j', 'i', 's', 'c', '6', '2', '2', '9', '1', '9', '8', '4', 'k', 'a', 'n', 'a'>
 : textEncodingType<text_encoding_id_ISO96JISC62291984kana_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '9', '6'>
 : textEncodingType<text_encoding_id_ISO96JISC62291984kana_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'c', '6', '2', '2', '9', '1', '9', '8', '4', 'k', 'a', 'n', 'a'>
 : textEncodingType<text_encoding_id_ISO96JISC62291984kana_t>
 {
 };
}
#endif

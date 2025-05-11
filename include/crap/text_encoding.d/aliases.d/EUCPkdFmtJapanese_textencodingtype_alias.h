#include <type_traits>

#include "../IANA_encodings.d/EUCPkdFmtJapanese_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_EUCPKDFMTJAPANESETEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_EUCPKDFMTJAPANESETEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'e', 'u', 'c', 'p', 'k', 'd', 'f', 'm', 't', 'j', 'a', 'p', 'a', 'n', 'e', 's', 'e'>
 : textEncodingType<text_encoding_id_EUCPkdFmtJapanese_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'u', 'c', 'j', 'p'>
 : textEncodingType<text_encoding_id_EUCPkdFmtJapanese_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'x', 't', 'e', 'n', 'd', 'e', 'd', 'u', 'n', 'i', 'x', 'c', 'o', 'd', 'e', 'p', 'a', 'c', 'k', 'e', 'd', 'f', 'o', 'r', 'm', 'a', 't', 'f', 'o', 'r', 'j', 'a', 'p', 'a', 'n', 'e', 's', 'e'>
 : textEncodingType<text_encoding_id_EUCPkdFmtJapanese_t>
 {
 };
}
#endif

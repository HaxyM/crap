#include <type_traits>

#include "../IANA_encodings.d/ISO91JISC62291984a_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO91JISC62291984ATEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO91JISC62291984ATEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '9', '1', 'j', 'i', 's', 'c', '6', '2', '2', '9', '1', '9', '8', '4', 'a'>
 : textEncodingType<text_encoding_id_ISO91JISC62291984a_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '9', '1'>
 : textEncodingType<text_encoding_id_ISO91JISC62291984a_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'c', '6', '2', '2', '9', '1', '9', '8', '4', 'a'>
 : textEncodingType<text_encoding_id_ISO91JISC62291984a_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'p', 'o', 'c', 'r', 'a'>
 : textEncodingType<text_encoding_id_ISO91JISC62291984a_t>
 {
 };
}
#endif

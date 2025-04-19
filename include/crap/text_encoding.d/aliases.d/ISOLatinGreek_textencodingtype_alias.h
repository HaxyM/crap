#include <type_traits>

#include "../IANA_encodings.d/ISOLatinGreek_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISOLATINGREEKTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISOLATINGREEKTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', 'l', 'a', 't', 'i', 'n', 'g', 'r', 'e', 'e', 'k'>
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'c', 'm', 'a', '1', '1', '8'>
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'l', 'o', 't', '9', '2', '8'>
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'g', 'r', 'e', 'e', 'k'>
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'g', 'r', 'e', 'e', 'k', '8'>
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '7'>
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '7', '1', '9', '8', '7'>
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '2', '6'>
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };
}
#endif

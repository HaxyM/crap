#include <type_traits>

#include "../IANA_encodings.d/ISO159JISX02121990_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO159JISX02121990TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO159JISX02121990TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '5', '9', 'j', 'i', 's', 'x', '2', '1', '2', '1', '9', '9', '0'>
 : textEncodingType<text_encoding_id_ISO159JISX02121990_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '5', '9'>
 : textEncodingType<text_encoding_id_ISO159JISX02121990_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'x', '2', '1', '2', '1', '9', '9', '0'>
 : textEncodingType<text_encoding_id_ISO159JISX02121990_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'x', '2', '1', '2'>
 : textEncodingType<text_encoding_id_ISO159JISX02121990_t>
 {
 };
}
#endif

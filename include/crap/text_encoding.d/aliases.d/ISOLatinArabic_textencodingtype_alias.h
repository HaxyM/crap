#include <type_traits>

#include "../IANA_encodings.d/ISOLatinArabic_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISOLATINARABICTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISOLATINARABICTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'a', 'r', 'a', 'b', 'i', 'c'>
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'a', 's', 'm', 'o', '7', '0', '8'>
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', 'l', 'a', 't', 'i', 'n', 'a', 'r', 'a', 'b', 'i', 'c'>
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'c', 'm', 'a', '1', '1', '4'>
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '6'>
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '6', '1', '9', '8', '7'>
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '2', '7'>
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };
}
#endif

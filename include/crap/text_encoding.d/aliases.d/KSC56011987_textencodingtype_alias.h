#include <type_traits>

#include "../IANA_encodings.d/KSC56011987_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_KSC56011987TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_KSC56011987TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'k', 's', 'c', '5', '6', '0', '1', '1', '9', '8', '7'>
 : textEncodingType<text_encoding_id_KSC56011987_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '4', '9'>
 : textEncodingType<text_encoding_id_KSC56011987_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'k', 's', 'c', '5', '6', '0', '1'>
 : textEncodingType<text_encoding_id_KSC56011987_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'k', 's', 'c', '5', '6', '0', '1', '1', '9', '8', '7'>
 : textEncodingType<text_encoding_id_KSC56011987_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'k', 's', 'c', '5', '6', '0', '1', '1', '9', '8', '9'>
 : textEncodingType<text_encoding_id_KSC56011987_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'k', 'o', 'r', 'e', 'a', 'n'>
 : textEncodingType<text_encoding_id_KSC56011987_t>
 {
 };
}
#endif

#include <type_traits>

#include "../IANA_encodings.d/ISO87JISX0208_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO87JISX0208TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO87JISX0208TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '8', '7', 'j', 'i', 's', 'x', '2', '0', '8'>
 : textEncodingType<text_encoding_id_ISO87JISX0208_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '8', '7'>
 : textEncodingType<text_encoding_id_ISO87JISX0208_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'c', '6', '2', '2', '6', '1', '9', '8', '3'>
 : textEncodingType<text_encoding_id_ISO87JISX0208_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'x', '2', '0', '8', '1', '9', '8', '3'>
 : textEncodingType<text_encoding_id_ISO87JISX0208_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'x', '2', '0', '8'>
 : textEncodingType<text_encoding_id_ISO87JISX0208_t>
 {
 };
}
#endif

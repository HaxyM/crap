#include <type_traits>

#include "../IANA_encodings.d/ISO92JISC62991984b_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO92JISC62991984BTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO92JISC62991984BTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '9', '2', 'j', 'i', 's', 'c', '6', '2', '9', '9', '1', '9', '8', '4', 'b'>
 : textEncodingType<text_encoding_id_ISO92JISC62991984b_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'j', 'p', 'o', 'c', 'r', 'b'>
 : textEncodingType<text_encoding_id_ISO92JISC62991984b_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '9', '2'>
 : textEncodingType<text_encoding_id_ISO92JISC62991984b_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'c', '6', '2', '2', '9', '1', '9', '8', '4', 'b'>
 : textEncodingType<text_encoding_id_ISO92JISC62991984b_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'p', 'o', 'c', 'r', 'b'>
 : textEncodingType<text_encoding_id_ISO92JISC62991984b_t>
 {
 };
}
#endif

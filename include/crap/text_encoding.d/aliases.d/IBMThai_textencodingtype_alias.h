#include <type_traits>

#include "../IANA_encodings.d/IBMThai_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBMTHAITEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBMTHAITEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', 't', 'h', 'a', 'i'>
 : textEncodingType<text_encoding_id_IBMThai_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', 't', 'h', 'a', 'i'>
 : textEncodingType<text_encoding_id_IBMThai_t>
 {
 };
}
#endif

#include <type_traits>

#include "../IANA_encodings.d/IBMSymbols_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBMSYMBOLSTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBMSYMBOLSTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', 's', 'y', 'm', 'b', 'o', 'l', 's'>
 : textEncodingType<text_encoding_id_IBMSymbols_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', 's', 'y', 'm', 'b', 'o', 'l', 's'>
 : textEncodingType<text_encoding_id_IBMSymbols_t>
 {
 };
}
#endif

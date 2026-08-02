#include <type_traits>

#include "../IANA_encodings.d/Amiga1251_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_AMIGA1251TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_AMIGA1251TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder> //Looks like bug in libstdc++.
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'a', 'l', 'i', 'a', 's', 'e', 's'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'a', 'm', 'i', '1', '2', '5', '1'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'a', 'm', 'i', 'g', 'a', '1', '2', '5', '1'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder> //Looks like bug in libstdc++.
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'a', 'n', 'd'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder> //Looks like bug in libstdc++.
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'a', 'r', 'e'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder> //Looks like bug in libstdc++.
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'b', 'e'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'a', 'm', 'i', 'g', 'a', '1', '2', '5', '1'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder> //Looks like bug in libstdc++.
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'f', 'o', 'r'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder> //Looks like bug in libstdc++.
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'h', 'i', 's', 't', 'o', 'r', 'i', 'c', 'a', 'l'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder> //Looks like bug in libstdc++.
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'm', 'a', 'l', 'y', 's', 'h', 'e', 'v'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder> //Looks like bug in libstdc++.
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'n', 'o', 't'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder> //Looks like bug in libstdc++.
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'p', 'r', 'o', 'v', 'i', 'd', 'e', 'd'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder> //Looks like bug in libstdc++.
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'r', 'e', 'a', 's', 'o', 'n', 's'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder> //Looks like bug in libstdc++.
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 's', 'h', 'o', 'u', 'l', 'd'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder> //Looks like bug in libstdc++.
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 's', 'e', 'd'>
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };
}
#endif

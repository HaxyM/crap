#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_AMIGA1251TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_AMIGA1251TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_Amiga1251_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: Amiga1251>;

 template <>    
 struct textEncodingType<text_encoding_id_Amiga1251_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_Amiga1251_t;
  using name = string<char, 'A', 'm', 'i', 'g', 'a', '-', '1', '2', '5', '1'>;
  using aliases = typeList<
      string<char, 'A', 'm', 'i', 'g', 'a', '-', '1', '2', '5', '1'>,
      string<char, 'A', 'm', 'i', '1', '2', '5', '1'>,
      string<char, 'A', 'm', 'i', 'g', 'a', '1', '2', '5', '1'>,
      string<char, 'A', 'm', '1', '-', '1', '2', '5', 'q'>,
      string<char, 'c', 's', 'A', 'm', 'i', 'g', 'a', '1', '2', '5', '1'>,
      //Following looks like bug in libstdc++.
      string<char, '(', 'A', 'l', 'i', 'a', 's', 'e', 's'>,
      string<char, 'a', 'r', 'e'>,
      string<char, 'p', 'r', 'o', 'v', 'i', 'd', 'e', 'd'>,
      string<char, 'f', 'o', 'r'>,
      string<char, 'h', 'i', 's', 't', 'o', 'r', 'i', 'c', 'a', 'l'>,
      string<char, 'r', 'e', 'a', 's', 'o', 'n', 's'>,
      string<char, 'a', 'n', 'd'>,
      string<char, 's', 'h', 'o', 'u', 'l', 'd'>,
      string<char, 'n', 'o', 't'>,
      string<char, 'b', 'e'>,
      string<char, 'u', 's', 'e', 'd', ')'>,
      string<char, '[', 'M', 'a', 'l', 'y', 's', 'h', 'e', 'v', ']'> >;
 };

 template <> //Looks like bug in libstdc++.
 struct textEncodingType<string<char, '(', 'A', 'l', 'i', 'a', 's', 'e', 's'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <> //Looks like bug in libstdc++.
 struct textEncodingType<string<char, '[', 'M', 'a', 'l', 'y', 's', 'h', 'e', 'v', ']'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'A', 'm', 'i', '-', '1', '2', '5', '1'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'A', 'm', 'i', '1', '2', '5', '1'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'A', 'm', 'i', 'g', 'a', '-', '1', '2', '5', '1'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'A', 'm', 'i', 'g', 'a', '1', '2', '5', '1'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <> //Looks like bug in libstdc++.
 struct textEncodingType<string<char, 'a', 'n', 'd'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <> //Looks like bug in libstdc++.
 struct textEncodingType<string<char, 'a', 'r', 'e'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <> //Looks like bug in libstdc++.
 struct textEncodingType<string<char, 'b', 'e'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'A', 'm', 'i', 'g', 'a', '1', '2', '5', '1'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <> //Looks like bug in libstdc++.
 struct textEncodingType<string<char, 'f', 'o', 'r'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <> //Looks like bug in libstdc++.
 struct textEncodingType<string<char, 'h', 'i', 's', 't', 'o', 'r', 'i', 'c', 'a', 'l'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <> //Looks like bug in libstdc++.
 struct textEncodingType<string<char, 'n', 'o', 't'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <> //Looks like bug in libstdc++.
 struct textEncodingType<string<char, 'p', 'r', 'o', 'v', 'i', 'd', 'e', 'd'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <> //Looks like bug in libstdc++.
 struct textEncodingType<string<char, 'r', 'e', 'a', 's', 'o', 'n', 's'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <> //Looks like bug in libstdc++.
 struct textEncodingType<string<char, 's', 'h', 'o', 'u', 'l', 'd'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };

 template <> //Looks like bug in libstdc++.
 struct textEncodingType<string<char, 'u', 's', 'e', 'd', ')'> >
 : textEncodingType<text_encoding_id_Amiga1251_t>
 {
 };
}
#endif

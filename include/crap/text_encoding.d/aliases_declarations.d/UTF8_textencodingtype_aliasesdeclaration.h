#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASESDECLARATIONS_UTF8TEXTENCODINGTYPEALIASESDECLARATION
#define CRAP_TEXTENCODING_ALIASESDECLARATIONS_UTF8TEXTENCODINGTYPEALIASESDECLARATION

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 's', 'u', 't', 'f', '8'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'u', 't', 'f', '8'>;
#endif

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASESDECLARATIONS_BIG5TEXTENCODINGTYPEALIASESDECLARATION
#define CRAP_TEXTENCODING_ALIASESDECLARATIONS_BIG5TEXTENCODINGTYPEALIASESDECLARATION

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 's', 'b', 'i', 'g', '5'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'b', 'i', 'g', '5'>;
#endif

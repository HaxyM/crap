#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASESDECLARATIONS_IBM880TEXTENCODINGTYPEALIASESDECLARATION
#define CRAP_TEXTENCODING_ALIASESDECLARATIONS_IBM880TEXTENCODINGTYPEALIASESDECLARATION

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 'p', '8', '8', '0'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '8', '0'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'i', 'b', 'm', '8', '8', '0'>;
#endif

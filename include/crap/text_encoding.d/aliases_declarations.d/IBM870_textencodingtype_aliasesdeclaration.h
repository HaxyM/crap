#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASESDECLARATIONS_IBM870TEXTENCODINGTYPEALIASESDECLARATION
#define CRAP_TEXTENCODING_ALIASESDECLARATIONS_IBM870TEXTENCODINGTYPEALIASESDECLARATION

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 'p', '8', '7', '0'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '7', '0'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'p', 'r', 'o', 'e', 'c', 'e'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'p', 'y', 'u'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'i', 'b', 'm', '8', '7', '0'>;
#endif

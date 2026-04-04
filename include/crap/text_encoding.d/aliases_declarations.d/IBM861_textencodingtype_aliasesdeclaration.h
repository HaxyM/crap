#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASESDECLARATIONS_IBM861TEXTENCODINGTYPEALIASESDECLARATION
#define CRAP_TEXTENCODING_ALIASESDECLARATIONS_IBM861TEXTENCODINGTYPEALIASESDECLARATION

template <class PlaceHolder>
struct alias<PlaceHolder, char, '8', '6', '1'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 'p', '8', '6', '1'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 'p', 'i', 's'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '6', '1'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'i', 'b', 'm', '8', '6', '1'>;
#endif

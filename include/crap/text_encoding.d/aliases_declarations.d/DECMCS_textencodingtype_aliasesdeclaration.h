#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASESDECLARATIONS_DECMCSTEXTENCODINGTYPEALIASESDECLARATION
#define CRAP_TEXTENCODING_ALIASESDECLARATIONS_DECMCSTEXTENCODINGTYPEALIASESDECLARATION

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 's', 'd', 'e', 'c', 'm', 'c', 's'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'd', 'e', 'c'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'd', 'e', 'c', 'm', 'c', 's'>;
#endif

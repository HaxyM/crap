#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASESDECLARATIONS_IBM284TEXTENCODINGTYPEALIASESDECLARATION
#define CRAP_TEXTENCODING_ALIASESDECLARATIONS_IBM284TEXTENCODINGTYPEALIASESDECLARATION

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 'p', '2', '8', '4'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '2', '8', '4'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'p', 'e', 's'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'i', 'b', 'm', '2', '8', '4'>;
#endif

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASESDECLARATIONS_IBM851TEXTENCODINGTYPEALIASESDECLARATION
#define CRAP_TEXTENCODING_ALIASESDECLARATIONS_IBM851TEXTENCODINGTYPEALIASESDECLARATION

template <class PlaceHolder>
struct alias<PlaceHolder, char, '8', '5', '1'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 'p', '8', '5', '1'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '5', '1'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'i', 'b', 'm', '8', '5', '1'>;
#endif

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASESDECLARATIONS_IBM863TEXTENCODINGTYPEALIASESDECLARATION
#define CRAP_TEXTENCODING_ALIASESDECLARATIONS_IBM863TEXTENCODINGTYPEALIASESDECLARATION

template <class PlaceHolder>
struct alias<PlaceHolder, char, '8', '6', '3'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 'p', '8', '6', '3'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '6', '3'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'i', 'b', 'm', '8', '6', '3'>;
#endif

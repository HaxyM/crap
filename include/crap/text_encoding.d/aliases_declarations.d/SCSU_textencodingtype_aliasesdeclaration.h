#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASESDECLARATIONS_SCSUTEXTENCODINGTYPEALIASESDECLARATION
#define CRAP_TEXTENCODING_ALIASESDECLARATIONS_SCSUTEXTENCODINGTYPEALIASESDECLARATION

template <class PlaceHolder>
struct alias<PlaceHolder, char, 'c', 's', 's', 'c', 's', 'u'>;

template <class PlaceHolder>
struct alias<PlaceHolder, char, 's', 'c', 's', 'u'>;
#endif

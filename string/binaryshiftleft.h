#ifndef CRAP_STRING_BINARYSHIFTLEFT
#define CRAP_STRING_BINARYSHIFTLEFT

#include <ostream>

#include "string.h"

template <class Char, Char ... Letters>
inline std :: ostream& operator << (std :: ostream& stream, const crap :: string<Char, Letters...>& string)
{
 return (output << string.c_str());
}
#endif


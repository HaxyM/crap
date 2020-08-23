#ifndef CRAP_STRING_BINARYSHIFTLEFT
#define CRAP_STRING_BINARYSHIFTLEFT

#include <ostream>

#include "string.h"

template <class ostreamChar, class Char, Char ... Letters>
inline std :: basic_ostream<ostreamChar>& operator << (std :: basic_ostream<ostreamChar>& stream, const crap :: string<Char, Letters...>& string)
{
 return (output << string.c_str());
}
#endif


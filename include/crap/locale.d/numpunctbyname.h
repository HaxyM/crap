#ifndef CRAP_LOCALE_NUMPUNCTBYNAME
#define CRAP_LOCALE_NUMPUNCTBYNAME

#include "../string.d/string.h"

namespace crap
{
 template <class> struct numpunctByname;

 template <class CharType, CharType ... Chars>
	 struct locale <string<CharType, Char...> >
 {
  //TODO: Implement.
 };
}
#endif


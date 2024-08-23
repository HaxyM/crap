#include "../include/crap/locale.d/hasfacet.h"

#include <tuple>
#include <utility>

#include "../include/crap/locale.d/numpunct.h"

struct empty {};

template <class Type> struct testFacet
{
 using facet = Type;
};

template <class Type> void test_hasFacetNumpunct()
{
 static_assert(!(crap :: hasFacet <crap :: numpunct<Type>, void> :: value), "Void has no facet.");
}

int main()
{
 test_hasFacetNumpunct<char>();
 return EXIT_SUCCESS;
}

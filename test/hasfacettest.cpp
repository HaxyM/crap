#include "../include/crap/locale.d/hasfacet.h"

#include <cstdlib>
#include <functional>
#include <numeric>
#include <tuple>
#include <utility>

#include "../include/crap/locale.d/numpunct.h"

struct empty {};

template <class Type> struct withFacet
{
 using facet = Type;
};

template <class Type> bool test_hasFacetNumpunct()
{
 //Negative tests:
 //No facet tests.
 static_assert(!(crap :: hasFacet <std :: numpunct<Type>, void> :: value), "Void has no facet.");
 static_assert(!(crap :: hasFacet <std :: numpunct<Type>, empty> :: value), "Empty has no facet.");
 static_assert(!(crap :: hasFacet <crap :: numpunct<Type>, void> :: value), "Void has no facet.");
 static_assert(!(crap :: hasFacet <crap :: numpunct<Type>, empty> :: value), "Empty has no facet.");
 //Invalid facet tests.
 static_assert(!(crap :: hasFacet <crap :: numpunct<Type>, withFacet<void> > :: value), "Facet is void.");
 static_assert(!(crap :: hasFacet <crap :: numpunct<Type>, withFacet<empty> > :: value), "Facet is empty.");
 static_assert(!(crap :: hasFacet <crap :: numpunct<Type>, withFacet<std :: tuple<> > > :: value),
		 "Facet is not having numpunct.");
 static_assert(!(crap :: hasFacet <crap :: numpunct<Type>, withFacet<std :: tuple<void> > > :: value),
		 "Facet is not having numpunct.");
 static_assert(!(crap :: hasFacet <crap :: numpunct<Type>, withFacet<std :: pair<void, empty> > > :: value),
		 "Facet is not having numpunct.");
 static_assert(!(crap :: hasFacet <crap :: numpunct<Type>, withFacet<std :: tuple<void, empty, void> > > :: value),
		 "Facet is not having numpunct.");
 static_assert(!(crap :: hasFacet <crap :: numpunct<Type>, withFacet<std :: pair<crap :: numpunct<Type>, crap :: numpunct<Type>> > > :: value),
		 "Facet is having many numpunct.");
 static_assert(!(crap :: hasFacet <crap :: numpunct<Type>, withFacet<std :: tuple<crap :: numpunct<Type>, void, crap :: numpunct<Type>> > > :: value),
		 "Facet is having many numpunct.");
 //Positive tests:
 //Valid facet tests.
 static_assert(crap :: hasFacet <crap :: numpunct<Type>, withFacet<crap :: numpunct<Type> > > :: value, "Facet correct.");
 static_assert(crap :: hasFacet <crap :: numpunct<Type>, withFacet<std :: pair<crap :: numpunct<Type>, void> > > :: value,
		 "Facet correct.");
 static_assert(crap :: hasFacet <crap :: numpunct<Type>, withFacet<std :: tuple<void, crap :: numpunct<Type>, void> > > :: value,
		 "Facet correct.");
 return true;
}

int main()
{
 const bool results[] =
 {
	 test_hasFacetNumpunct<char>(),
	 test_hasFacetNumpunct<wchar_t>()
 };
 return std :: accumulate(std :: begin(results), std :: end(results), true, std :: logical_and<bool>())
	 ? EXIT_SUCCESS
	 : EXIT_FAILURE;
}

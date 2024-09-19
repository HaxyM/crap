#include "../include/crap/locale.d/hasfacet.h"

#include <cstdlib>
#include <functional>
#include <numeric>
#include <tuple>
#include <utility>

#include "../include/crap/locale.d/moneypunct.h"
#include "../include/crap/locale.d/numpunct.h"
#include "../include/crap/utility.d/typelist.h"

struct empty {};

template <class Type> struct withFacet
{
 using facet = Type;
};

template <class Type, template <class> class Facet> bool test_hasFacet()
{
 //Negative tests:
 //No facet tests.
 static_assert(!(crap :: hasFacet <Facet<Type>, void> :: value), "Void has no facet.");
 static_assert(!(crap :: hasFacet <Facet<Type>, empty> :: value), "Empty has no facet.");
 //Invalid facet tests.
 static_assert(!(crap :: hasFacet <Facet<Type>, withFacet<void> > :: value), "Facet is void.");
 static_assert(!(crap :: hasFacet <Facet<Type>, withFacet<empty> > :: value), "Facet is empty.");
 static_assert(!(crap :: hasFacet <Facet<Type>, withFacet<std :: tuple<> > > :: value),
		 "Facet is not having proper facet type.");
 static_assert(!(crap :: hasFacet <Facet<Type>, withFacet<crap :: typeList<> > > :: value),
		 "Facet is not having proper facet type.");
 static_assert(!(crap :: hasFacet <Facet<Type>, withFacet<std :: tuple<void> > > :: value),
		 "Facet is not having proper facet type.");
 static_assert(!(crap :: hasFacet <Facet<Type>, withFacet<crap :: typeList<void> > > :: value),
		 "Facet is not having proper facet type.");
 static_assert(!(crap :: hasFacet <Facet<Type>, withFacet<std :: pair<void, empty> > > :: value),
		 "Facet is not having proper facet type.");
 static_assert(!(crap :: hasFacet <Facet<Type>, withFacet<std :: tuple<void, empty, void> > > :: value),
		 "Facet is not having proper facet type.");
 static_assert(!(crap :: hasFacet <Facet<Type>, withFacet<crap :: typeList<void, empty, void> > > :: value),
		 "Facet is not having proper facet type.");
 static_assert(!(crap :: hasFacet <Facet<Type>, withFacet<std :: pair<Facet<Type>, Facet<Type> > > > :: value),
		 "Facet is having many proper facet types.");
 static_assert(!(crap :: hasFacet <Facet<Type>, withFacet<std :: tuple<Facet<Type>, void, Facet<Type> > > > :: value),
		 "Facet is having many proper facet types.");
 static_assert(!(crap :: hasFacet <Facet<Type>, withFacet<crap :: typeList<Facet<Type>, void, Facet<Type> > > > :: value),
		 "Facet is having many proper facet types.");
 //Positive tests:
 //Valid facet tests.
 static_assert(crap :: hasFacet <Facet<Type>, withFacet<Facet<Type> > > :: value, "Facet correct.");
 static_assert(crap :: hasFacet <Facet<Type>, withFacet<std :: pair<Facet<Type>, void> > > :: value,
		 "Facet correct.");
 static_assert(crap :: hasFacet <Facet<Type>, withFacet<std :: tuple<void, Facet<Type>, void> > > :: value,
		 "Facet correct.");
 static_assert(crap :: hasFacet <Facet<Type>, withFacet<crap :: typeList<void, Facet<Type>, void> > > :: value,
		 "Facet correct.");
 return true;
}

template <class Type> using moneypunctInternational = crap :: moneypunct<Type, true>;
template <class Type> using moneypunctShort = crap :: moneypunct<Type, false>;

int main()
{
 const bool results[] =
 {
	 test_hasFacet<char, moneypunctInternational>(),
	 test_hasFacet<wchar_t, moneypunctInternational>(),
	 test_hasFacet<char, moneypunctShort>(),
	 test_hasFacet<wchar_t, moneypunctShort>(),
	 test_hasFacet<char, crap :: numpunct>(),
	 test_hasFacet<wchar_t, crap :: numpunct>()
 };
 return std :: accumulate(std :: begin(results), std :: end(results), true, std :: logical_and<bool>())
	 ? EXIT_SUCCESS
	 : EXIT_FAILURE;
}

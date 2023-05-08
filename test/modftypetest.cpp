#include "../include/crap/cmath.d/modftype.h"
#include "../include/crap/ratio.d/modftype.h"

#include "iscompletetype.h"
#include <cstdlib>
#include <limits>
#include <type_traits>

int main()
{
 static_assert(!(isCompleteType <crap :: modfType<void> > :: value), "No logical sense for operation on type that does not represent any value.");

 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<-1, 2> > :: type, std :: ratio<-1, 2> >(), "Modf of -1/2 should be -1/2.");
 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<1, 2> > :: type, std :: ratio<1, 2> >(), "Modf of 1/2 should be 1/2.");
 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<0, 1> > :: type, std :: ratio<0, 1> >(), "Modf of 0 should be 0.");
 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<1, 1> > :: type, std :: ratio<0, 1> >(), "Modf of 1 should be 0.");
 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<-1, 1> > :: type, std :: ratio<0, 1> >(), "Modf of -1 should be 0.");

 static_assert(std :: is_same<typename crap :: modfType <crap :: valueRatio<unsigned int, '-', 1u, 2u> > :: type, crap :: valueRatio<unsigned int, '-', 1u, 2u> >(), "Modf of -1/2 should be -1/2.");
 static_assert(std :: is_same<typename crap :: modfType <crap :: valueRatio<unsigned int, '+', 1u, 2u> > :: type, crap :: valueRatio<unsigned int, '+', 1u, 2u> >(), "Modf of 1/2 should be 1/2.");
 static_assert(std :: is_same<typename crap :: modfType <crap :: valueRatio<unsigned int, '+', 0u, 1u> > :: type, crap :: valueRatio<unsigned int, '+', 0u, 1u> >(), "Modf of 0 should be 0.");
 static_assert(std :: is_same<typename crap :: modfType <crap :: valueRatio<unsigned int, '-', 0u, 1u> > :: type, crap :: valueRatio<unsigned int, '+', 0u, 1u> >(), "Modf of 0 should be 0.");
 static_assert(std :: is_same<typename crap :: modfType <crap :: valueRatio<unsigned int, '+', 1u, 1u> > :: type, crap :: valueRatio<unsigned int, '+', 0u, 1u> >(), "Modf of 1 should be 0.");
 static_assert(std :: is_same<typename crap :: modfType <crap :: valueRatio<unsigned int, '-', 1u, 1u> > :: type, crap :: valueRatio<unsigned int, '+', 0u, 1u> >(), "Modf of -1 should be 0.");

 //FIXME: Looks like std :: ratio having problems itself on edge cases :(
 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<(std :: numeric_limits <std :: intmax_t> :: min() + 1), 1> > :: type, std :: ratio<0, 1> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<(std :: numeric_limits <std :: intmax_t> :: min() + 1), (std :: numeric_limits <std :: intmax_t> :: min() + 1)> > :: type, std :: ratio<0, 1> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<(std :: numeric_limits <std :: intmax_t> :: min() + 1), std :: numeric_limits <std :: intmax_t> :: max()> > :: type, std :: ratio<0, 1> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<std :: numeric_limits <std :: intmax_t> :: max(), (std :: numeric_limits <std :: intmax_t> :: min() + 1)> > :: type, std :: ratio<0, 1> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<1, (std :: numeric_limits <std :: intmax_t> :: min() + 1)> > :: type, std :: ratio<-1, -(std :: numeric_limits <std :: intmax_t> :: min() + 1)> >(), "Should not fail on close to end of range values.");
 //XXX: Though those are fine. Strange :(
 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<std :: numeric_limits <std :: intmax_t> :: max(), 1> > :: type, std :: ratio<0, 1> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<std :: numeric_limits <std :: intmax_t> :: max(), std :: numeric_limits <std :: intmax_t> :: max()> > :: type, std :: ratio<0, 1> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: modfType <std :: ratio<1, std :: numeric_limits <std :: intmax_t> :: max()> > :: type, std :: ratio<1, std :: numeric_limits <std :: intmax_t> :: max()> >(), "Should not fail on close to end of range values.");

 static_assert(std :: is_same<typename crap :: modfType <crap :: valueRatio<unsigned int, '+', 1u, std :: numeric_limits <unsigned int> :: max()> > :: type, crap :: valueRatio<unsigned int, '+', 1u, std :: numeric_limits <unsigned int> :: max()> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: modfType <crap :: valueRatio<unsigned int, '-', 1u, std :: numeric_limits <unsigned int> :: max()> > :: type, crap :: valueRatio<unsigned int, '-', 1u, std :: numeric_limits <unsigned int> :: max()> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: modfType <crap :: valueRatio<unsigned int, '+', std :: numeric_limits <unsigned int> :: max(), std :: numeric_limits <unsigned int> :: max()> > :: type, crap :: valueRatio<unsigned int, '+', 0u, 1u> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: modfType <crap :: valueRatio<unsigned int, '-', std :: numeric_limits <unsigned int> :: max(), std :: numeric_limits <unsigned int> :: max()> > :: type, crap :: valueRatio<unsigned int, '+', 0u, 1u> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: modfType <crap :: valueRatio<unsigned int, '+', std :: numeric_limits <unsigned int> :: max(), 1u> > :: type, crap :: valueRatio<unsigned int, '+', 0u, 1u> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: modfType <crap :: valueRatio<unsigned int, '-', std :: numeric_limits <unsigned int> :: max(), 1u> > :: type, crap :: valueRatio<unsigned int, '+', 0u, 1u> >(), "Should not fail on close to end of range values.");

 return EXIT_SUCCESS;
}


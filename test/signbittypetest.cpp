#include "../include/crap/cmath.d/signbittype.h"
#include "../include/crap/ratio.d/signbittype.h"

#include "iscompletetype.h"
#include <cstdlib>
#include <limits>
#include <type_traits>

int main()
{
 static_assert(!(isCompleteType <crap :: signbitType<void> > :: value), "No logical sense for operation on type that does not represent any value.");

 static_assert(crap :: signbitType <std :: ratio<-1, 2> >(), "Signbit of -1/2 should be true.");
 static_assert(!crap :: signbitType <std :: ratio<1, 2> >(), "Signbit of 1/2 should be false.");
 static_assert(!crap :: signbitType <std :: ratio<0, 1> >(), "Signbit of 0 should be false.");
 static_assert(!crap :: signbitType <std :: ratio<1, 1> >(), "Signbit of 1 should be false.");
 static_assert(crap :: signbitType <std :: ratio<-1, 1> >(), "Signbit of -1 should be true.");

 static_assert(crap :: signbitType <crap :: valueRatio<int, '-', 1u, 2u> >(), "Signbit of -1/2 should be true.");
 static_assert(!crap :: signbitType <crap :: valueRatio<int, '+', 1u, 2u> >(), "Signbit of 1/2 should be false.");
 static_assert(!crap :: signbitType <crap :: valueRatio<int, '+', 0u, 1u> >(), "Signbit of 0 should be false.");
 static_assert(crap :: signbitType <crap :: valueRatio<int, '-', 0u, 1u> >(), "Signbit of -0 should be true.");
 static_assert(!crap :: signbitType <crap :: valueRatio<int, '+', 1u, 1u> >(), "Signbit of 1 should be false.");
 static_assert(crap :: signbitType <crap :: valueRatio<int, '-', 1u, 1u> >(), "Signbit of -1 should be true.");

 //FIXME: Looks like std :: ratio having problems itself on edge cases :(
 static_assert(crap :: signbitType <std :: ratio<(std :: numeric_limits <std :: intmax_t> :: min() + 1), 1> >(), "Should not fail on close to end of range values.");
 static_assert(!crap :: signbitType <std :: ratio<(std :: numeric_limits <std :: intmax_t> :: min() + 1), (std :: numeric_limits <std :: intmax_t> :: min() + 1)> >(), "Should not fail on close to end of range values.");
 static_assert(crap :: signbitType <std :: ratio<(std :: numeric_limits <std :: intmax_t> :: min() + 1), std :: numeric_limits <std :: intmax_t> :: max()> >(), "Should not fail on close to end of range values.");
 static_assert(crap :: signbitType <std :: ratio<std :: numeric_limits <std :: intmax_t> :: max(), (std :: numeric_limits <std :: intmax_t> :: min() + 1)> >(), "Should not fail on close to end of range values.");
 static_assert(crap :: signbitType <std :: ratio<1, (std :: numeric_limits <std :: intmax_t> :: min() + 1)> >(), "Should not fail on close to end of range values.");
 //XXX: Though those are fine. Strange :(
 static_assert(!crap :: signbitType <std :: ratio<std :: numeric_limits <std :: intmax_t> :: max(), 1> >(), "Should not fail on close to end of range values.");
 static_assert(!crap :: signbitType <std :: ratio<std :: numeric_limits <std :: intmax_t> :: max(), std :: numeric_limits <std :: intmax_t> :: max()> >(), "Should not fail on close to end of range values.");
 static_assert(!crap :: signbitType <std :: ratio<1, std :: numeric_limits <std :: intmax_t> :: max()> >(), "Should not fail on close to end of range values.");

 static_assert(!crap :: signbitType <crap :: valueRatio<int, '+', 1u, std :: numeric_limits <unsigned int> :: max()> >(), "Should not fail on close to end of range values.");
 static_assert(crap :: signbitType <crap :: valueRatio<int, '-', 1u, std :: numeric_limits <unsigned int> :: max()> >(), "Should not fail on close to end of range values.");
 static_assert(!crap :: signbitType <crap :: valueRatio<int, '+', std :: numeric_limits <unsigned int> :: max(), std :: numeric_limits <unsigned int> :: max()> >(), "Should not fail on close to end of range values.");
 static_assert(crap :: signbitType <crap :: valueRatio<int, '-', std :: numeric_limits <unsigned int> :: max(), std :: numeric_limits <unsigned int> :: max()> >(), "Should not fail on close to end of range values.");
 static_assert(!crap :: signbitType <crap :: valueRatio<int, '+', std :: numeric_limits <unsigned int> :: max(), 1u> >(), "Should not fail on close to end of range values.");
 static_assert(crap :: signbitType <crap :: valueRatio<int, '-', std :: numeric_limits <unsigned int> :: max(), 1u> >(), "Should not fail on close to end of range values.");

 return EXIT_SUCCESS;
}


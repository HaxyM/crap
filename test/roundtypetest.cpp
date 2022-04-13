#include "../include/crap/cmath.d/roundtype.h"
#include "../include/crap/ratio.d/roundtype.h"

#include "iscompletetype.h"
#include <cstdlib>
#include <limits>
#include <type_traits>

int main()
{
 static_assert(!(isCompleteType <crap :: roundType<void> > :: value), "No logical sense for operation on type that does not represent any value.");

 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<1, 3> > :: type, std :: ratio<0, 1> >(), "Round of 1/3 should be 0.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<-1, 3> > :: type, std :: ratio<0, 1> >(), "Round of -1/3 should be 0.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<2, 3> > :: type, std :: ratio<1, 1> >(), "Round of 2/3 should be 1.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<-2, 3> > :: type, std :: ratio<-1, 1> >(), "Round of -2/3 should be -1.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<1, 2> > :: type, std :: ratio<1, 1> >(), "Round of 1/2 should be 1.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<-1, 2> > :: type, std :: ratio<0, 1> >(), "Round of -1/2 should be 0.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<0, 1> > :: type, std :: ratio<0, 1> >(), "Round of 0 should be 0.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<1, 1> > :: type, std :: ratio<1, 1> >(), "Round of 1 should be 1.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<-1, 1> > :: type, std :: ratio<-1, 1> >(), "Round of -1 should be -1.");

 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '-', 1u, 2u> > :: type, crap :: valueRatio<int, '-', 0u, 1u> >(), "Round of -1/2 should be 0.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '+', 1u, 2u> > :: type, crap :: valueRatio<int, '+', 1u, 1u> >(), "Round of 1/2 should be 1.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '-', 1u, 3u> > :: type, crap :: valueRatio<int, '-', 0u, 1u> >(), "Round of -1/3 should be 0.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '+', 1u, 3u> > :: type, crap :: valueRatio<int, '+', 0u, 1u> >(), "Round of 1/3 should be 0.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '-', 2u, 3u> > :: type, crap :: valueRatio<int, '-', 1u, 1u> >(), "Round of -2/3 should be -1.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '+', 2u, 3u> > :: type, crap :: valueRatio<int, '+', 1u, 1u> >(), "Round of 2/3 should be 1.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '+', 0u, 1u> > :: type, crap :: valueRatio<int, '+', 0u, 1u> >(), "Round of 0 should be 0.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '-', 0u, 1u> > :: type, crap :: valueRatio<int, '-', 0u, 1u> >(), "Round of 0 should be 0.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '+', 1u, 1u> > :: type, crap :: valueRatio<int, '+', 1u, 1u> >(), "Round of 1 should be 1.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '-', 1u, 1u> > :: type, crap :: valueRatio<int, '-', 1u, 1u> >(), "Round of -1 should be -1.");

 //FIXME: Looks like std :: ratio having problems itself on edge cases :(
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<(std :: numeric_limits <std :: intmax_t> :: min() + 1), 1> > :: type, std :: ratio<(std :: numeric_limits <std :: intmax_t> :: min() + 1), 1> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<(std :: numeric_limits <std :: intmax_t> :: min() + 1), (std :: numeric_limits <std :: intmax_t> :: min() + 1)> > :: type, std :: ratio<1, 1> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<(std :: numeric_limits <std :: intmax_t> :: min() + 1), std :: numeric_limits <std :: intmax_t> :: max()> > :: type, std :: ratio<-1, 1> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<std :: numeric_limits <std :: intmax_t> :: max(), (std :: numeric_limits <std :: intmax_t> :: min() + 1)> > :: type, std :: ratio<-1, 1> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<1, (std :: numeric_limits <std :: intmax_t> :: min() + 1)> > :: type, std :: ratio<0, 1> >(), "Should not fail on close to end of range values.");
 //XXX: Though those are fine. Strange :(
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<std :: numeric_limits <std :: intmax_t> :: max(), 1> > :: type, std :: ratio<std :: numeric_limits <std :: intmax_t> :: max(), 1> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<std :: numeric_limits <std :: intmax_t> :: max(), std :: numeric_limits <std :: intmax_t> :: max()> > :: type, std :: ratio<1, 1> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: roundType <std :: ratio<1, std :: numeric_limits <std :: intmax_t> :: max()> > :: type, std :: ratio<0, 1> >(), "Should not fail on close to end of range values.");

 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '+', 1u, std :: numeric_limits <unsigned int> :: max()> > :: type, crap :: valueRatio<int, '+', 0u, 1u> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '-', 1u, std :: numeric_limits <unsigned int> :: max()> > :: type, crap :: valueRatio<int, '-', 0u, 1u> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '+', std :: numeric_limits <unsigned int> :: max(), std :: numeric_limits <unsigned int> :: max()> > :: type, crap :: valueRatio<int, '+', 1u, 1u> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '-', std :: numeric_limits <unsigned int> :: max(), std :: numeric_limits <unsigned int> :: max()> > :: type, crap :: valueRatio<int, '-', 1u, 1u> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '+', std :: numeric_limits <unsigned int> :: max(), 1u> > :: type, crap :: valueRatio<int, '+', std :: numeric_limits <unsigned int> :: max(), 1u> >(), "Should not fail on close to end of range values.");
 static_assert(std :: is_same<typename crap :: roundType <crap :: valueRatio<int, '-', std :: numeric_limits <unsigned int> :: max(), 1u> > :: type, crap :: valueRatio<int, '-', std :: numeric_limits <unsigned int> :: max(), 1u> >(), "Should not fail on close to end of range values.");

 return EXIT_SUCCESS;
}


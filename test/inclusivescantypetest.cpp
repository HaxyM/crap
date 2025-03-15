#include "../include/crap/numeric.d/inclusivescantype.h"

#include "../include/crap/utility.d/printtype.h"
#include "testutils.h"

#include <iostream>

template <class, class> struct plus;

template <unsigned int Lhs, unsigned int Rhs> struct plus<u<Lhs>, u<Rhs> >
{
 using type = u<Lhs + Rhs>;
};

int main()
{
 using test1 =
	 typename crap :: inclusiveScanType <plus, u<3u>, u<1u>, u<4u>, u<1u>, u<5u>, u<9u>, u<2u>, u<6u> > :: template
	 type<crap :: printType>;
 test1 :: print(std :: cout, ", ");
}


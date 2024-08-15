#include "../include/crap/numeric.d/mulsatvalue.h"

#include <cstdlib>
#include <limits>

template <class Type> void test_mulSatValue()
{
 constexpr const static bool isSigned = std :: is_signed <Type> :: value;
 constexpr const static auto max = std :: numeric_limits <Type> :: max();
 constexpr const static auto min = std :: numeric_limits <Type> :: min();
 static_assert(crap :: mulSatValue <Type, min, min> :: value == (isSigned ? max : min),
		 "Min times min should be extremum.");
 static_assert(crap :: mulSatValue <Type, min, max> :: value == min,
		 "Min times max should be min.");
 static_assert(crap :: mulSatValue <Type, max, min> :: value == min,
		 "Max times min should be min.");
 static_assert(crap :: mulSatValue <Type, max, max> :: value == max,
		 "Max times max should be max.");

 static_assert(crap :: mulSatValue <Type, max, max, max, max, max> :: value == max,
		 "Product of all macies should be max.");
 static_assert(crap :: mulSatValue <Type, min, min, min, min, min> :: value == min,
		 "Product of odd mins should be min.");
 static_assert(crap :: mulSatValue <Type, min, min, min, min, min, min> :: value == (isSigned ? max : min),
		 "Product of even mins should be extremum.");
}

int main()
{
 test_mulSatValue<signed char>();
 test_mulSatValue<unsigned char>();
 test_mulSatValue<signed short int>();
 test_mulSatValue<unsigned short int>();
 test_mulSatValue<signed int>();
 test_mulSatValue<unsigned int>();
 test_mulSatValue<signed long int>();
 test_mulSatValue<unsigned long int>();
 test_mulSatValue<signed long long int>();
 test_mulSatValue<unsigned long long int>();
 return EXIT_SUCCESS;
}

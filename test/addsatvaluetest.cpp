#include "../include/crap/numeric.d/addsatvalue.h"

#include <cstdlib>
#include <limits>

template <class Type> void test_addSatValue()
{
 constexpr const static auto max = std :: numeric_limits <Type> :: max();
 constexpr const static auto min = std :: numeric_limits <Type> :: min();
 static_assert(crap :: addSatValue <Type, min, min> :: value == min,
		 "Min plus min should be min.");
 static_assert(crap :: addSatValue <Type, min, max> :: value == (min + max),
		 "Min plus max should be something in range.");
 static_assert(crap :: addSatValue <Type, max, min> :: value == (max + min),
		 "Max plus min should be something in range.");
 static_assert(crap :: addSatValue <Type, max, max> :: value == max,
		 "Max plus max should be max.");

 static_assert(crap :: addSatValue <Type, min, min, min, min, min> :: value == min,
		 "Sum of all mins should be min.");
 static_assert(crap :: addSatValue <Type, max, max, max, max, max> :: value == max,
		 "Sum of all macies should be max.");
}

int main()
{
 test_addSatValue<signed char>();
 test_addSatValue<unsigned char>();
 test_addSatValue<signed short int>();
 test_addSatValue<unsigned short int>();
 test_addSatValue<signed int>();
 test_addSatValue<unsigned int>();
 test_addSatValue<signed long int>();
 test_addSatValue<unsigned long int>();
 test_addSatValue<signed long long int>();
 test_addSatValue<unsigned long long int>();
 return EXIT_SUCCESS;
}

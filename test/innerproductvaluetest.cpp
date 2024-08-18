#include "../include/crap/numeric.d/innerproductvalue.h"

#include <cstdlib>
#include <iterator>
#include <numeric>

#include "../include/crap/numbers.d/zero.h"
#include "../include/crap/numeric.d/innerproductfortype.h"
#include "../include/crap/utility.d/valuelist.h"

template <unsigned int Value1, unsigned int Value2> struct add
{
 constexpr const static unsigned int value = (Value1 + Value2);
};

template <unsigned int Value1, unsigned int Value2> struct mul
{
 constexpr const static unsigned int value = (Value1 * Value2);
};

bool test_innerProductValue()
{
 using valueTestType = unsigned int;
 constexpr const static auto const0 = crap :: zero <valueTestType> :: value;
 //TODO: Make sequences random.
 using testList1 = crap :: valueList <valueTestType, 0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u>;
 using testList2 = crap :: valueList <valueTestType, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u>;
 using testedFun =
	 typename testList1 :: copy <crap :: innerProductForType<valueTestType, add, mul> :: template values>;
 constexpr const static auto testResult = testList2 :: copy <testedFun :: template with> :: value;
 const static auto expectedResult =
	 std :: inner_product(std :: begin(testList1 :: data()), std :: end(testList1 :: data()),
			 std :: begin(testList2 :: data()), const0);
 return (testResult == expectedResult);
}

int main()
{
 return test_innerProductValue() ? EXIT_SUCCESS : EXIT_FAILURE;
}

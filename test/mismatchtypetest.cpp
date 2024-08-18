#include "../include/crap/algorithm.d/mismatchtype.h"

#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>

#include "testutils.h"
#include "../include/crap/utility.d/valuelist.h"

//TODO: consider adding such functionality to crap core.
template <template <class, class> class Operator> struct mismatchForTypes
{
 template <class ... Types>
	 using type = crap :: mismatchType<Operator, Types...>;
};

bool test_mismatchTypeTrivialTest()
{
 using valueTestType = unsigned int;
 //TODO: Make sequence random.
 using testList1 = crap :: valueList <valueTestType, 0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u>;
 using testedFun =
	 typename testList1 :: copy <valuesToTypesForType <valueTestType> :: template type> ::
	 type <mismatchForTypes<equalType> :: template type>;
 using testResult_t =
	 typename testList1 :: copy <valuesToTypesForType <valueTestType> :: template type> ::
	 type <testedFun :: template with>;
 constexpr const static auto testResult = testResult_t :: value;
 constexpr const static auto expectedResult = testResult_t :: npos;
 return (testResult == expectedResult);
}

int main()
{
 const bool results[] = {
	 test_mismatchTypeTrivialTest()
 };
 return std :: accumulate(std :: begin(results), std :: end(results), true, std :: logical_and<bool>())
	 ? EXIT_SUCCESS
	 : EXIT_FAILURE;
}


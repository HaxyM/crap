#include "../include/crap/algorithm.d/isheapfortype.h"

#include <cstdlib>
#include <functional>
#include <iterator>
#include <numeric>

#include "testutils.h"
#include "../include/crap/functional.d/comparatorsfortype.h"

bool test_isHeapValueTrivialPassingTest()
{
 using valueTestType = unsigned int;

 //TODO: Make sequence random.
 using testList1 =
	 crap :: valueList<valueTestType, 9u, 8u, 7u, 7u, 7u, 7u, 5u, 5u, 3u>;
 using testedFun = crap :: isHeapForType<
	 valueTestType,
	 lessConstrainedForType <valueTestType, Constrain> :: template type>;
 using testResult_t = typename testList1 :: copy <testedFun :: template type>;
 constexpr const static auto testResult = testResult_t :: value;
 static_assert(testResult, "Set is a heap!");
 return true;
}

bool test_isHeapValueTrivialFailingTest()
{
 using valueTestType = unsigned int;
 constexpr const static valueTestType Constrain = 42u;
 constexpr const static valueTestType Subject = 101u;

 //TODO: Make sequence random.
 using testList1 =
	 crap :: valueList<valueTestType, 9u, 8u, 7u, 7u, 7u, 7u, 5u, Subject, Constrain>;
 using testedFun = crap :: isHeapForType<
	 valueTestType,
	 crap :: comparatorsForType <valueTestType> :: template Less>;
 using testResult_t = typename testList1 :: copy <testedFun :: template type>;
 constexpr const static auto testResult = testResult_t :: value;
 static_assert(!testResult, "Set is not a heap!");
 return true;
}

int main()
{
 const bool results[] = {
	 test_isHeapValueTrivialPassingTest(),
	 test_isHeapValueTrivialFailingTest()
 };
 return std :: accumulate(std :: begin(results), std :: end(results), true, std :: logical_and<bool>())
	 ? EXIT_SUCCESS
	 : EXIT_FAILURE;
}


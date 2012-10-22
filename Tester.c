#include <stdio.h>
#include "CuTest.h"

void Test1(CuTest* tc)
{
	CuAssert(tc, "1 == 1 + 1", 1 == 1 + 1);
}
void Test2(CuTest* tc)
{
	CuAssertStrEquals(tc, "<Test 2>", "<Test 3>");
}
void Test3(CuTest* tc)
{
	CuAssertIntEquals(tc, 123, 124);
}
void Test4(CuTest* tc)
{
	CuAssertPtrNotNull(tc, NULL);
}
void Test5(CuTest* tc)
{
	CuAssertPtrNotNull(tc, tc);
	CuAssertPtrEquals(tc, NULL, (void*)1);
}

void RunAllTests(void)
{
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();
	CuTest tc1, tc2, tc3, tc4, tc5;

	CuSuiteInit(suite);
	CuTestInit(&tc1, "Test1",  Test1);
	CuTestInit(&tc2, "Test2",  Test2);
	CuTestInit(&tc3, "Test3",  Test3);
	CuTestInit(&tc4, "Test4",  Test4);
	CuTestInit(&tc5, "Test5",  Test5);

	CuSuiteAdd(suite, &tc1);
	CuSuiteAdd(suite, &tc2);
	CuSuiteAdd(suite, &tc3);
	CuSuiteAdd(suite, &tc4);
	CuSuiteAdd(suite, &tc5);

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

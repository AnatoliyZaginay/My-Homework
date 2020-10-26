#include "PostfixCalculatorTests.h"

#include "PostfixCalculator.h"

bool sumTest(void)
{
	int result = 0;
	return postfixCalculator("55+", &result) == CORRECT_WORK_CODE && result == 10;
}

bool subtractionTest(void)
{
	int result = 0;
	return postfixCalculator("72-", &result) == CORRECT_WORK_CODE && result == 5;
}

bool subtractionTestNegativeResult(void)
{
	int result = 0;
	return postfixCalculator("27-", &result) == CORRECT_WORK_CODE && result == -5;
}

bool multiplicationTest(void)
{
	int result = 0;
	return postfixCalculator("56*", &result) == CORRECT_WORK_CODE && result == 30;
}

bool divisionTest(void)
{
	int result = 0;
	return postfixCalculator("93/", &result) == CORRECT_WORK_CODE && result == 3;
}

bool divisionByZeroTest(void)
{
	int result = 0;
	return postfixCalculator("90/", &result) == ERROR_CODE_DIVISION_BY_ZERO && result == 0;
}

bool combinationOfOperationsTest(void)
{
	int result = 0;
	return postfixCalculator("92310+-*/", &result) == CORRECT_WORK_CODE && result == 2;
}

bool notEnoughNumbersTest(void)
{
	int result = 0;
	return postfixCalculator("9132****", &result) == ERROR_CODE_NOT_ENOUGH_NUMBERS && result == 0;
}

bool notEnoughOperationsTest(void)
{
	int result = 0;
	return postfixCalculator("9132**", &result) == ERROR_CODE_NOT_ENOUGH_OPERATIONS;
}

bool wrongLineTest(void)
{
	int result = 0;
	return postfixCalculator("91+test", &result) == ERROR_CODE_WRONG_LINE && result == 0;
}

bool postfixCalculatorTest(void)
{
	return sumTest() && subtractionTest() && subtractionTestNegativeResult() &&
		multiplicationTest() && divisionTest() && divisionByZeroTest() &&
		combinationOfOperationsTest() && notEnoughNumbersTest() && notEnoughOperationsTest() &&
		wrongLineTest();
}
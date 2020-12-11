#include "FromInfixToPostfixTests.h";

#include "FromInfixToPostfix.h"
#include <string.h>

bool plusAndMinusTest(void)
{
	char result[10] = "";
	return fromInfixToPostfix("1+2-3+4-5", result) == CORRECT_WORK_CODE && strcmp(result, "12+3-4+5-") == 0;
}

bool multiplicationAndDivisionTest(void)
{
	char result[10] = "";
	return fromInfixToPostfix("1*2/3*4/5", result) == CORRECT_WORK_CODE && strcmp(result, "12*3/4*5/") == 0;
}

bool allOperationsTest(void)
{
	char result[20] = "";
	return fromInfixToPostfix("1+2*3-0+5/9*6+7-4/8", result) == CORRECT_WORK_CODE && strcmp(result, "123*+0-59/6*+7+48/-") == 0;
}

bool bracketsTest(void)
{
	char result[20] = "";
	return fromInfixToPostfix("(1+2)*3-(0+5/9*(6+7))-4/8", result) == CORRECT_WORK_CODE && strcmp(result, "12+3*059/67+*+-48/-") == 0;
}

bool openBracketErrorTest(void)
{
	char result[20] = "";
	return fromInfixToPostfix("(1+2)*3-((0+5/9*(6+7))-4/8", result) == ERROR_CODE_NOT_FOUND_BRACKET;
}

bool closingBracketErrorTest(void)
{
	char result[20] = "";
	return fromInfixToPostfix("(1+2)*3-(0+5/9*(6+7)))-4/8", result) == ERROR_CODE_NOT_FOUND_BRACKET;
}

bool fromInfixToPostfixTest(void)
{
	return plusAndMinusTest() && multiplicationAndDivisionTest() && allOperationsTest() &&
		bracketsTest() && openBracketErrorTest() && closingBracketErrorTest();
}
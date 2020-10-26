#include "BracketsBalanceTests.h"

#include "BracketsBalance.h"

bool roundBracketsTest(void)
{
	return isBalanced("(())") && isBalanced("(()())") && !isBalanced(")(") &&
		!isBalanced("(()") && !isBalanced("())");
}

bool squareBracketsTest(void)
{
	return isBalanced("[[]]") && isBalanced("[[][]]") && !isBalanced("][") &&
		!isBalanced("[[]") && !isBalanced("[]]");
}

bool curlyBracketsTest(void)
{
	return isBalanced("{{}}") && isBalanced("{{}{}}") && !isBalanced("}{") &&
		!isBalanced("{{}") && !isBalanced("{}}");
}

bool differentTypesOfBracketsTest(void)
{
	return isBalanced("{([])}") && isBalanced("([]){()[]}") && isBalanced("[((){[]})]") &&
		isBalanced("(){}[]") && !isBalanced("{([)]}") && !isBalanced("([{}]") &&
		!isBalanced("[[{[()]}]]]");
}

bool bracketsBalanceTest(void)
{
	return roundBracketsTest() && squareBracketsTest() && curlyBracketsTest() &&
		differentTypesOfBracketsTest();
}
#include "RealNumberLexerTest.h"

#include "RealNumberLexer.h"

bool isRealNumberTest(void)
{
	return isRealNumber("1") && isRealNumber("123") && isRealNumber("123E123") && isRealNumber("123E+123") &&
		isRealNumber("123.123") && isRealNumber("123.123E123") && isRealNumber("123.123E-123") && isRealNumber("123.123E+123") &&
		!isRealNumber("abc") && !isRealNumber("123.") && !isRealNumber("123E") && !isRealNumber("123.E") &&
		!isRealNumber("123-123") && !isRealNumber("123.123+1") && !isRealNumber("123E.123") && !isRealNumber("123.123A+123") &&
		!isRealNumber("123E+");
}
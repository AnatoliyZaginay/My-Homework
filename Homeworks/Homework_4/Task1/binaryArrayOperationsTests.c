#include "binaryArrayOperationsTests.h"

#include "binaryArrayOperations.h"
#include "arrayOperations.h"

bool testConvertToBinary(void)
{
	int binaryArray[ARRAY_SIZE] = { 0 };
	convertToBinary(12, binaryArray, ARRAY_SIZE);
	int expectedBinaryArray[ARRAY_SIZE] = { 0, 0, 1, 1 };
	if (!compareArrays(binaryArray, expectedBinaryArray, ARRAY_SIZE))
	{
		return false;
	}
	int secondBinaryArray[ARRAY_SIZE] = { 0 };
	convertToBinary(-3, secondBinaryArray, ARRAY_SIZE);
	int secondExpectedBinaryArray[ARRAY_SIZE] = { 0 };
	binaryNumberInversion(secondExpectedBinaryArray, ARRAY_SIZE);
	secondExpectedBinaryArray[1] = 0;
	return compareArrays(secondBinaryArray, secondExpectedBinaryArray, ARRAY_SIZE);
}

bool testBinarySum(void)
{
	int firstBinaryArray[ARRAY_SIZE] = { 0 };
	int secondBinaryArray[ARRAY_SIZE] = { 0 };
	convertToBinary(12, firstBinaryArray, ARRAY_SIZE);
	convertToBinary(4, secondBinaryArray, ARRAY_SIZE);
	int sum[ARRAY_SIZE] = { 0 };
	binarySum(firstBinaryArray, secondBinaryArray, sum, ARRAY_SIZE);
	int expectedSum[ARRAY_SIZE] = { 0 };
	convertToBinary(16, expectedSum, ARRAY_SIZE);
	if (!compareArrays(sum, expectedSum, ARRAY_SIZE))
	{
		return false;
	}
	int firstBinaryArrayNegativeTest[ARRAY_SIZE] = { 0 };
	int secondBinaryArrayNegativeTest[ARRAY_SIZE] = { 0 };
	convertToBinary(5, firstBinaryArrayNegativeTest, ARRAY_SIZE);
	convertToBinary(-10, secondBinaryArrayNegativeTest, ARRAY_SIZE);
	int sumNegativeTest[ARRAY_SIZE] = { 0 };
	binarySum(firstBinaryArrayNegativeTest, secondBinaryArrayNegativeTest, sumNegativeTest, ARRAY_SIZE);
	int expectedSumNegativeTest[ARRAY_SIZE] = { 0 };
	convertToBinary(-5, expectedSumNegativeTest, ARRAY_SIZE);
	return compareArrays(sumNegativeTest, expectedSumNegativeTest, ARRAY_SIZE);
}

bool testFromBinaryToDecimal(void)
{
	int binaryArray[ARRAY_SIZE] = { 0 };
	convertToBinary(25, binaryArray, ARRAY_SIZE);
	if (fromBinaryToDecimal(binaryArray, ARRAY_SIZE) != 25)
	{
		return false;
	}
	int secondBinaryArray[ARRAY_SIZE] = { 0 };
	convertToBinary(-31, secondBinaryArray, ARRAY_SIZE);
	return fromBinaryToDecimal(secondBinaryArray, ARRAY_SIZE) == -31;
}

bool testsResult(void)
{
	return testConvertToBinary() && testBinarySum() && testFromBinaryToDecimal();
}
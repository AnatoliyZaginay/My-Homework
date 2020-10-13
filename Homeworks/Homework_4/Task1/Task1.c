#include "binaryArrayOperations.h"
#include "binaryArrayOperationsTests.h"
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

bool testsResult(void)
{
	return testConvertToBinary() && testBinarySum() && testFromBinaryToDecimal();
}

void main(void)
{
	if (!testsResult())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	int firstNumber = 0;
	int secondNumber = 0;
	printf("Введите первое число: ");
	scanf("%i", &firstNumber);
	printf("Введите второе число: ");
	scanf("%i", &secondNumber);
	int binaryFirstNumber[ARRAY_SIZE] = { 0 };
	int binarySecondNumber[ARRAY_SIZE] = { 0 };
	int sum[ARRAY_SIZE] = { 0 };
	convertToBinary(firstNumber, binaryFirstNumber, ARRAY_SIZE);
	convertToBinary(secondNumber, binarySecondNumber, ARRAY_SIZE);
	binarySum(binaryFirstNumber, binarySecondNumber, sum, ARRAY_SIZE);
	printf("Первое число в двоичном представлении: ");
	printBinaryArray(binaryFirstNumber, ARRAY_SIZE);
	printf("\nВторое число в двоичном представлении: ");
	printBinaryArray(binarySecondNumber, ARRAY_SIZE);
	printf("\nСумма чисел в двоичном представлении: ");
	printBinaryArray(sum, ARRAY_SIZE);
	printf("\nСумма чисел в десятичном представлении: ");
	printf("%i", fromBinaryToDecimal(sum, ARRAY_SIZE));
}
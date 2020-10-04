#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int recursiveFibonacci(int numberFibonacci)
{
	if (numberFibonacci <= 0)
	{
		return -1;
	}
	if (numberFibonacci <= 2)
	{
		return 1;
	}
	return recursiveFibonacci(numberFibonacci - 1) + recursiveFibonacci(numberFibonacci - 2);
}

int iterativeFibonacci(int numberFibonacci)
{
	if (numberFibonacci <= 0)
	{
		return -1;
	}
	int firstFibonacciNumber = 1;
	int secondFibonacciNumber = 1;
	int result = 1;
	for (int i = 0; i < numberFibonacci - 2; ++i)
	{
		result = firstFibonacciNumber + secondFibonacciNumber;
		firstFibonacciNumber = secondFibonacciNumber;
		secondFibonacciNumber = result;
	}
	return result;
}

bool testFibonacci()
{
	return (recursiveFibonacci(1) == 1) && (recursiveFibonacci(2) == 1) &&
		(iterativeFibonacci(1) == 1) && (iterativeFibonacci(2) == 1) &&
		(recursiveFibonacci(10) == 55) && (iterativeFibonacci(10) == 55);
}

bool testFibonacciIncorrectInput()
{
	return (recursiveFibonacci(-1) == -1) && (iterativeFibonacci(-1) == -1) &&
		(recursiveFibonacci(0) == -1) && (iterativeFibonacci(0) == -1);
}

void main()
{
	if (!testFibonacci() || !testFibonacciIncorrectInput())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	int number = 0;
	printf("Введите номер числа Фибоначчи: ");
	scanf("%i", &number);
	if (number <= 0)
	{
		printf("Номер числа Фибоначчи должен быть натуральным числом");
		return;
	}
	const int resultIterative = iterativeFibonacci(number);
	printf("%i число Фибоначчи: %i (подсчитано итеративно)\n", number, resultIterative);
	const int resultRecursive = recursiveFibonacci(number);
	printf("%i число Фибоначчи: %i (подсчитано рекурсивно)\n", number, resultRecursive);
}
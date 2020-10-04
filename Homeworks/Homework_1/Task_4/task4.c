#include <stdio.h>
#include <math.h>
#include <locale.h>

int isPrimeNumber(int number)
{
	const squareRoot = sqrt(number);
	for (int i = 2; i < squareRoot + 1; ++i)
	{
		if (number % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int lastNumber = 0;
	printf("Введите число: ");
	scanf("%d", &lastNumber);
	printf("Простые числа, не превосходящие %d: ", lastNumber);
	for (int i = 2; i <= lastNumber; ++i)
	{
		if (isPrimeNumber(i) == 1)
		{
			printf("%d ", i);
		}
	}
}
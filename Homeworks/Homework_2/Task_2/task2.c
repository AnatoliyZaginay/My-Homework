#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

float logPowerOfNumber(float base, int exponent)
{
	if (exponent < 0)
	{
		base = 1 / base;
		exponent = -exponent;
	}
	if (exponent == 0)
	{
		return 1;
	}
	const float dividedPower = logPowerOfNumber(base, exponent / 2);
	if (exponent % 2 == 0)
	{
		return dividedPower * dividedPower;
	}
	return dividedPower * dividedPower * base;
}

float iterativePowerOfNumber(float base, int exponent)
{
	if (exponent < 0)
	{
		base = 1 / base;
		exponent = -exponent;
	}
	float result = 1;
	for (int i = 0; i < exponent; ++i)
	{
		result *= base;
	}
	return result;
}

bool testPositiveNumberPositivePower()
{
	return (logPowerOfNumber(2, 2) == 4) && (iterativePowerOfNumber(2, 2) == 4) &&
		(logPowerOfNumber(1.5, 2) == 2.25) && (iterativePowerOfNumber(1.5, 2) == 2.25);
}

bool testPositiveNumberNegativePower()
{
	return (logPowerOfNumber(2, -2) == 0.25) && (iterativePowerOfNumber(2, -2) == 0.25) &&
		(logPowerOfNumber(0.5, -2) == 4) && (iterativePowerOfNumber(0.5, -2) == 4);
}

bool testNegativeNumberPositivePower()
{
	return (logPowerOfNumber(-2, 2) == 4) && (iterativePowerOfNumber(-2, 2) == 4) &&
		(logPowerOfNumber(-0.5, 3) == -0.125) && (iterativePowerOfNumber(-0.5, 3) == -0.125);
}

bool testNegativeNumberNegativePower()
{
	return (logPowerOfNumber(-2, -2) == 0.25) && (iterativePowerOfNumber(-2, -2) == 0.25) &&
		(logPowerOfNumber(-0.5, -3) == -8) && (iterativePowerOfNumber(-0.5, -3) == -8);
}

bool testZeroPower()
{
	return (logPowerOfNumber(2, 0) == 1) && (iterativePowerOfNumber(2, 0) == 1) &&
		(logPowerOfNumber(-0.5, 0) == 1) && (iterativePowerOfNumber(-0.5, 0) == 1);
}

void main()
{
	if (!testPositiveNumberPositivePower() || !testPositiveNumberNegativePower() ||
		!testNegativeNumberPositivePower() || !testNegativeNumberNegativePower() ||
		!testZeroPower())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	float number = 0;
	int power = 0;
	printf("Введите число: ");
	scanf("%f", &number);
	printf("Введите степень: ");
	scanf("%i", &power);
	const float resultLog = logPowerOfNumber(number, power);
	printf("O(log n) %f в %i степени: %f\n", number, power, resultLog);
	const float resultIterative = iterativePowerOfNumber(number, power);
	printf("O(n) %f в %i степени: %f", number, power, resultIterative);
}
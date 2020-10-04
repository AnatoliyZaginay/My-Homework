#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int digitsSumCount[28];
	int tickets = 0;
	for (int i = 0; i < 28; ++i)
	{
		digitsSumCount[i] = 0;
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				++digitsSumCount[i + j + k];
			}
		}
	}
	for (int i = 0; i < 28; ++i)
	{
		tickets += digitsSumCount[i] * digitsSumCount[i];
	}
	printf("Число счастливых шестизначных билетов: %d", tickets);
}
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int a = 0;
	int b = 0;
	printf("Введите делимое: ");
	scanf("%d", &a);
	printf("Введите делитель: ");
	scanf("%d", &b);
	if (b == 0)
	{
		printf("На ноль делить нельзя.");
		return 0;
	}
	int result = 0;
	while (abs(a - result * b) >= abs(b) || a - result * b < 0)
	{
		if (a * b >= 0)
		{
			++result;
		}
		else
		{
			--result;
		}
	}
	printf("Неполное частное: %d", result);
}
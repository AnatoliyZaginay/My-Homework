#include <stdio.h>
#include <locale.h>

int main()
{
	char line[10];
	int bracketCount = 0;
	setlocale(LC_ALL, "Rus");
	printf("Введите скобочную последовательность: ");
	scanf("%s", &line);
	for (int i = 0; i < strlen(line); ++i)
	{
		if (line[i] == '(')
		{
			++bracketCount;
		}
		if (line[i] == ')')
		{
			--bracketCount;
		}
		if (bracketCount < 0)
		{
			printf("Баланс скобок не выполняется");
			return 0;
		}
	}
	if (bracketCount > 0)
	{
		printf("Баланс скобок не выполняется");
	}
	else
	{
		printf("Баланс скобок выполняется");
	}
}
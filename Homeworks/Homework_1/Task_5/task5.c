#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	char s[100];
	char s1[100];
	int count = 0;
	printf("Введите строку S: ");
	scanf("%s", &s);
	printf("Введите строку S1: ");
	scanf("%s", &s1);
	for (int i = 0; i <= strlen(s) - strlen(s1); ++i)
	{
		int check = 1;
		for (int j = 0; j < strlen(s1); ++j)
		{
			if (s[i + j] != s1[j])
			{
				check = 0;
				break;
			}
		}
		if (check == 1)
		{
			++count;
		}
	}
	printf("Строка S1 входит в строку S, как подстрока %d раз(а).", count);
}
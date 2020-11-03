#include "CyclicList.h"
#include "CyclicListTests.h"
#include <stdio.h>
#include <locale.h>

void main(void)
{
	if (!cyclicListTests())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	struct List* list = createList();
	printf("Введите количество войнов: ");
	int n = 0;
	scanf("%i", &n);
	printf("Введите, с какой периодичностью будут убивать войнов: ");
	int m = 0;
	scanf("%i", &m);
	for (int i = 1; i <= n; ++i)
	{
		add(list, i);
	}
	int k = lastElement(list, m);
	if (k > 0)
	{
		printf("Номер начальной позиции война, который останется последним: %i", k);
	}
	else
	{
		printf("Введены неверные данные");
	}
	deleteList(&list);
}
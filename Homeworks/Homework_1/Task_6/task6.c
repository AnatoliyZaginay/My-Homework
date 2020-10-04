#include <stdio.h>
#include <locale.h>
#define ARRAY_SIZE 100

void arrayReverse(int array[], int leftBorder, int rightBorder)
{
	for (int i = 0; i <= (rightBorder - leftBorder) / 2; ++i)
	{
		const int change = array[leftBorder + i];
		array[leftBorder + i] = array[rightBorder - i];
		array[rightBorder - i] = change;
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int x[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		x[i] = 0;
	}
	int n = 0;
	printf("Введите длину массива: ");
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		printf("Введите %d элемент массива: ", i + 1);
		scanf("%d", &x[i]);
	}

	int m = 0;
	printf("\nВведите индекс, разграничивающий начало и конец массива: ");
	scanf("%d", &m);
	printf("\n");
	arrayReverse(x, 0, m - 1);
	arrayReverse(x, m, n - 1);
	arrayReverse(x, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		printf("%d элемент изменённого массива: %d\n", i + 1, x[i]);
	}
}
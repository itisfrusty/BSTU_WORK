#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main()
{
	int* a;
	int i, j, n, m;
	system("chcp 1251");
	system("cls");
	printf("Enter number of rows: ");
	scanf_s("%d", &n);
	printf("Enter number of columns : ");
	scanf_s("%d", &m);
	a = (int*)malloc(n * m * sizeof(int));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", (a + i * m + j));
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%5d", *(a + i * m + j));
		}
		printf("\n");
	}
	free(a);
	getchar(); getchar();
	return 0;
}
#include <stdio.h>
#include <malloc.h>

#pragma warning(disable:4996)


int main() {
	int i, j;
	int n, *arr[2];
	scanf("%d", &n);
	for(i=0; i<2; i++)
		arr[i] = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < 2; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	for (i = 0; i < n; i++)
		printf(" %d", arr[0][i] + arr[1][n - 1 - i]);
	return 0;

}
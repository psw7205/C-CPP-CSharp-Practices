#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

void MyDelete(INFO **ar, int *n)
{
	char tmp[101];
	int i, j;

	if (*n == 0) // �����Ͱ� ������ ����
	{
		printf("NO MEMBER\n");
		return;
	}

	printf("Name:");
	gets(tmp); // ���� �̸� ����

	for (i = 0; i < *n; i++)
	{
		if (!strcmp(tmp, ar[i]->name)) // ���� �̸��� ã����
			break; // Ż��
	}

	if (i == *n) // i�� n���� ���������� ���� �̸��� ��ã�� ��
		return; // ����

	free(ar[i]->birthDay);
	free(ar[i]->name);
	free(ar[i]->phoneNumber);
	free(ar[i]);

	for (j = i; j < *n; j++) // ã�� �ڸ��� ��ĭ�� ������ �̵����� ����
		ar[j] = ar[j + 1];

	(*n)--; // ���� ����

	return;
}
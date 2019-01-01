#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

void ShowAll(INFO **ar, int *n)
{
	int i;

	for (i = 0; i < *n; i++) // �迭�� ��ȸ�ϸ� ������ ���
	{
		printf("%s %s %s\n", ar[i]->name, ar[i]->phoneNumber, ar[i]->birthDay);
	}
}

void FindByBirth(INFO **ar, int *n)
{
	int i, tmp, mon = 0;

	printf("Birth:");
	scanf("%d", &tmp); // ������ �Է¹�����
	for (i = 0; i < *n; i++)
	{
		mon = ar[i]->birthDay[4] - '0'; // 10�� �ڸ��� int�� ������ ���� ��
		mon *= 10; // *10�� ���� 10�� �ڸ��� �̵�
		mon += ar[i]->birthDay[5] - '0'; // 1�� �ڸ� ����, �� ������ ���� ������ ������ ����

		if (mon == tmp) // ã�� ������ ������
			printf("%s %s %s\n", ar[i]->name, ar[i]->phoneNumber, ar[i]->birthDay); // �ش� ������ ���
	}
}
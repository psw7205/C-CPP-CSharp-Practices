#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

void Registration(INFO **ar, int *n, int max) // ��������
{
	char tmp[3][101];
	int i, j;
	if (*n == max) // �̹� �ִ� max���� ����Ǿ�������
	{
		printf("OVERFLOW\n"); // �����÷� ��� ��
		return; // ���⸮��
	}
	printf("Name:");
	gets(tmp[0]); // �̸��Է�
	printf("Phone_number:");
	gets(tmp[1]); // ��ȭ��ȣ �Է�
	printf("Birth:");
	gets(tmp[2]); // �����Է�

	if (*n == 0) // ó�� ����� ���
	{
		ar[0] = (INFO*)malloc(sizeof(INFO));

		ar[0]->name = (char*)malloc(sizeof(char)*(strlen(tmp[0]) + 1));
		strcpy(ar[0]->name, tmp[0]);

		ar[0]->phoneNumber = (char*)malloc(sizeof(char)*(strlen(tmp[1]) + 1));
		strcpy(ar[0]->phoneNumber, tmp[1]);

		ar[0]->birthDay = (char*)malloc(sizeof(char)*(strlen(tmp[2]) + 1));
		strcpy(ar[0]->birthDay, tmp[2]); // �� ����
	}
	else // 2��° ����� �������ʹ�
	{
		for (i = 0; i < *n; i++) // ������ Ȯ���ϸ�
		{
			if (strcmp(tmp[0], ar[i]->name) < 0) // �� ū ���� ���ö����� i�̵�
				break; // i�� ����� ��ġ
		}

		for (j = *n; j > i; j--) // ��ĭ�� �ڷ� �̵�
			ar[j] = ar[j - 1];

		ar[i] = (INFO*)malloc(sizeof(INFO));

		ar[i]->name = (char*)malloc(sizeof(char)*(strlen(tmp[0]) + 1));
		strcpy(ar[i]->name, tmp[0]);

		ar[i]->phoneNumber = (char*)malloc(sizeof(char)*(strlen(tmp[1]) + 1));
		strcpy(ar[i]->phoneNumber, tmp[1]);

		ar[i]->birthDay = (char*)malloc(sizeof(char)*(strlen(tmp[2]) + 1));
		strcpy(ar[i]->birthDay, tmp[2]); // �� ���� // i�ڸ��� �� ����
	}

	(*n)++; // ���� ����
	printf("<<%d>>\n", *n); // ���� ���
	return;
}


void RegFromFile(INFO **ar, int *n, int max)
{
	FILE *fp = fopen("PHONE_BOOK.txt", "r");
	int i, j;
	char tmp[3][101];

	while (fscanf(fp, "%s %s %s", tmp[0], tmp[1], tmp[2]) != EOF)
	{
		if (*n == max) // �̹� �ִ� max���� ����Ǿ�������
		{
			printf("OVERFLOW\n"); // �����÷� ��� ��
			return;
		}

		if (*n == 0) // ó�� ����� ���
		{
			ar[0] = (INFO*)malloc(sizeof(INFO));

			ar[0]->name = (char*)malloc(sizeof(char)*(strlen(tmp[0]) + 1));
			strcpy(ar[0]->name, tmp[0]);

			ar[0]->phoneNumber = (char*)malloc(sizeof(char)*(strlen(tmp[1]) + 1));
			strcpy(ar[0]->phoneNumber, tmp[1]);

			ar[0]->birthDay = (char*)malloc(sizeof(char)*(strlen(tmp[2]) + 1));
			strcpy(ar[0]->birthDay, tmp[2]); // �� ����
		}
		else // 2��° ����� �������ʹ�
		{
			for (i = 0; i < *n; i++) // ������ Ȯ���ϸ�
			{
				if (strcmp(tmp[0], ar[i]->name) < 0) // �� ū ���� ���ö����� i�̵�
					break; // i�� ����� ��ġ
			}

			for (j = *n; j > i; j--) // ��ĭ�� �ڷ� �̵�
				ar[j] = ar[j - 1];

			ar[i] = (INFO*)malloc(sizeof(INFO));

			ar[i]->name = (char*)malloc(sizeof(char)*(strlen(tmp[0]) + 1));
			strcpy(ar[i]->name, tmp[0]);

			ar[i]->phoneNumber = (char*)malloc(sizeof(char)*(strlen(tmp[1]) + 1));
			strcpy(ar[i]->phoneNumber, tmp[1]);

			ar[i]->birthDay = (char*)malloc(sizeof(char)*(strlen(tmp[2]) + 1));
			strcpy(ar[i]->birthDay, tmp[2]); // �� ���� // i�ڸ��� �� ����
		}
		(*n)++; // ���� ����
	}

	fclose(fp);
}

void close(INFO **ar, int *n)
{
	FILE *fp = fopen("PHONE_BOOK.txt", "w");

	for (int i = 0; i < *n; i++)
	{
		fprintf(fp, "%s %s %s\n", ar[i]->name, ar[i]->phoneNumber, ar[i]->birthDay);
	}

	fclose(fp);
}
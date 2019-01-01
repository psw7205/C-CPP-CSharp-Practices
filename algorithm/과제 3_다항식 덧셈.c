#include<stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

typedef struct {
	int degree;
	int *coef;
} poly; // �ִ������� ������ degree�� ����� ������ �� �� �����Ҵ��� ���� ������ coef�Դϴ�.

poly addpoly(poly a, poly b) // �� ���׽��� ���ϴ� �Լ��Դϴ�.
{
	poly sum, max;
	int min = 0;

	if (a.degree > b.degree)
	{
		sum.degree = a.degree;
		min = b.degree;
		max = a;
	}
	else
	{
		sum.degree = b.degree; 
		min = a.degree;
		max = b;
	}
	// ū ���׽��� ����� sum����, �� ���� ���׽��� min����, ū ���׽��� ����� poly����ü�� max�� �����߽��ϴ�

	sum.coef = (int *)malloc(sizeof(int)*(sum.degree + 1)); // �� ū ������ �°� �����Ҵ� �Ͽ����ϴ�.

	for (int i = 0; i <= min; i++)
	{
		sum.coef[i] = a.coef[i] + b.coef[i];
	} // ������������ �����߱� ������ ������� ���� �� ���� �������� ���߽��ϴ�.
	for (int i = min+1; i <=sum.degree; i++)
	{
		sum.coef[i] = max.coef[i];
	}// �� ���� �������ʹ� �� ū �ʸ� �����մϴ�.
	 
	return sum;
}

int main()
{
	int a = 0, b = 0;
	poly c;
	poly d;
	poly sum;

	scanf("%d", &a);
	c.degree = a;
	c.coef = (int *)malloc(sizeof(int)*(a + 1));
	for (int i = 0; i <= a; i++)
	{
		scanf("%d", &c.coef[a - i]);
	}

	scanf("%d", &b);
	d.degree = b;
	d.coef = (int *)malloc(sizeof(int)*(b + 1));
	for (int i = 0; i <= b; i++)
	{
		scanf("%d", &d.coef[b - i]);
	} 
	
	// ���׽� a,b�� �Է¹ް� ����(��������)���� �����߽��ϴ�.

	sum = addpoly(c, d);

	for (int i = sum.degree; i >= 0; i--)
	{
		printf(" %d", sum.coef[i]);
	}

	free(c.coef);
	free(d.coef);
	free(sum.coef);
	return 0;
}

#include <stdio.h>
#pragma warning(disable:4996)


#define SMALLEST_NUM 1


int sumation(int n) {
	if (n == SMALLEST_NUM) // ��͸� �׸��� ����
		return n; // ó�� ���� ��ȯ�Ѵ�.
	return sumation(n - 1) + n; // ����� ȣ��
	
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", sumation(n));
	return 0;
}
#include <stdio.h>
#pragma warning(disable:4996)



int rUclidGCD(int a, int b) {
	if (b == 0) // ���� 0�� �ɶ�, �� �ּҰ������ ã������ �� ���� return.
		return a;
	return rUclidGCD(b, a%b);
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", rUclidGCD(a, b));
	return 0;

}
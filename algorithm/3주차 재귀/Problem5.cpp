#include <stdio.h>
#pragma warning(disable:4996)

void rHanoi(int n, char from, char aux, char to) {
	if (n == 1) { // ������ �ϳ��ۿ� ���°��. ������ ��������� �ű��� return.
		printf("%c %c\n", from, to);
		return;
	}
	rHanoi(n - 1, from, to, aux); // n-1���� ������ rHanoi ��� ȣ��� aux�� �̵�
	printf("%c %c\n", from, to); // n��° ������ ��������� �̵�
	rHanoi(n - 1, aux, from, to); // n-1���� ������ rHanoi ȣ��� to�� �̵�
	return;
}


int main() {
	int n;
	scanf("%d", &n);
	rHanoi(n, 'A', 'B', 'C');
	return 0;
}
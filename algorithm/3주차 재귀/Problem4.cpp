#include <stdio.h>
#pragma warning(disable:4996)


/*
���̸� �˼� ���� arr �迭 ��

0���� n��°���� �߿� ���� ū ���� return �Ѵ�.
*/

int rscanmax(int arr[], int n) { 
	if (n == 0)// index�� 0 �ϳ����� �迭(���̰� 1�ι迭)�� index 0�� ���� ū���̴�.
		return arr[n];
	int temp = rscanmax(arr, n - 1); // temp �� n-1��° �ε��� �߿� ���� ū���� �����Ѵ�
	if ( temp < arr[n])
		return arr[n]; // ���� ū�� return
	return temp;

}


int main() {
	int n;
	int arr[20];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", rscanmax(arr, n - 1));
	return 0;
	

}
/*
�������������а� 16013093 �ڻ���Դϴ�.
������ �ּҸ� �̿��Ͽ� ���ڿ��� ��ó���� �ǵ� ���ڰ� ������ count�� 1�� �����ϰ�
���������� ���ڿ� ���̿� count�� ������ palindrome���� Ȯ���ϴ� ����Դϴ�.
*/

#include<stdio.h>
#include<string.h>
#pragma warning(disable: 4996) // vs2017���� scanf�� c4996 ������ �����մϴ�.


int palindrome(char a[])
{

	int len = 0, count = 0;

	len = strlen(a);

	for (int i = len - 1, j = 0; i >= 0, j < len; i--, j++)
	{
		if (*(a + j) == *(a + i))
			count++;
	}

	if (len == count)
		return 1;
	else
		return 0;
}

int main()
{
	char a[100];
	int b = 0;

	scanf("%s", a);

	printf("�Է��� �ܾ� %s�� ", a);

	if (palindrome(a) == 1)
		printf("palindrome �Դϴ� \n");
	else
		printf("palindrome�� �ƴմϴ� \n");

	return 0;

}
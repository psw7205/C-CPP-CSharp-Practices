#include<iostream>
#include<string>
#pragma warning(disable: 4996)//vs2017���� strtok�� c4996 ������ ����

using namespace std;

int main()
{
	while (true)
	{
		char number[100];
		char *p[4];
		int a, b;

		cout << "? " ;
		cin.getline(number, 100);

		p[0] = strtok(number, " "); // ���ڿ� number�� " "���� ����

		for (int i = 1; i < 3; i++)
		{
			p[i] = strtok('\0', " "); // �� �������� " "�� ���� �ݺ�
		}

		a = atoi(p[0]);
		b = atoi(p[2]); // a, b�� ������

		cout << a << " " << p[1] << " " << b << " = ";

		if (strcmp(p[1], "+") == 0) a += b;
		if (strcmp(p[1], "-") == 0) a -= b;
		if (strcmp(p[1], "*") == 0) a *= b;
		if (strcmp(p[1], "/") == 0) a /= b;
		if (strcmp(p[1], "%") == 0) a %= b;
		//strcmp�� �̿� p[1]�� �� �����ڰ� ������ ����

		cout << a << endl;

	}

	return 0;
}

#include<iostream>
#include<string>
#pragma warning(disable: 4996)//vs2017���� strtok�� c4996 ������ ����

using namespace std;

int main()
{
	char name[100];
	char *p[6];
	int n;
	string longname;

	cout << "5���� �̸��� ';'�� �����Ͽ� �Է��ϼ���" << endl << ">>";

	cin.getline(name, 100);

	p[0] = strtok(name, ";"); // ���ڿ� ��ó�� ���� ';'���� ����

	for (int i = 0; i < 5; i++)
	{
		p[i+1] = strtok('\0',";"); // �� �������� ';'���� ���� �ݺ� 
		cout << i + 1 << " : " << p[i] << endl;
	}

	n = strlen(p[0]); 

	longname = p[0];
	
	for (int i = 1; i < 5; i++)
	{
		if (n < strlen(p[i])) 
		{
			longname = p[i]; 
			break;
		}// ���ڿ� ���̰� �� ������ longname�� ����
	}

	cout << "���� �� �̸��� " << longname << endl;


	return 0;
}

#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int mystrlen(const char s[])
{
	int l = 0;
	while (true)
	{
		if (s[l] == 0) 
			break;
		l++;
	}

	return l;
}


int main()
{
	char c;

	c = 'a';
	cout << c << endl;
	cout << int(c) << endl;

	char ar[10] = "abc" ; // {'a','b','c', 0 };
	ar[0] = 'a';
	ar[1] = 'b';
	ar[2] = 'c';
	ar[3] = 0 ; // Null character �� �������� �ʼ�


	cout << strlen(ar) << endl;
	cout << ar << endl;
	cout << mystrlen("sejong") << endl; //strlen()�Լ��� �� �� ���� ���

	char name[100];
	cout << "�̸�" << endl;
	cin >> name; // ���ڿ����� ������ ������ ���� �ڷδ� �� ������
	cin.getline(name, 100); // name ������ �ִ� 100���� ���� �־��, ������� �����ؼ� ����

	cout << "����� �̸��� " << name << "�Դϴ�" << endl;

	// �ƽ�Ű�ڵ� : 1 ����Ʈ, �ѱ� X, ���� ��� c, c++, c#
	// �����ڵ� : 2 ����Ʈ, ��� ��� �ڹ� , ���̽�


	string str = "ABC" ; // c++���� �����ϴ� ���ڿ� Ÿ�� #include<string>�ʿ�
	str = "sejong"; // char �迭 �̿��� ���ڿ� ���忡�� �Ұ����� ���

	string str1 = "university";
	string str2 = str + str1;
	string str3;

	cin >> str3; 

	cout << str2 << endl;
	cout << str2.length() << endl; //���ڿ� ���̵� �ٷ� ��°���

	return 0;
}

#include<iostream>
#include<string>

using namespace std;

/*
int cnt = 0;
void func() // cnt�� func() ���� �ϳ��� ������ �ȵ��ư�, ���� ���ӵǾ�����.
{
	cnt++;

	if(cnt % 2 == 1)
		cout << "Ȧ" << endl;
	else
		cout << "¦" << endl;
}
*/
void func() 
{
	static int cnt = 0; // �Լ� �ӿ��� ����Ǵ� �������� �� �Լ������� ���� �� ����
	cnt++;				// �Լ��� ����Ǳ� ���� �̸� ������ ������ �Լ��� ȣ���ص� static�� �� 1���� �Ҹ�
	if (cnt % 2 == 1)
		cout << "Ȧ" << endl;
	else
		cout << "¦" << endl;
}

int main()
{
	func();
	func();
	func();
	func();

	return 0;
}

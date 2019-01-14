#include<iostream>
using namespace std;

class MyIntStack 
{
	int *p; // ���ø޸𸮷� ����� ������
	int size; // ������ �ִ� ũ��
	int tos; // ������ ž�� ����Ű�� �ε���
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(MyIntStack& s);// ���� ������
	~MyIntStack();

	bool push(int n); // ���� n�� Ǫ��, ���������� false �ƴϸ� true����
	bool pop(int &n); // ���� ž�� �ִ� ���� n�� ��, ��������� false �ƴϸ� true ����
};

MyIntStack::MyIntStack(int size)
{
	tos = 0; // ������ tos�� 0���� �����մϴ�. 
	p = new int[size]; // size�� ũ�⸸ŭ �����Ҵ��մϴ�.
	this->size = size; // size�� ������� size�� �����մϴ�. 
}
 
MyIntStack::~MyIntStack()
{
	delete[] p;
} // Ŭ������ ������ �����Ҵ��� p[]�� ��ȯ�մϴ�.

bool MyIntStack::push(int n)
{
	if(tos == size) // �ְ� ��ġ�� size�� ������ ������ �� �����̹Ƿ� false�� �����մϴ�.
		return false;
	else
	{
		p[tos] = n; // n�� ���ÿ� �����մϴ�.
		tos++; // �ְ���ġ�� 0���� ���������Ƿ� ���� �ְ� 1������ŵ�ϴ�.
		return true;
	}
}

MyIntStack::MyIntStack(MyIntStack& s)
{
	size = s.size;
	tos = s.tos;
	p = new int[size]; //���� ���縦 ���� ���Ӱ� �����Ҵ��մϴ�.
	for(int i = 0 ; i < size; i++)
		p[i] = s.p[i]; // ���� ���縦 ���� ������ ���� �����մϴ�.
}

bool MyIntStack::pop(int &n)
{
	if(tos == 0) // �ְ���ġ�� 0�̸� ������ ����ִ� ���̹Ƿ� 0�� ����մϴ�.
		return false;
	else
	{
		tos--;// push���� �����͸� �ְ� �������ױ� ������ ������ tos�� �ְ���ġ���� 1 Ů�ϴ�. �׷��Ƿ� ���� ���ҽ�Ű�� �����͸� �����մϴ�.
		n = p[tos]; // ������ �̿��� n�� �����͸� �����մϴ�.
		return true;
	}
}


int main()
{
	MyIntStack a(10); // ������ ũ�Ⱑ 10�� a�� �����մϴ�.
	a.push(10); // 10�� push�մϴ�
	a.push(20); // 20�� push�մϴ�

	MyIntStack b = a; // b�� ����� a�� ���� �����մϴ�.
	b.push(30); // b�� 30�� �ֽ��ϴ�.

	int n ;

	a.pop(n); // a���� pop�մϴ�.
	cout << "���� a���� ���� �� " << n << endl;
	b.pop(n); // b���� pop�մϴ�.
	cout << "���� b���� ���� �� " << n << endl;

	return 0;
}

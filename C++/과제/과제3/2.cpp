#include <iostream>
using namespace std;

class Sample 
{
private: 
	int *p;
	int size;
public:
	Sample(int in_n) // ������ ����� �����ϰ� ������ŭ �����迭�� �Ҵ��ϴ� �������Դϴ�.
	{
		size = in_n; 
		p = new int[in_n]; 
	}

	void read(); // �����Ҵ� ���� �迭 p�� ���� �Է¹޴� �Լ��Դϴ�.
	void write(); // �����迭�� ȭ�鿡 ����ϴ� �Լ��Դϴ�.
	int big(); // �����迭���� ���� ū �� �����մϴ�.
	~Sample(); // �����Ҵ��� p�� �����ϱ� ���� �Ҹ����Դϴ�.
};

void Sample::read()
{
	for (int i = 0; i < size; i++)
	{
		cin >> p[i]; // size�� ������ŭ �ݺ��Ͽ� �Է��մϴ�; 
	}
}

void Sample::write()
{
	for (int i = 0; i < size; i++)
	{
		cout << p[i] << "/"; // ������� ����մϴ�. 
	}
	cout << endl;
}

int Sample::big()
{
	int temp = p[0];
	for (int i = 0; i < size; i++)
	{
		temp = (temp > p[i]) ? temp : p[i]; 
	}
	return temp; // ���� ū ���� �����մϴ�.
}

Sample::~Sample()
{
	delete[] p; // �����Ҵ��� �迭 p�� ��ȯ�մϴ�.
}

int main()
{
	Sample s(10);
	s.read();
	s.write();
	cout << "���� ū ���� " << s.big() << endl;
	return 0;
}

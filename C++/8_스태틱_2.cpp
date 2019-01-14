#include<iostream>
#include<string>

using namespace std;

class CStudent
{
private:
	static int totalNum;

	void setNum()
	{
		totalNum++;
		m_num = totalNum;
	}
	int m_num;
public:
	CStudent()
	{
		setNum();
	}
	void print()
	{
		cout << m_num << endl;
	}
	static int getTotal() { return totalNum;  }
	// ����ƽ �Լ��� ���� �Լ����� ������ �� ���
	// class�� �����̱� ������ �̷� ������ �ִٴ� �͸� �˷���, main���� ����ؾ� �޸𸮰� ����
};	// C ������ �̷�... 
	// private���� �ۼ��ϸ� ��ȣ����, ��ȣ�Ѵٸ� �Լ��� �����ؾ���

int CStudent::totalNum = 0; // totalNum�� �Ҽ��� CStudent��� �ۿ� ���� �����������

void func()
{
	cout << "�� ���� " << CStudent::getTotal(); << endl;
} // �����Լ��̱� ������ Ŭ���� �ۿ����� CStudent::totalNum�� ���� ����

int main()
{
	CStudent a, b, c;
	CStudent arr[10];
	CStudent d, e;
	c.print();
	d.print();

	//cout << "�� ���� " << a.totalNum << " " << b.totalNum << " " << d.totalNum << endl;
	func();

	return 0;
}

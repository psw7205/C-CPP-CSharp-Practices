#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
	string name;
public:
	Person() {	} // �̹� �Էº����� �ִ� �����ڰ� �־� �⺻ �����ڸ� �߰��߽��ϴ�. 
	Person(string in_name) { this->name = in_name; }
	void setName(string in_name) { this->name = in_name; } // this�����͸� �̿��� �̸��� PersonŬ������ name ������ �����߽��ϴ�. 
	string getName() { return name; }
};

class Family
{
private:
	Person * p;
	int size;
	string m_name; // Family�������� �̸��� ������ �����Դϴ�.
public:
	Family(string in_name, int in_n);
	void show();
	void setName(int in_i, string in_name);
	~Family();
};

Family::Family(string in_name, int in_n)
{
	p = new Person[in_n];
	this->m_name = in_name;
	this->size = in_n;
} // Family name�� ��������� ��������� �����ϰ� ���� �� ��ŭ Person Ŭ������ �����Ҵ��մϴ�

void Family::show()
{
	cout << m_name << "������ ������ ���� " << size << "�� �Դϴ�." << endl;
	for (int i = 0; i < size; i++)
	{
		cout << p[i].getName() << "\t";
	}
} // ����� Famliy name�� ���������� ����մϴ�.

void Family::setName(int i, string in_name)
{
	p[i].setName(in_name);
}  // ���� �������� �̸��� �����մϴ�.

Family::~Family()
{
	delete[] p;
} // �����Ҵ��� PersonŬ���� �迭�� ��ȯ�մϴ�.

int main()
{
	Family *simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}
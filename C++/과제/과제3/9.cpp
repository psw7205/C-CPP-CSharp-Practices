#include<iostream>
#include<string>
using namespace std;

class Circle
{
private:
	int radius;
	string name;
public:
	void setCircle(string in_name, int in_radius);
	double getArea();
	string getName();
};

class CircleManger
{
private:
	Circle * p;
	int size;
public:
	CircleManger(int in_size);
	~CircleManger();
	void searchByName();
	void searchByArea();
};
void Circle::setCircle(string in_name, int in_radius)
{
	this->name = in_name;
	this->radius = in_radius;
} // ���ڷ� �Է¹��� �������� ��������� �����մϴ�.
double Circle::getArea()
{
	return 3.14 * radius * radius; // pi*r^2�� ���� �����մϴ�.
}
string Circle::getName()
{
	return name; 
}

CircleManger::CircleManger(int in_size)
{
	string name;
	int r = 0;
	p = new Circle[in_size];
	this->size = in_size;
	for (int i = 0; i < in_size; i++)
	{
		cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
		cin >> name >> r;
		p[i].setCircle(name, r);
	}
} // Circle �迭�� �����Ҵ��ϰ� �̸��� �������� �Է¹޽��ϴ�.
CircleManger::~CircleManger()
{
	delete[] p;
} // �����Ҵ� ���� Circle Ŭ���� p �迭�� ��ȯ�մϴ�. 
void CircleManger::searchByName()
{
	string name;
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	cin >> name;
	for (int i = 0; i < size; i++)
	{
		if (p[i].getName() == name)
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << endl;
	}
} // �̸��� �Է¹ް� ����� �̸��� ���� �� ���� ��� ����մϴ�. 
void CircleManger::searchByArea()
{
	int area = 0;
	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	cin >> area;
	cout << area << "���� ū ���� �˻��մϴ�" << endl;

	for (int i = 0; i < size; i++)
	{
		if (p[i].getArea() >= area)
		{
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << ",";
		}
	}
	cout << endl;
} // �� ������ ū ��츦 ã�� ����մϴ�.

int main()
{
	int n = 0;

	cout << "���� ���� >> ";
	cin >> n;

	CircleManger c(n);
	c.searchByName();
	c.searchByArea();

	return 0;
}
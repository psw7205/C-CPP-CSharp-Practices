#include <iostream>
#include <string>
using namespace std;

class CShape // �θ� Ŭ����
{
private:
protected:
	double x, y;
	string color;
public:
	CShape()
	{
		x = 0;
		y = 0;
		color = "black";
	}

	CShape(double _x, double _y, string c)
	{
		x = _x;
		y = _y;
		color = c;
	}

	void print()
	{
		cout << x << "," << y << " - " << color << endl;
	}
};

class CRect : public CShape // CRect Ŭ������ CShape Ŭ������ ��ӹ���, private�� ���� �Ұ� protected ���� ���� ����
{
private :
	double width, height;
public:

	CRect() {};

	CRect(double w, double h)
	{
		width = w;
		height = h;
	}

	CRect(double x, double y, string c, double w, double h)
		: CShape(x, y, c) // �θ�Ŭ������ �����ڸ� ��� ȣ���� �� ���, ���ٸ� ����Ʈ�����ڰ� ȣ���
	{
		width = w;
		height = h;
	}
	void printRect()
	{
		cout << x << "," << y << " - " << color;
		cout << " - " << width << "," << height << endl;
	}

	void print() // ���� �̸��� �Լ��� ���� ���� ����, �Լ��������̵�
	{
		cout << x << "," << y << " - " << color;
		cout << " - " << width << "," << height << endl;
	}
};

/*
class a
class b : a
class c : b
�����ڴ� a - b - c ������ ȣ��ǰ�
�Ҹ��ڴ� c - b - a ������ ȣ��ȴ�.
*/

int main()
{
	CShape a;
	a.print();

	CRect b;
	b.printRect(); // �θ�Ŭ������ �⺻�����ڰ� ȣ��Ǽ� x, y�� 0���� �ʱ�ȭ�ȴ�. b�� �⺻ �����ڰ� ���� ������ width�� height�� ������ ���� ����Ǿ��ִ�.

	CRect c(15, 20);
	c.print(); // CShape���� print()�� ������ CRect Ŭ������ �ִ� print()�� ȣ��� , �Լ� �������̵�, ���� �̸��� �Լ����� Ŭ������ ���� �ٸ��� ȣ�� ����

	CRect d(10, 20, "red", 100, 100);
	d.print();

	return 0;
}
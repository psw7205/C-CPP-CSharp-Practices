#include <iostream>
using namespace std;

class CCircle
{
public:
	double m_x, m_y;
	double m_r;
	void setRadius(double in_r, CCircle c)
	{
		m_r = in_r;

		if (isOverlap(c, *this) == true) // �� ��ü�� Ȱ���� ����ϴ� �Լ��� ��ǲ���� �����ڽŸ� �ְ� ���� ��
		{
			m_r == 0;
		}

	}

	/* 1
	double r;
	void setRadius(double r)
	{
		this; // ����Լ� �ȿ��� �ڵ����� ȣ��� �� �ּҸ� �˷���
		cout << this << endl;
		r = r;
	} // ������ ������ �򰥸�, this->r �� ������ ���� ����
	*/

};

bool isOverlap(CCircle a, CCircle b)
{
	double dist = (a.m_x - b.m_x)*(a.m_r - b.m_x) + (a.m_y - b.m_y)*(a.m_y - b.m_y);
	dist = sqrt(dist);
	double r2 = a.m_r + b.m_r;
	if (dist > r2)	return true;
	else false;
} // �� ���� ��ġ�� true �ƴϸ� false


int main()
{
	CCircle a, b;

	/* 1
	cout << &a << endl;
	cout << &b << endl;
	*/

	a.setRadius(10, b);
	b.setRadius(20, a);


	return 0;
}
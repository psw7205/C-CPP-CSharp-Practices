#include <iostream>
using namespace std;

class CCircle
{
public:
	CCircle()
	{
		m_x = 0; m_y = 0;
		m_r = 1;
		cout << "a circle is creationg" << endl;
	}
	~CCircle()
	{
		cout << "a circle is dying" << endl;
	}

	double m_x, m_y;
	double m_r;
	void setRadius(double in_r); // �Լ� ����� declaration, prototype
	
	double getRadius()
	{ 
		return m_r;
	}
	
	//double getCenter() { return x, y; } // ���� 2�� �Ұ��� 
	double getCenter(double *x, double *y)
	{
		*x = m_x;
		*y = m_y;
	}
	/*
	bool isBig(CCircle * a) // Ŭ������ ���� �� �����ͳ�
	{
		if (m_r > a->m_r) return true;
		return false;
	}
	*/
	bool isBig(CCircle & a) // ���۷����� �޴´�, ���۷����� ������ ���� ��������� �ʰ� main�Լ��� ���ڸ� �״�� �����
	{
		if (m_r > a.m_r) return true;
		return false;
	}
	
	CCircle & getMe()
	{
		return *this;
	} // �ڱ��ڽ��� �Ѱ��� �� ���۷��� ��� 

	double & getX()
	{
		return m_x;
	}

};

void CCircle::setRadius(double in_r) // ����, ������ definition, implimentation
{
	m_r = in_r;
}


int main()
{
	CCircle a, b;
	a.m_r = 1;
	CCircle & r = a; // referencing ������ �������, ������ �׻� �̸��� �־�� �ϰ� �׳� ���� �Ұ�, ���۷��� ������ �ִٸ� �ݵ��� ���� �ִ� ������
	/*
	CCircle & r;
	r = a; // �Ұ���, ���������� ��������
	*/

	r.m_r = 10; //a.m_r�� ���� 10���� ����
	
	/*
	CCIrcle b = a; // ������ ���� �ٷ� ���� ��, ���߿� �Ҹ��ڸ� �Ҹ�
	��
	CCIrcle b;
	b = a;
	�ΰ��� ���� �ٸ� ������ �Ͼ
	*/

	/*
	a.setRadius(10);
	b.setRadius(20);

	double x, y;
	double r;
	r = a.getRadius();
	a.getCenter(&x, &y);
	*/

	if (a.isBig(b) == true) cout << "a is bigger than b" << endl;
	else cout << "b is bigger than a" << endl;

	double x = a.getMe().getMe().m_x;


	return 0;
}

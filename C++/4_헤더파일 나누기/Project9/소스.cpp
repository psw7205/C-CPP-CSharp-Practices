#include <iostream>
using namespace std;

#include "CStudent.h"
#include "CLecture.h"

int main()
{
	CStudent a("kim");
	a.print();

	CStudent b("Lee");
	b.print();

	/*
	CStudent *p; // �ʱ�ȭ ���ϰ� �����͸� �����ϴ°� ������ ����
	p = &a; 
	(*p).print();
	*/

	CStudent *p = &b; // �����ʹ� �׳� �����ϱ⸸ �ؼ� �ƹ� �ǹ� ���� �׻� ����� ���ÿ� �ʱ�ȭ �ؾ� �Ǽ�����, �ʼ�
	(*p).print();  // �ϳ��� ������ ���� �����͸� �ٲ�ġ�� ��밡�� 
	p->print(); //20�� 21�� ���� ���� 

	CLecture cpp;
	cpp.m_pStudents[0] = &a;
	cpp.m_pStudents[1] = &b;

	CLecture mp;
	mp.m_pStudents[0] = &a; 

	a.m_name = "park"; // �����ͷ� �����ϸ� �����͸� �ٲܶ� ���� �ٲ� �ʿ� ����
	cpp.m_pStudents[0]->print();
	

	return 0;
}
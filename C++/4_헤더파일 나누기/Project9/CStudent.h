#ifndef _STUDENT_H_ // �� ���ڰ� ���ǰ� �ȵ�������
#define _STUDENT_H_ // �� ���ڸ� �����ض� ���� ���ִٸ� �ǳʶ�� = #pragma once : VS���� �ٸ� ide���� ������

#include<string>
using namespace std;

class CStudent
{
private:

	int m_num;
public:
	CStudent();
	~CStudent();
	CStudent(string in_name);
	double m_score;
	string m_name;

private:
	// setting the num
	void setNum();
public:
	void print();
};

#endif

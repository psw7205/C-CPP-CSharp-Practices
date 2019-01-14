#include<iostream>
#include<string>
#pragma warning(disable: 4996)//vs2017���� strtok�� c4996 ������ ����

using namespace std;

/*
struct student
{
	string name;
	int num;
	double score;

}; // ����ü

void printStudent(student in)
{
	cout << "�̸�:" << in.name << endl;
	cout << "�й�:" << in.num << endl;
	cout << "����:" << in.score << endl;
}

void computeScore(student *in, int m, int k, int e)
{
in->num = (m + k + e) / 3.0f;
}
*/

int total_num = 0;

class student
{
	int num;

	void setnum()
	{
		total_num++;
		num = total_num;
	} // �й��� ����ڰ� ������ �� ������ �Ź� ȣ���ؾ��ϰ� �Ǽ�(�ߺ� ��)�� ���� �� �ֱ⿡ ���н�Ŵ

public: // ����Ʈ���� ����, public�� �̿� �ۿ��� ���� �����ϰ� ��, num�� ���� �Ұ��� public���ϴ� ���� ����
	
	string name;
	double score;

	student() // ����Ʈ ������
	{
		name = "����";
		setnum();
		score = 0;
	}

	student(string in_name) // constructor ������, �� ������ �־�߸� �������� ����
	{
		name = in_name;
		setnum();
	} // ���� �ҋ� �ݵ��� name�� �־�� �������� ����, �ڵ����� �й��� �ο�(����ڰ� ��Ʈ�� X)

	student(string in_name, double in_score) // constructor ������, �� ������ �־�߸� �������� ����
	{
		name = in_name;
		setnum();
		score = in_score;
	} // �����ڴ� ������ �������� ���ڿ� ���� �˾Ƽ� ȣ���

	void print();

	void computeScore(int m, int k, int e)
	{
		score = (m + k + e) / 3.0f;
	}


}; // ����ü���� ������ �Ӹ��ƴ϶� �Լ����� ���ӽ�Ŵ 
// �ۼ����� �ǵ� �߰�(����ڰ� ������� ���ϰ�) struct -> class


void student::print()
{
	cout << "---------------------------------" << endl;
	cout << "�̸�:" << name << endl;
	cout << "�й�:" << num << endl;
	cout << "����:" << score << endl;
	cout << "---------------------------------" << endl;
} // clss�ۿ��� ���� ����



int main()
{
	student a("kim");
	//student a; a.name = "kim"; �Ұ��� 
	//a.num = 10; // class���� ����ڰ� ���� �Ұ����ϰ� ����
	//a.setnum();
	a.computeScore(100, 90, 90); //computeScore(&a, 100, 90, 90); ���� �Ƚ����� �� �����͸� �̿��ؼ� �Լ�ȣ��
	a.print();

	student b("park");
	b.computeScore(10, 20, 20);
	b.print();

	student c("Lee", 30);
	c.print();

	student d;
	d.print();

	return 0;
}

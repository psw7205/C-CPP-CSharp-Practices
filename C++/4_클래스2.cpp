#include<iostream>
using namespace std;
#include<string>

int total_num = 0;

class student
{
private: // �� ���� �ڵ������� �ۺ� ���� �����̺����� ������
	int num;


	void setnum()
	{
		total_num++;
		num = total_num;
		
	} 

public:
	student();
	student(string in_name);
	student(string in_name, double in_score);

	~student()
	{
		cout << name << " is distructed" << endl;
	}	// �Ҹ��� : ���� �ѹ��� �ڵ�ȣ��, ������ �Ҹ� �ñ� Ȯ�� ����, ���� �޸� ���� ��� ... 
		//c���� �ۼ��ڰ� �޸𸮸� ���� �����������, �Ҹ��Ű�� �ʴ´ٸ� �����Ͱ� �����Ǿ� �޸� ������ ����

	string	name;
	double score;


	void print()
	{
		cout << " name : " << name << endl;
		cout << " num : " << num << endl;
		cout << " score : " << score << endl;
	}

};

student::student()
{
	name = "none";
	setnum();
	score = 0;
	cout << name << " is created" << endl;
} // default constructor ���⺻ ������ 

student::student(string in_name)
{
	name = in_name;
	setnum();
	score = 0;
	cout << name << " is created" << endl;
}// ������ : �ݵ��� �ѹ�, ��ó�� ȣ���Ŵ, ������ �ʱ�ȭ ����

student::student(string in_name, double in_score)
{
	name = in_name;
	setnum();
	score = in_score;
	cout << name << " is created" << endl;
}// ���� �ٸ� ������ ���� ����

student g("global");
void func()
{
	student l("local");
}

class smartarray
{
	int size;
	int *data;
public:
	smartarray(int s)
	{
		size = s;
		data = (int*)malloc(sizeof(int)*size);
	}
	smartarray()
	{
		free(data);
	}
	int & operator [] (int ind)
	{
		return data[ind];
	} // [ind]�� ���� data[ind]�� �ٲ� 

};



int main()
{
	student a("Lee"), b("park"), c;

	{
		student ll("lol");
	} // �߰�ȣ�� ������ ������ ����, �Ҹ��ڷ� Ȯ�� ����

	a.score = 100;

	a.print();
	b.print();
	c.print();

	func();

	/*
	int *data = (int *)malloc(sizeof(int) * 100);
	data[0] = 1;

	free(data); // ����� �������� �Ҹ���Ѿ� ������ ������ �Ȼ���
	���� �Ҵ� ���� */

	smartarray arr(100);
	//arr.data[10] = 1;
	arr[10] = 1; //operator�� ��� ���� 

	cout << arr[10] << endl;

	return 0;
}
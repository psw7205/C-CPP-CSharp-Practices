#include<stdio.h> // Cǥ��, C++ǥ���� <cstdio>
#include<iostream> // input output stream
using namespace std;

namespace sejong // namespace ������
{
	int a = 5;
}


int main()
{

	printf("hellow world\n");


	std::cout << "hellow world\n";
	//console out, ��������
	//standard�� ���� cout�̶�� ����

	char s[] = "world!";
	int a = 10;
	std::cout << "hellow " << s << a << std::endl ;
	// ����Ϳ� hellow���� ������ s������ a�� ����
	printf("hellow %s %f \n", s, a); // %fó�� �ڷ��� �Ǽ��� ������
	// std::endl == \n
	
	// A::B -> A namespace�� B�� �ҼӵǾ��ִ�

	//3���� ����� std::��������
	//#inclued<iostream>�� using namespace std;�� �׻� ����
	cout << "hellow " << s << a << endl;
	cout << sejong::a << endl;



	return 0;
}
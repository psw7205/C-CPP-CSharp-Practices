#include<iostream>
using namespace std;

int main()
{
	int age;
	double score;
	
	
	printf("Input Age : ");
	scanf_s("%d", &age);
	printf("Age : %d\n", age);
	//���� C��� �ڷ����� ���� %d, %f�� �����ڸ� ������� 
	

	cin >> age >> score;
	cout << "your age is " << age << endl;
	cout << "your score is " << score << endl;
	
	// C�ʹ� �ٸ��� >> �� �˾Ƽ� �� ������

	return 0;
}
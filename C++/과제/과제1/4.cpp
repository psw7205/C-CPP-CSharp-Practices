#include<iostream>
using namespace std;


int main()
{
	float AR[5]; // �Ǽ��� ������ double�� �迭
	float max = 0; // �ִ밪�� ������ ����

	cout << "5���� �Ǽ��� �Է��϶�>>" ;

	for (int i = 0; i < 5; i++)
	{
		cin >> AR[i];
	} // AR[0]~AR[4]���� 5���� �Ǽ� �Է�

	max = AR[0];

	for (int i = 1; i < 5; i++)
	{
		if (max < AR[i])
			max = AR[i];
	} // max�� AR[i]���� ���� �� AR[i]�� max�� ����

	cout << "���� ū �� = " << max << endl;

	return 0;
}

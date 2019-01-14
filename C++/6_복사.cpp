#include<iostream>
using namespace std;

class CMyArray
{
private:
	CMyArray(CMyArray & in) {}; //private�� ���´ٸ� ���簡 ������
	int m_size;
	int* m_pData;
public:
	CMyArray(int size)
	{
		m_size = size;
		m_pData = new int[size]; // Ŭ������ 8����Ʈ�� �����Ҵ�� �޸𸮴� Ŭ���� ��(��)�� �����
	}

	CMyArray(CMyArray & in) // copy constructor 
	{
		m_size = in.m_size;
		m_pData = new int[m_size];
		for (int i = 0; i < m_size; i++)
			m_pData[i] = in.m_pData[i];
	} // ���� ������ (���� ����) : ���� �ȸ���� �شٸ� �⺻ ���� �����ڰ� ��������� ���� ����� �����

	~CMyArray() { delete[] m_pData; }
	int getSize() { return m_size; }
	/*
	int getAt(int ind) { return m_pData[ind]; }
	void setAt(int ind, int value) { m_pData[ind] = value; }
	*/
	int & at(int ind) { return m_pData[ind]; } // ���ϰ� ������ �� �ΰ� �Լ� ���� ���� (���� �Լ��� ���� �� ������ٸ� �翬�� �ȵ�)

	int & operator [] (int ind) { return m_pData[ind]; }

	CMyArray & operator = (CMyArray & in)
	{
		delete[] m_pData;
		m_size = in.m_size;
		m_pData = new int[m_size];
		for (int i = 0; i < m_size; i++)
			m_pData[i] = in.m_pData[i];
		return *this;
	} // �Ҵ� 

};

/*
int sumi(int a, int b) { return a + b; }
double sumd(double a, double b) { return a + b; } 
C���� ���ڿ� ���� �ٸ� �ڷ����� ���� �ٸ� �̸��� �Լ����� �ʿ��� 
C++���� ���� �̸��� �Լ��� ���ڸ� �ٸ��� �ߺ� ����
*/

int sum(int a, int b) { return a + b; }
double sum(double a, double b) { return a + b; }
float sum(float a, float b) { return a + b; }

int main()
{
	cout << sum(10, 20) << endl;
	cout << sum(10.5, 20.8) << endl;

	CMyArray arr(10);

	/*
	for (int i = 0; i < arr.getSize(); i++)
		arr.setAt(i, i * 2);
	for (int i = 0; i < arr.getSize(); i++)
		cout << i << " : " << arr.getAt(i) << endl;
	*/

	for (int i = 0; i < arr.getSize(); i++)
		// arr.at(i) = i * 2 ;
		arr[i] = i * 2; // operater []�� ���̸� m_pData[ind]�� ���� 
	for (int i = 0; i < arr.getSize(); i++)
		cout << i << " : " << arr[i] << endl;// arr.at(i) << endl;

	CMyArray brr = arr;
	/*
	copy constructor, copy �ϰ� �Ǹ� int m_size�� int * m_pData�� ������
	������ �ּҵ� �����ϱ� ������ b�� �ٲ㵵 a�� �ٲ�, b�� a ��� �� �����͸� ����Ŵ
	���� ����(shallow copy) ���̴� �͸� ������
	-----------------------------------------------
	CMyArray brr;
	brr = arr; // assignment (�Ҵ�)
	����� �Ҵ��� �ٸ���...
	*/

	CMyArray crr(arr); // == CMyArray crr = arr; 

	for (int i = 0; i < arr.getSize(); i++)
		brr[i] = i * 3; 
	for (int i = 0; i < arr.getSize(); i++)
		cout << i << " : " << brr[i] << endl;

	for (int i = 0; i < arr.getSize(); i++)
		cout << i << " : " << arr[i] << endl; // b���� �ٲ������� a���� ���� �ٲ� ��� �� �����͸� ����Ű�� ����...

	return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<list> // vector�� ���Ḯ��Ʈ ����
using namespace std;

/*
generic programming (�Ϲ��� ���α׷���) = template
�Լ��� ������ Ÿ�Կ� ���ӵ��� �ʰ� �Ϲ������� ��� �����ϰ� �ϴ� ���α׷���
���ø��̶� ������� ����
���� : ������ ����, ������ ��Ʈ���� �� Ư�� �о߿��� �ſ� ������ 
���� : �б� ����(�������� �ſ� ������), ������� �����

STL - ǥ�� ���ø� ���̺귯��
����
�����̳� - ���ø� Ŭ����
iterator - �����̳� ���ҿ� ���� ������
�˰��� - ���ø� �Լ�
*/

template <class T> //���ø� �Լ�, T�� �׶��׶� �ٲ�ġ����
T bigger(T a, T b)
{
	if (a > b)
		return a;
	return b;
}

template <class T, class S> // �ɺ� ������ ���� ���� 
S div(T a, T b)
{
	S out;
	out = (S)a / (S)b;
	return out;
}

template <class T>
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

// class���� typename�� ���� 
template<typename T>  // ���ø� Ŭ����
class SmartArr
{
	T *data;
	int size;
public:
	SmartArr(int n)
	{
		size = n;
		data = new T[n];
	}

	~SmartArr() { delete[] data; }

	T & operator[](int ind){ return data[ind];	}

	int getsize() { return size; }
};

int main()
{
	cout << bigger<int>(3, 4) << endl;
	cout << bigger<double>(3.3, 4.2) << endl;
	cout << bigger<char>('a', 'b') << endl; // ���ڰ� ��Ȯ�Ѱ�� <>�� �����ص� ����

	cout << div<int, double>(3, 4) << endl;

	int a = 10; 
	int b = 20;

	mySwap(a, b);
	cout << a << endl;

	string c = "abc";
	string d = "def";

	mySwap(c, d);
	cout << c << endl;

	SmartArr<int> arr(10);
	
	for (int i = 0; i < arr.getsize(); i++)
		arr[i] = i * 2;
	for (int i = 0; i < arr.getsize(); i++)
		cout << arr[i] << endl;

	vector<string> arr2(10); // SmartArr�� ���� ������ �̹� ��������ִ� ���ø� Ŭ����
	for (int i = 0; i < arr2.size(); i++)
		arr2[i] = "aaa";
	for (int i = 0; i < arr2.size(); i++)
		cout << arr2[i] << endl;

	vector<int> arr3;
	for (int i = 0; i < 10; i++)
		arr3.push_back(i); // �ڿ� �߰��ϴ� �Լ� - �̹� �����Ǿ�����. �׳� ���ͳݿ��� ã�ƺ��� ���� ��

	arr3.resize(20, 100); // ����� 20 �� ���� 100���� �ʱ�ȭ 

	for (int i = 0; i < arr3.size(); i++)
		cout << arr3[i] << endl;


	list<int> arr4; //���Ḯ��Ʈ�̱� ������ �˻������� ��ȸ�ؾ���
	for (int i = 0; i < 10; i++)
		arr4.push_back(i);

	list<int>::iterator it; // int������ list�� ����Ű�� ���ͷ����� it

	it = arr4.begin(); // ���� ��带 ����Ŵ

	while (it != arr4.end()) // ���� �ƴҶ�����
	{
		cout << (*it) << endl; // ������ �ּҰ� ����Ű�� ��
		it++; // �������� �Ѿ it = it -> next;
	}

	it = arr4.begin(); // ó���� ����Ű��
	it++;
	it++;
	it++; // 3��° ĭ���� �̵���Ű��

	arr4.erase(it); // ������

	arr4.sort();// ����
	arr4.unique(); // �Ѱ��� ��� 


	return 0;
}
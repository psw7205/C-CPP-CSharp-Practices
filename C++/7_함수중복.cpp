#include<iostream>
#include<string>

using namespace std;

class CMyClass
{
public:
	int x, y;
	CMyClass() { x = 1; y = 2; }
	CMyClass(int _x, int _y) { x = _x; y = _y; }
	//== CMyClass(int _x = 1, int _y = 2) { x = _x; y = _y; } // �ΰ� �ϳ��� ���� ����
};

// �ߺ��� ��ȣ�ϸ� ������ �׻� ���� ���� ��Ȯ�ϰ� �ڵ�

void func(int w, int h = 3, char c = '*') // c�� ���ָ� *�� ��� ������ �ָ� �װɷ� ���� (����Ʈ �Ű�����)
{										  // ����Ʈ �Ű������� ���� �����־����, �ʼ��� �������� ������
	for (int j = 0; j < h; j++)			  // Ŭ���� �����ڿ����� ��� ����
	{
		for (int i = 0; i < w; i++)
			cout << c;
		cout << endl;
	}
}

int main()
{
	func(3);
	func(3, 5, '&');
	func(3, 5);
	
	CMyClass a;

	
	return 0;
}


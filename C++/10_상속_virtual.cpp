#include<iostream>
using namespace std;

class CShape
{
public:
	int x, y;
	
	CShape()
	{
		x = 0;
		y = 0;
	}

	CShape(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	virtual ~CShape() {} // �ּҿ� �����ϴ� ��¥ �����Ϳ� �´� �Ҹ��ڸ� ������

	virtual void draw() // virtual, �ּҿ� �����ϴ� ��¥ �Լ��� �����Ѵ�. ���� ���ε� ���þ�
	{
		cout << "Shape:(" << x << "," << y << ")" << endl;
	}

};

class CRect: public CShape  
{// ���� �θ�Ŭ������ ���� ���� ���� �ƴϰ� � ������� ���ư��� �� �𸣱� ������ �׻� ���� ���� Ŭ������ ������ �ǵ帰��.
public:
	int w, h;
	CRect() // : CShpae() , �Ƚ��ָ� �θ�Ŭ������ ����Ʈ �����ڰ� �ڵ����� ���Ե�
	{
		w = 1;
		h = 1;
	}

	CRect(int _x, int _y, int _w, int _h)
		: CShape(_x, _y)
	{
		w = _w;
		h = _h;
	}

	void draw() // overriding �θ� Ŭ������ �Լ��� �ڱⰡ ����, �߰��ؼ� ��� ����.
	{
		// CShape::draw(); // �θ�Ŭ���� CShape�� draw()�Լ��� ���� �����ϰ� �߰������� �ٸ� �ڵ带 ������
		cout<<"Rect:(" << x << "," << y << ") " << w<< "," << h <<  endl;
	}

};

class CCircle : public CShape
{
public:
	int r;
	CCircle()
	{
		r = 1;
	}
	CCircle(int _x, int _y, int _r)
		:CShape(_x, _y)
	{
		r = _r;
	}
	
	void draw()
	{
		cout << "Circle:(" << x << "," << y << ") " << r << endl;
	}
};

void func(CShape *o)
{
	o->x += 10;
	o->y += 10;
}

int main()
{
	CShape a;
	CRect b;
	CRect c(1, 2, 3, 4);

	CShape d = c; // ���� �ٸ� Ŭ����(�ڽ�->�θ�)���� ���� ���� : ��������ȯ up casting
	// CRect e = a; �θ� -> �ڽ��� �Ұ��� : ��������ȯ X down casting(w, h�� �ʱ�ȭ �� ����� ��ȣ�ϱ� ������...)

	CShape *p1 = &c; // �������� ��������ȯ�� ������ ����
	p1->draw(); // c�� CRectŬ�������� p1�� CShape�� ������ ����ϹǷ� CShape::draw()�� �����

	// CRect *p2 = &a; // �������� ��������ȯ�� Ư�� ������ ���� ���� 
	CRect *p2 = (CRect*) p1; // CShape ���������� �ּҰ� ����Ű�� c�� CRect�̹Ƿ� ��������ȯ���� ��� ����
	p2->draw();

	a.draw();
	b.draw();
	c.draw();
	d.draw(); 

	CShape *p[3]; // �ϳ��� �迭�� ���� �ٸ� Ŭ������ �ϳ��� ��� ���� ����
	p[0] = new CShape (20, 10);
	p[1] = new CRect(1, 2, 3, 4);
	p[2] = new CCircle (10, 20, 100);

	CRect *r = (CRect*)p[1];
	r->w = 10; 

	func(p[2]);

	for (int i = 0; i < 3; i++)
		p[i]->draw(); // virtual������ �߱⿡ �Ҹ��� ������ ��¥ �����͸� Ȯ���ϰ� ���� , ���� ���ε� : ������ (polymorphism)

	for (int i = 0; i < 3; i++)
		delete p[i]; 
	
	return 0;
}
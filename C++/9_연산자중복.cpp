//operator overload ������ �ߺ�

#include<iostream>
using namespace std;

class CComplex
{
private:
	double real, img;
public:
	CComplex()
	{
		real = 0;
		img = 0;
	}

	CComplex(double a, double b)
	{
		real = a;
		img = b;
	}

	void print()
	{
		cout << "(" << real << "+" << img << "i)" << endl;
	}
	/* 1
	CComplex add(CComplex in)
	{
		CComplex out;
		out.real = real + in.real;
		out.img = img + in.img;
		return out;
	}
	*/
	/* 2
	static CComplex add(CComplex l, CComplex r)
	{
		CComplex out;
		out.real = l.real + r.real;
		out.img = l.img + r.img;
		return out;
	} // �������� ����
	*/
	/* 3
	friend CComplex add(CComplex l, CComplex r); // friend�� ���� �ϸ� ����ƽ���� ���� �� ó�� CComplex::�� �Ƚᵵ ��
	*/
	/* 4
	CComplex operator+( CComplex r)
	{
		CComplex out;
		out.real = real + r.real;
		out.img = img + r.img;
		return out;
	}
	*/	

	CComplex &operator= (const CComplex & r) // const�� ������ ������ ��븸 �ϰ� ���� ���� �� ������ �Ұ�����
	{
		real = r.real;
		img = r.img;
		return *this; // �Ҵ��� �����ϰ� �ڱ��ڽ��� ����
	} // �Ҵ�(=) ������ ����Լ��θ� ���� 

	double & operator[] (int ind)
	{
		//if(ind < 0 || ind >= 2) // ����ó���ʿ�... ,���� �����̱⿡ �ٸ� ����� ����
		if (ind == 0) return real;
		if (ind == 1) return img;
	}

	friend CComplex operator+(CComplex l, CComplex r);
	friend CComplex operator*(CComplex l, CComplex r);
	friend CComplex operator!(CComplex r);
	friend CComplex operator*(double a, CComplex r);
	friend ostream & operator<<(ostream & stram, const CComplex in);

	// ������ �޴°� ����
};
/* 3
CComplex add(CComplex l, CComplex r)
{
	CComplex out;
	out.real = l.real + r.real;
	out.img = l.img + r.img;
	return out;
}
*/
CComplex operator+(CComplex l, CComplex r)
{
	CComplex out;
	out.real = l.real + r.real;
	out.img = l.img + r.img;
	return out;
} // Ŭ���� �ȿ� ��� �Լ��� �����ϸ� ���ڴ� �ϳ��� ���� �� �ְ� �ٸ� �ϳ��� ������� ������ ��

CComplex operator*(CComplex l, CComplex r)
{
	CComplex out;
	out.real = l.real * r.real - l.img * r.img;
	out.img = l.real * r.img  + l.img * r.real;
	return out;
}
CComplex operator*(double a, CComplex r)
{
	CComplex out;
	out.real = a * r.real;
	out.img = a* r.img;
	return out;
}

CComplex operator!(CComplex r)
{
	CComplex out;
	out.real = r.real;
	out.img = - r.img;
	return out;
}

ostream & operator<<(ostream & stream, const CComplex in)
{
	stream<< "(" << in.real << "+" << in.img << "i)" << endl;
	return stream;
}

int main()
{
	CComplex a(3, 4), b(2, 7);
	
	/* 1
	CComplex c = a.add(b); // = b.add(a) // c = a + b
	a.add(b); // a = a + b ... ? �Լ��� ���� �� �ǹ̰� ȥ���Ǳ� ������ 
	*/

	/* 2
	CComplex c = CComplex::add(a, b); // CComplex:: �� ���� ����...
	*/
	/* 3
	CComplex c = add(a, b);
	*/
	CComplex c = a + b; // operator+(a, b) == a.operator(b)
	CComplex d = a * b; // �������� �����ǰ� �ʿ���
	CComplex e = a * (!a);
	CComplex f = 3 * a;
	CComplex g;
	g = 2 * a + 3 * b; // �Ҵ� 

	a.print();
	b.print();
	c.print();
	d.print();
	e.print();
	f.print();
	g.print();

	cout << a[0] << "+" << a[1] << endl;

	for (int i = 0; i < 2; i++)
		b[i] = a[i]; // ����...

	cout << a; //  <<(cout, a) // operator<< �����Ƿ� a.print()�� �����
	cout << a << b; //  <<(<<(cout, a),b)

	return 0;
}
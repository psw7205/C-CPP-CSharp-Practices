interface comparable {
	public boolean compareTo(Object o); // �������̽��� ��ΰ� �ۺ��̿��� ��
}

interface drawable {
	public static final int MAX = 100;

	public void colorDraw();
}

class MyMouse implements drawable, comparable { // �������̽��� ������ ���� ����
	public void colorDraw() {
	}

	public boolean compareTo(Object o) {
		return false;
	} // �������̽��� ������ ��������� ��
}

abstract class abstractShape {
	// �߻�޼ҵ带 �ϳ��� ������ �ִٸ� �߻�Ŭ������ ��
	// ���� �������� ���� ���, �߻�޼ҵ尡 ��� �߻� Ŭ���� ����

	abstract void draw(); // �߻� �޼ҵ�, ������ ������ ������ ���� �޼ҵ�, ��ӹ����� ������ ���� ����� ��

	void tmp() {
	}; // �׳� ��� �� �Լ��� ���� ���ص� ��� ����
}

class MyShape {
	MyShape() {
		x = 0;
		y = 0;
		color = "white";
	}

	MyShape(double _x, double _y, String _s) {
		x = _x;
		y = _y;
		color = _s;
	}

	double x, y;
	String color;

	void draw() {
		System.out.println("[SHAPE] (" + x + "," + y + ") �� : " + color);
	}

}

class MyRect extends MyShape {
	MyRect(double _x, double _y, double _w, double _h, String _c) {
		super(_x, _y, _c); // �θ��� �����ڸ� �̿��� ����
		w = _w;
		h = _h;

	}

	double w, h;

	@Override // �ǵ��� �������̵��̶��
	void draw() {
		System.out.println("[RECT] (" + x + "," + y + ") (" + w + "," + h + ") �� : " + color);
	}

	public boolean equals(Object obj) {
		if (obj instanceof MyRect) {
			MyRect r = (MyRect) obj;
			if (w == r.w && h == r.h)
				return true;
		}

		return false;
	}

	public String toString() {
		return "MyRect!!!!!";
	}
}

class MyCircle extends MyShape {
	MyCircle(double _x, double _y, double _r, String _c) {
		super(_x, _y, _c);
		r = _r;
	}

	double r;

	@Override
	void draw() {
		System.out.println("[CIRCLE] (" + x + "," + y + ") (" + r + ") �� : " + color);
	}
}

public class Polymorphism {

	public static void draw(drawable o) { // Į��׸��� ����� �ִ� ��� ��ü�� ���ڷ� ����
		o.colorDraw();
	}

	public static void main(String[] args) {

//		MyShape p = new MyShape(10, 10, "red");
//		MyRect q = new MyRect(20, 30, 40, 50, "blue");
//		MyCircle r = new MyCircle(40, 50, 10, "green");
//
//		p.draw();
//		q.draw();
//		r.draw(); 
//		�������� ��ü�� ������ �ϳ��� ���� �ϱ����ؼ� superŬ������ �迭(���Ḯ��Ʈ)�� �����ؾ���

		MyShape[] arr = new MyShape[3];
		arr[0] = new MyShape(10, 10, "red");
		arr[1] = new MyRect(20, 30, 40, 50, "blue");
		arr[2] = new MyCircle(40, 50, 10, "green");

		for (int i = 0; i < arr.length; i++)
			arr[i].draw(); // MyShape �迭������ �������ε� �Ǿ��⿡ ���� ����� �������̵��� �Լ����� ȣ����
		// �ϳ��� draw()�� �Լ��� �ٸ��� ������ -> polymorphism

		for (int i = 0; i < arr.length; i++)
			System.out.println(arr[i]); // ��� Ŭ������ ObjectŬ������ ��� �ޱ⿡ toString()�� �������̵��� ��� ����

	}

}

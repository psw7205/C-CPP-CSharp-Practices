package sejonguniv;

// import sejonguniv.software.MyMath;
import sejonguniv.software.*; // �� ��Ű�� �Ʒ��� �ִ� ��� Ŭ���� ��� ����
// import : ã�ٰ� �𸣴� �Լ��� ������ �� ��Ű�� �� �Լ����� Ȯ���غ���
// ���� �ҹ��ڷ� �ۼ�, ū���� -> ��������
// ���丮�� �Ʒ��� �ִ��� �ҼӰ���� ����, ���� ��������

class MyPoint { // extends java.lang.Object�� �ڵ������� ��ӵ�
	double x, y;

	MyPoint(double _x, double _y) {
		x = _x;
		y = _y;
	}

	@Override // equals ������ �ؾ� ��� ����
	public boolean equals(Object obj) {
		if (!(obj instanceof MyPoint))
			return false;

		MyPoint in = (MyPoint) obj;

		if (this.x == in.x && this.y == in.y)
			return true;

		return false;

	}

	@Override
	public String toString() {
		// ���� � Ŭ�������� �˷��ִ� getClass()�� �̸��� �˷��ִ� toString()
		return this.getClass().toString() + "(" + x + " , " + y + ")";
	}
}

public class MyApp {

	public static void main(String[] args) {
		int x = 10;
		int y = 20;
		// int z = sejonguniv.software.MyMath.add(x,y); // �ٸ� ��Ű����� �׻� Ǯ�������� ȣ���ؾ���
		int z = MyMath.add(x, y); // ����Ʈ�� ���� �ٿ� �� �� ����
		int w = MyCalc.mul(x, y); // ���� ��Ű����� �׳� ��� ����

		System.out.println(z);
		System.out.println(w);

		MyPoint p = new MyPoint(1, 2);
		MyPoint p2 = new MyPoint(1, 2);

		if (p == p2) // ���۷��� "�ּ�"�� ������ �ٸ��� ��
			System.out.println("equal");
		else
			System.out.println("Not equal");

		if (p.equals(p2)) // ������ ��
			System.out.println("equal");
		else
			System.out.println("Not equal");

		System.out.println(p); // print�� Ŭ���� ��ü�� ���ڷ� �Ѿ���� �ڵ����� toString()ȣ��
		System.out.println(p.hashCode()); // �����͸� ������ �ٲ��ִ� �޼ҵ�
	}

}
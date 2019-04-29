class MyMath {
	static float pow(float in, int p) {
		float out = 1;
		for (int i = 0; i < p; i++)
			out *= in;
		return out;
	}
	// �ڹٿ��� �����Լ��� ���� ������ Ŭ���� �ӿ� �־����
	// ����ƽ���� �����ؾ� Ŭ���� ��.�Լ�() ���� ������
	// ��ü�� ���� ������ ���� Ŭ�������� ��� (math Ŭ����)
}

class Circle {
	public double radius = 12; // �ڹٴ� �̷� ����� �ʱ�ȭ�� ������
	String name;
	static int repeat = 1; // static ������ new�� ���� ��ü�� ����� ���� �̹� �������. 1���� ��������� ��� ��ü���� ������
	// ���������� ���

	Circle() {
		name = "untitled";
	}

	Circle(int _r, String _n) {
		radius = _r;
		name = _n;
	} // ���� �̸��� �Լ��� ������ ����� �� = �����ε�
		// ���ڸ� ���� �˾Ƽ� ��� �����

	void copyForm(Circle in) {
		radius = in.radius;
		name = new String(in.name); // Ŭ������ ����� �̷��� ���� �Ҵ��ϰ� �����ؾ���
	}

	void print() {
		System.out.println("Circle: " + name + ", r = " + radius);
	}

	static void printRepeat() {
		System.out.println("repeat" + repeat);

	} // ����ƽ �Լ��� ����ƽ �Լ��� ȣ�� ����
}

public class MySecondClass {

	public static void main(String[] args) {
		Circle a = new Circle();
		Circle b = new Circle(100, "��붱");
		// b = a; // b�� a�� ����Ű�� �ٲ�� ������ a�� �ٲ�� b�� �ٲ�. ���簡 �ƴ�

		Circle.repeat = 2; // static������ Ŭ���� �̸��� ���ؼ��� ���� ����
		//Circle.repeat();

		a.name = "����";

		a.print();
		b.print();

		// String str = "�������б�";
		// String str = new String("�������б�"); �� �ΰ��� ����.

		b.copyForm(a); // ���� �Լ��� ����� ���
		b.print();

		Circle[] c = new Circle[10]; // ���۷��� �迭

		// c[0].radius = 10; // ���۷��� ������ �ʱ�ȭ ���� ���µ� ���� �� �� ����. ������Ʈ�ͼ��� ���� �߻�

		for (int i = 0; i < 10; i++)
			c[i] = new Circle(); // ���� �ʱ�ȭ�� ����� ��� ����

		c[0].radius = 10;

	}

}

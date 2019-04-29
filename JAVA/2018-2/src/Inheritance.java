
class ColorPoint extends Point { // point Ŭ������ Ȯ�� ���� ColorPoint Ŭ������ ���� (���)
	String color;

	ColorPoint() // �⺻���� �θ��� ����Ʈ �����ڸ� ȣ����
	{
		// super(); �� �⺻���� �����־� ������ ���� ���� �����
		color = "white";
	}

	ColorPoint(double _x, double _y) {
		// this(); �� super(); �� �� ���ٿ� �־�� �ϹǷ� ���ÿ� ��� ����
		super(_x, _y); // �θ�Ŭ������ �����ڸ� ȣ�� �� �� super()�� ���
		color = "white";
	}

	ColorPoint(double _x, double _y, String _color) {
		super(_x, _y);
		color = _color;
	}

	void ColorPrint() {
		print(); // �÷������Ϳ��� �����Ǿ����� ������ ������ Ŭ������ �����Ǿ��ִ� �Լ� ��� ����
		System.out.println("color -> " + color);
	}

	@Override // �� �ܾ ������ �����Ϸ��� �ٷ� �� �Լ��� �θ� �����ϴ� �Լ��� �ִ��� �˷��� -> ��Ż�� �߰� ����
	void print() // �Լ��̸��� ���� ����� �ڽ� �Լ��� �θ� �Լ��� �ٲ�ġ���� -> �������̵�
	{
		super.print(); // �θ��� �Լ��� ȣ���� �� super�� ����� ��������� ǥ����
		System.out.println("color -> " + color);
	}
}

class Point {
	final static double MAX_X = 100;
	final static double MAX_Y = 100;
	private double x, y; // �����ʹ� ���� �����̺����� ���Ƶΰ�

	Point() {
		setX(0);
		setY(0);
	}

	Point(double _x, double _y) {
		setX(_x);
		setY(_y);
	}

	// setter : mutator
	public void setX(double in) {
		x = (in < MAX_X) ? in : MAX_X;
	} // �Լ��� �̿��� ����ڰ� �ٲ� �� �ִ� ���� ������ ��

	public void setY(double in) {
		y = (in < MAX_Y) ? in : MAX_Y;
		;
	}

	// getter : accessor
	public double getX() {
		return x;
	}

	public double getY() {
		return y;
	}

	void print() {
		System.out.println(x + "," + y);
	}

	static double getDistance(Point a, Point b) {
		return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}
}

public class Inheritance {

	public static void main(String[] args) {

		Point a = new Point(50, 50);
		a.print();

		ColorPoint b = new ColorPoint();
		b.ColorPrint();
		b.print();
	
	
		System.out.println(Point.getDistance(a, b)); // b�� Į������Ʈ���� �θ�Ŭ������ �����͸� ������ �ֱ⿡ �ٷ� ��� ����
		
		Point c = b; // �ڽ�Ŭ���� �߿� �θ�Ŭ���� �κи� ���, �θ��� ���۷����� ������ �ڽ��� ����ų �� ���� sub->super : upcasting
	
		c.setX(10);
		c.print(); // ����Ʈ Ŭ���������� ������ ����Ű�� ������ Į������Ʈ Ŭ�����̱⿡ Į������Ʈ�� print()�� ȣ���
		// dynamic binding, polymorphism �̸��� ������ ����Ű�� ���뿡 ���� �ٸ��� ������
		
		//ColorPoint d = a; // �ڽ��� �θ� ����Ŵ down casting,�� �� ���� ���� ��ų �� �ֱ� ������ ���� // 
		ColorPoint d = (ColorPoint) c; // d->c->b �ᱹ b(colorPoint)�� ����Ű�⿡ ���� ����ȯ ��� ����
	}

}

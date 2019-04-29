
class Node { // ��ũ�� ����Ʈ ����, ���ø����� ���� �� ��� �ڷ������� ��� ����
	int value;
	Node next;

	void addTail(int v) {
		if (next == null) {
			Node n = new Node();
			n.next = null;
			n.value = v;
			this.next = n;
		} else {
			next.addTail(v);
		}
	}
}

class Box {
	int value;

	private Object value2;

	public Object getValue() {
		return value2;
	}

	public void setValue(Object in) {
		value2 = in;
	}

}

class Box2<T> { // ���ø� Ŭ����
	int value;

	private T value2;

	public T getValue() {
		return value2;
	}

	public void setValue(T in) {
		value2 = in;
	}
}

public class GeneralPractices {
	public static void func1(int x) {
		x = 20;
	}

	public static void func2(Box x) {
		x.value = 20;
	}

	public static String func3(String x) {
		x = "software";
		return x;
	}

	public static void main(String[] args) {
		int a = 10; // ���� �� ��ü�� �޸�
		func1(a); // �⺻���� �Լ����� �����ϴ� ����� �޶���
		System.out.println(a);

		Box b = new Box(); // b�� ������, new�� �޸𸮸� �Ҵ��ϰ� b�� ����Ŵ
		b.value = 10;
		func2(b); // �׻� �� ���� ���۷���
		System.out.println(b.value);

		// Integer c = new Integer("123");
		Integer c = Integer.valueOf("123"); // �� �ΰ��� ���� ���
		System.out.println(c);

		a = c; // unboxing wrapper -> �⺻Ÿ��
		c = a; // boxing �⺻Ÿ�� -> wrapper

		float d = c.floatValue();
		System.out.println(d);

		String str = "sejog univ.";
		str = func3(str); // string�� �ٲٱ� ���ؼ� ���ϰ����� x�� ����Ű�� ��ġ�� ��ȯ����� ��
		System.out.println(str);

		Box e = new Box();
		e.setValue("park"); // Object�� ������ ��� �� �� ������ �� ������
		String str2 = (String) e.getValue(); // ���� �� �����ڰ� ���� ��������� -> �Ǽ����ɼ� ����
		System.out.println(str2);

		Box2<String> f = new Box2<String>(); // �̶� <T>�� String���� �ٲ� ���� Ŭ������ �������
		f.setValue("kim");

		Box2<Integer> g = new Box2<>(); // Ŭ������ ����, int �Ұ���
		g.setValue(123);

		Node n = new Node();

		n.value = 10;
		n.next = null;

		n.addTail(20);
		n.addTail(30);
		n.addTail(40);

		Node it = n;
		while (it != null) {
			System.out.println(it.value);
			it = it.next;
		}
	}
}

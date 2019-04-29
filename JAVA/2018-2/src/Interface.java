import java.util.Arrays;

interface Printable {
	void print();
}

class Stu implements Printable, Comparable {
	String name;
	int num;

	Stu(String _name, int _num) {
		name = _name;
		num = _num;
	}

	public void print() // �������̽� ����
	{
		System.out.println(name + " : " + num);
	}

	@Override
	public int compareTo(Object o) { // ������ ���� �� �������̽� ����
		// ���� ������ -1, ũ�� 1, ������ 0
		Stu in = (Stu) o; // �л��� ���Ұ� Ȯ���ϴϱ� �ٿ�ĳ����

		if (this.num > in.num)
			return 1;
		if (this.num < in.num)
			return -1;
		return 0;
		// return (this.num - in.num);
	}
}

class Car implements Printable {
	String maker;
	private String model;
	CarModel carModel;

	class CarModel {
		String name;
		int year;

		CarModel() {
			name = new String(model); // ����
			// �ٸ� Ŭ�����ӿ��� ���� Ŭ������ private ���� ����
		}
	}

	Car(String _model, String _maker) {
		model = _model;
		maker = _maker;
	}

	public void print() {
		System.out.println(model + " : " + maker);
	}
}

class Welcome implements Printable {
	public void print() {
		System.out.println("welcome");
	}
}

public class Interface {

	public static void networkPrint(Printable p) {
		System.out.println("======");
		p.print();
	}

	public static void main(String[] args) {

		Stu a = new Stu("park", 100);
		Car c = new Car("sonata", "hyundai");

		Object o[] = new Object[2];
		o[0] = a;
		o[1] = c;

		for (int i = 0; i < o.length; i++) {
			if (o[i] instanceof Printable) {

				((Printable) o[i]).print();
			}
		}

//		Printable o[] = new Printable[2];
//		o[0] = a;
//		o[1] = c;
//		
//		for(int i = 0; i < o.length; i++)
//			o[i].print();

		Stu arr[] = new Stu[3];
		arr[0] = new Stu("Kim", 300);
		arr[1] = new Stu("Lee", 100);
		arr[2] = new Stu("Park", 200);

		Arrays.sort(arr);

		for (int i = 0; i < arr.length; i++)
			arr[i].print();

		networkPrint(arr[0]);

		// �Ʒ�ó�� �ѹ��� ���� ���ؼ� Ŭ������ ����� ��ü�� �����ϱ� ����, ���� Ŭ���� ���, 1ȸ��
		Welcome w = new Welcome();
		networkPrint(w);
		networkPrint(new Welcome());

		String name = "TEMP";
		Printable p = new Printable() {
			public void print() {
				System.out.println("Thx!" + name);
			}
		};

		networkPrint(p);

		networkPrint(new Printable() {
			public void print() {
				System.out.println("Thx!");
			}
		});
	}
}

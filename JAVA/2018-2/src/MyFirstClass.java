// ���� ������ : public - ������, protected - ��ӳ���, private - ����, ���� - ���� ��Ű������
// �ۺ� Ŭ������ �ϳ��� �ڹ����Ͽ� 1���� �����ϸ� �����̸��� ���ƾ���

class Student {
	public String name; // fields
	private int number;

	Student() {// �⺻�����ڴ� �ٸ� �����ڰ� ������ ���� ����������, �ٸ� �����ڰ� ���ٸ� �ڵ����� ��������
		name = "����";
	}

	Student(String _name, int _num) {
		name = _name;
		number = _num;
	} // �����ڰ� ������ �� �μ����� �� �ʿ���

	Student(int _num) {
		name = "����";
		number = _num;
	} // overloading ���� �̸��� �Լ��� �ߺ��ؼ� ��밡�� - ���ڴ� ������ �޶����

	void print() { // methods
		System.out.println("�̸�: " + name + ", �й� : " + number);
	}
}

public class MyFirstClass {

	public static void main(String[] args) {

		//Student a = new Student(); // �����ڰ� �������� �ʱ� ������ �����Ұ���
		Student a = new Student("�ڻ��", 1); // ����Ÿ���� Ŭ������ new�� ���� ����Ű�� �ؾ� ��밡��
		Student b = a; // b�� a�� ����Ű�⿡ b�� �ٲٸ� a�� �ٲ�
		Student c = new Student("�̿���", 1);
		
		a.name = "�ڻ��";
		//a.number = 1;
		
		b.name = "��ö��";
		//b.number = 2;
		
		//System.out.println("�̸�: " + a.name + ", �й� : " + a.number);
		//System.out.println("�̸�: " + b.name + ", �й� : " + b.number);
		//private�� number������ ��� �Ұ���
		a.print();
		b.print();
		c.print();
		
	}

}

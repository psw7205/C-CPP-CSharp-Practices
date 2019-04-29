class Point2D {
	double x, y;

	static double getDistance(Point2D a, Point2D b) {
		return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));

	} // 2���� �Ÿ��� ���ϴ� �Լ�

	double getDistanceFromMe(Point2D in) {
		return getDistance(this, in); // ���� in������ �Ÿ��� return, �Լ��� ����
	} // ���� �� ������ �Ÿ�
} // this���۷��� ��� ����

//regNum should be unique
// if regNum is not ready, you can not make a client

class Client {
	static int numClient = 0;
	final static int OFFSET = 100;

	String name; // �̸�
	String tel; // ��ȭ��ȣ
	int regNum; // ����ȣ, �ߺ��Ǹ� �ȵ�, ��ȣ�� ��������� ��������

	private Client() {
		numClient++;
		regNum = numClient + OFFSET;
	} // �̸��̳� ��ȣ�� �־�߸� ���������ؾ��ϹǷ� private�� 

	Client(String _name) {
		this();
		name = _name;
	}

	Client(String _name, String _tel) {
		this(_name); // �����ڿ��� �ٸ� �����ڸ� ȣ���� �� ���
		tel = _tel;
	} // �ڵ� ���� ����

	void print() {
		System.out.println("����ȣ " + regNum + " �̸� " + name);

		if (isLastClient(this)) { // this�� ����
			System.out.println("-------------------------------------------------------");
		}
	}

	static boolean isLastClient(Client in) {
		if (numClient + OFFSET == in.regNum)
			return true;
		return false;
	}
}

public class ClassPractice {

	public static void main(String[] args) {

		Client[] client = new Client[3];

		client[0] = new Client("david");
		client[1] = new Client("albus");
		client[2] = new Client("boris");

		for (int i = 0; i < 3; i++) {
			client[i].print();
		}

		Client.isLastClient(client[2]);
	}

}

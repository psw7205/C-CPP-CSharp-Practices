package homework1;

import java.util.Scanner;

class MyConcertMenu { // �޴��� �����ϴ� Ŭ�����Դϴ�.

	MySeat seat[] = new MySeat[3]; // 3������ �¼��� �ֽ��ϴ�.
	Scanner in = new Scanner(System.in);

	MyConcertMenu() {
		for (int i = 0; i < seat.length; i++) {
			seat[i] = new MySeat(); // �����ڸ� �̿��� ���� �ʱ�ȭ�մϴ�.
		}
	}

	boolean Reserve() { // ����޴��Դϴ�.
		System.out.print("�¼� ���� S(1), A(2), B(3)>>");
		int classNum = in.nextInt(); // � ������ �¼����� �Է¹޽��ϴ�.
		switch (classNum) {
		case 1:
			System.out.print("S>>");
			break;
		case 2:
			System.out.print("A>>");
			break;
		case 3:
			System.out.print("B>>");
			break;
		default:
			System.out.println("�߸��� �¼��Դϴ�."); // �߸��� ��ȣ�� ������ 
			return false; //������ ����ϰ� false�� �����մϴ�.
		}

		seat[classNum - 1].PrintMySeat(); // ���� �¼��� ���¸� ��Ÿ���ϴ�.

		boolean tmp = false;

		System.out.print("�̸�>>");
		String name = in.next(); // �̸��� �Է¹ް�

		while (tmp == false) { // ����� ������ ��(SetMySeat �Լ����� true����)���� ��� �Է¹޽��ϴ�.
			System.out.print("��ȣ>>"); // ��ȣ�� �Է¹޽��ϴ�.
			int num = in.nextInt(); 
			tmp = seat[classNum - 1].SetMySeat(name, num - 1);
		}
		return true;
	}

	void CheckMySeat() { // ��ȸ�޴��Դϴ�.
		System.out.print("S>>"); // �� ������ �¼��� ���� ����մϴ�.
		seat[0].PrintMySeat(); 
		System.out.print("A>>");
		seat[1].PrintMySeat();
		System.out.print("B>>");
		seat[2].PrintMySeat();
		System.out.println("<<<��ȸ�� �Ϸ��߽��ϴ�>>>");
	}

	boolean CancleMySeat() { // ��Ҹ޴��Դϴ�.
		System.out.print("�¼� ���� S(1), A(2), B(3)>>");

		int classNum = in.nextInt(); // ����޴��� ���� �����մϴ�.

		switch (classNum) {
		case 1:
			System.out.print("S>>");
			break;
		case 2:
			System.out.print("A>>");
			break;
		case 3:
			System.out.print("B>>");
			break;
		default:
			System.out.println("�߸��� �¼��Դϴ�.");
			return false;
		}

		seat[classNum - 1].PrintMySeat();

		boolean tmp = false;

		while (tmp == false) { // �̸��� �Է¹޴µ� 
			System.out.print("�̸�>>");
			String name = in.next();
			tmp = seat[classNum - 1].DeleteMySeat(name); // �̸��� ����� �������ų�

			if (seat[classNum - 1].isEmpty() == true) { // �¼��� ��� ��������� �����մϴ�.
				break;
			}
		}
		return true;
	}
}

class MySeat { // �¼��� �����ϴ� Ŭ�����Դϴ�.

	String seat[] = new String[10]; // �� 10���� �¼��Դϴ�. 

	MySeat() {
		for (int i = 0; i < seat.length; i++) {
			seat[i] = " --- "; // �����ڸ� �̿��� " --- "�� �ʱ�ȭ�մϴ�.
		}
	}

	boolean isEmpty() { // �¼��� ����ִ��� �˻��ϴ� �޼ҵ��Դϴ�.
		int i = 0;

		for (i = 0; i < seat.length; i++) {
			if (seat[i] != " --- ") {
				break;
			}
		} // " --- "�� �ƴ϶�� �̸��� �ԷµǾ��ִ� ����Դϴ�.

		if (i == seat.length) { // i�� ���̸�ŭ ������ ���� 
			return true; // ������ ���� " --- "�̹Ƿ� �� �¼��� ����ִ� ����Դϴ�.
		} else {
			return false;
		}
	}

	boolean SetMySeat(String _name, int _num) { // �¼� ��ȣ�� �̸��� ���ڷ� �¼��� �����ϴ� �޼ҵ��Դϴ�.
		if (_num < 0 || _num >= 10) { // 1~10�� �ƴ� ��ȣ�� ������ ����
			System.out.println("�߸��� �¼���ȣ�Դϴ�.");
			return false;
		}

		if (seat[_num] != " --- ") { // " --- "�� �ƴϸ� �̹� ����� �¼��Դϴ�.
			System.out.println("�̹� ����� �¼��Դϴ�.");
			return false;
		}
		// �� �� ��찡 �ƴ϶�� �̸��� �����ϰ� true�� �����մϴ�.
		seat[_num] = _name;
		return true;
	}

	void PrintMySeat() { // foreach���� �̿��� ��� ���� ����մϴ�.
		for (String s : seat) {
			System.out.print(s);
		}

		System.out.println();
	}

	boolean DeleteMySeat(String _name) { // �¼����� �ش� �̸��� ����� �޼ҵ��Դϴ�.
		for (int i = 0; i < seat.length; i++) {
			if (seat[i].equals(_name) == true) { // �̸��� �߰��ϸ� 
				seat[i] = " --- "; // " --- "�� �ʱ�ȭ�ϰ� true�� �����մϴ�.
				return true;
			}
		}
		// ������ ��ȯ���� �ʴ´ٸ� �̸��� ���� ���Դϴ�.
		System.out.println("�̸��� �����ϴ�."); // false�� �����մϴ�. 
		return false;
	}
}

public class Hw1_5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("��ǰ�ܼ�ƮȦ ���� �ý����Դϴ�.");

		MyConcertMenu menu = new MyConcertMenu(); // �޴��� �����մϴ�. 

		while (true) {
			System.out.print("����1, ��ȸ:2, ���:3, ������:4>>");

			int num = in.nextInt();

			if (num == 4) { // 4�� �ԷµǸ� ���ѹݺ��� Ż���ϰ� �����մϴ�.
				break;
			}

			boolean tmp = true;

			switch (num) {
			case 1:
				tmp = menu.Reserve(); // 1�� �ԷµǸ� ������ �����ϰ�

				while (tmp == false) { // ����� ���� �� ������ �Է¹޽��ϴ�.
					tmp = menu.Reserve();
				}
				break;
			case 2:
				menu.CheckMySeat(); // ��ȸ�� �����մϴ�.
				break;
			case 3:
				tmp = menu.CancleMySeat(); // ����� ���������� ��ҵ� 

				while (tmp == false) { // ����� ��� �� ������ �Է¹޽��ϴ�.
					tmp = menu.CancleMySeat();
				}
				break;
			default: // 1, 2, 3�� �ƴϸ� �߸��� �Է��Դϴ�.
				System.out.println("�߸��� �Է��Դϴ�.");
				break;
			}
		}

		in.close();
	}
}
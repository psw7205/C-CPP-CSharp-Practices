package homework1;

import java.util.Scanner;

public class Hw1_2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("����>>");

		double a = in.nextDouble();
		String op = in.next();
		double b = in.nextDouble();

		if (b == 0) { // 0���� ������ ���
			System.out.println("0���� ���� �� �����ϴ�.");
		} else { // �ƴҰ��
			System.out.print(a + op + b + "�� ��� ����� ");

			if (op.equals("+") == true) {
				System.out.println(a + b);
			} else if (op.equals("-") == true) {
				System.out.println(a - b);
			} else if (op.equals("*") == true) {
				System.out.println(a * b);
			} else { // �����ڰ� �� 4������ �����⿡ ������� else�� ����߽��ϴ�.
				System.out.println(a / b);
			}
		}
		in.close();
	}
}
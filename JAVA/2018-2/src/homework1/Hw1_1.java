package homework1;

import java.util.Scanner;

public class Hw1_1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("ù��° ���� �߽ɰ� ������ �Է�>>");

		double x = in.nextDouble();
		double y = in.nextDouble();
		double r = in.nextDouble();

		System.out.print("�ι�° ���� �߽ɰ� ������ �Է�>>");

		double x1 = in.nextDouble();
		double y1 = in.nextDouble();
		double r1 = in.nextDouble();

		double tmp = Math.sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));

		if (tmp < r + r1) {
			System.out.println("�� ���� ��Ĩ�ϴ�.");
		} else {
			System.out.println("�� ���� ��ġ�� �ʽ��ϴ�.");
		}

		in.close();

	}

}

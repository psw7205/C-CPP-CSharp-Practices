package homework1;

import java.util.Scanner;

public class Hw1_3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("���� �>>");

		int n = in.nextInt();

		int ar[] = new int[n];

		for (int i = 0; i < n; i++) {
			ar[i] = (int) (Math.random() * 100 + 1); // 1~100���� ���� ���� �����մϴ�.
			for (int j = 0; j < i; j++) { // ���߹ݺ����� �̿��� �տ��� ���� ��ġ���� Ȯ���ϴµ�
				if (ar[j] == ar[i]) { // �ߺ��� ���� �տ��� ���� ���
					i--; // i�� 1 �ٿ� �ٽ� �� ��ġ�� ���� ���� �����մϴ�.
					break;
				}
			}
		}

		int cnt = 0;

		for (int x : ar) {
			if (cnt % 10 == 9) { // å�� ����ó�� ǥ���ϱ� ���� 10ĭ�� ���� ǥ���߽��ϴ�.
				System.out.println(" " + x);
			} else {
				System.out.print(" " + x);
			}
			cnt++;
		}

		in.close();
	}
}
package homework1;

public class Hw1_4 {

	public static void main(String[] args) {

		int ar[][] = new int[4][4]; // 4X4����Դϴ�.

		for (int i = 0; i < 10; i++) {
			int x = (int) (Math.random() * 4); // 0~3���� ������ǥ�Դϴ�.
			int y = (int) (Math.random() * 4);

			while (ar[x][y] != 0) { // �ش� ��ǥ�� ���� 0�� �ƴϸ� �̹� �ٸ� ���� ���� �ִ� ����Դϴ�.
				x = (int) (Math.random() * 4); // �ش� ��ǥ ���� 0�� �� ������ �������� x, y�� �����մϴ�.
				y = (int) (Math.random() * 4);
			}

			ar[x][y] = (int) (Math.random() * 10 + 1); // 1~10���� ���� ���� �����մϴ�.
		}

		for (int i = 0; i < ar.length; i++) {
			for (int j = 0; j < ar[i].length; j++)
				System.out.print(ar[i][j] + "\t");
			System.out.println();
		}
	}
}


public class MyFirstArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		double pi = 0.0;
		final int ITER_MAX = 10000; // ���

		double sign = 1.0;

		for (int i = 0; i < ITER_MAX; i++) {
			double inc = 4.0 / (2 * i + 1);
			pi += (sign * inc);
			sign *= (-1.0);
			System.out.println("iter " + i + " : " + pi);
		}

		// int arr[10]; c ���� �Ҵ�
		// int* arr = (int*)malloc(sizeof(int)*10); c �����Ҵ�
		// int* arr = new int [10]; c++ �����Ҵ�

		int size = 10;
		int[] arr = new int[10];
		int arr2[] = new int[size]; // �ڹٿ��� �Ѵ� ��� ����
		int brr[] = arr; // ���� ������ ����Ŵ

		for (int i = 0; i < arr.length; i++) { // �迭�� �ɹ������� ���̸� ������ ����
			arr[i] = 2 * i;
		}

		for (int i = 0; i < size; i++) {
			System.out.println(arr[i]);
		}

		arr2 = new int[5]; // ���ӰԵ� �Ҵ� ����

		for (int i = 0; i < size; i++) {
			System.out.println(brr[i]);
		}

		// �޸� ������ free�� delete �ʿ� ���� �˾Ƽ� �������÷����� ������ �ش�. garbage collection

		for (int elem : arr) // arr�� ����ִ� ��� ������ ���Ҹ� elem�� �����ؼ� ������� ����
		{ // foreach�� �б� ���� ���� �Ұ�
			System.out.println(elem);
		}

		String names[] = { "���", "��", "����", "����" };
		for (String elem : names) {
			System.out.println(elem); // ��Ʈ��, enum�� ��� Ÿ�Կ� ���� ��� ����
		}

		int arr2d[][] = new int[2][5]; // 5���� 2���� {{ 1,2,3,4,5 } , {1,2,3,4,5} }
		int brr2d[][] = new int[4][]; // 4������ ����µ� �� ������ ���� ����
		brr2d[0] = new int[10]; // 0��° ������ 10��
		brr2d[1] = new int[30]; // 1��° ������ 30��

	}

}

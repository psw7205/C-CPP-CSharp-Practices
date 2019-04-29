import java.util.Scanner;

class MyArrayIdxNegativeException extends Exception {
// Exception�� ��ӹ޾� ���ο� ����ó�� Ŭ������ ���� �� ����
}

class MyArrayIdxtoBigException extends Exception {

}

public class ExceptionPractice {

	// c���� ����ϴ� ����ó�� ���
	public static boolean setInput(int arr[], int idx, int value) {
		if (idx < 0 || idx > arr.length - 1)
			return false;

		arr[idx] = value;
		return true;
	}

	public static void setInput2(int arr[], int idx, int value)
			throws MyArrayIdxNegativeException, MyArrayIdxtoBigException {
		// throws�� ������ ������ ����ó���� �������, ������ thorw �� �� ����
		if (idx < 0) {
			MyArrayIdxNegativeException e = new MyArrayIdxNegativeException();
			throw e;
		}

		if (idx > arr.length - 1) {
			MyArrayIdxtoBigException e = new MyArrayIdxtoBigException();
			throw e;
		}

		arr[idx] = value;
	}

	public static void main(String[] args) {

		/*
		 * int x = 10; int y = 0; int z = 0;
		 * 
		 * try { z = x / y; // 0���� ������ } catch (ArithmeticException e) { z = 0; }
		 * 
		 * int arr[] = new int[10];
		 * 
		 * try { arr[10] = 100; // �迭 �ε��� ���� �ۿ� ���� } catch
		 * (ArrayIndexOutOfBoundsException e) { System.out.println("Wrong Array index");
		 * }
		 * 
		 * Scanner input = null; // null �����͸� ����� input.nextInt();
		 */

		int arr[] = new int[10];

		if (!setInput(arr, 10, 100))
			System.out.println("error");
		// c���� ����ϴ� ���� üũ ���, ���� : � ������ ������� ��, ������ boolŸ���̱⿡ �ٸ� ���ϰ��� �� ������

		int arr2[] = new int[10];

		try {
			setInput2(arr2, 1, 100);
			int x = 10;
			int y = 0;
			int z = x / y;
		} catch (MyArrayIdxNegativeException e) {
			System.out.println("Negative index error !");
		} catch (MyArrayIdxtoBigException e) {
			System.out.println("Too Big index error !");
		} catch (ArithmeticException e) {
			System.out.println("Do not divide by zero !");
		} catch (Exception e) {
			System.out.println("������ ���� �� ����");
			// �갡 �� ���� ������ �갡 ������ �� �ޱ⿡ ������ �������� ó���� �ȵ�
		}

	}

}
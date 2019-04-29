import java.util.ArrayList;

class SharedData {
	int sum = 0;

	// critical section : ����� �ϴ� ���� �ƹ��� ���� ���ϰ� ���ƾ��� -> Lock, Unlock�� ���� �ذ�
	// Synchronization : ����ȭ�� ���� �ذ�
	synchronized public void add() {
		// �Լ���ü, Ư���κи� ���� ����, �ٸ� �������� �ǹ̰� �����
		synchronized (this) {
			int n = sum;
			n += 10;

			// System.out.print(Thread.currentThread().getName());
			// System.out.println(" Sum : " + n);

			try {
				Thread.sleep((int) (Math.random() * 10));
			} catch (InterruptedException e) {
				e.printStackTrace();
			}

			sum = n;
		}
		
		System.out.print(Thread.currentThread().getName());
		System.out.println(" Sum : " + sum); // �����Ͱ� �����Ǳ⿡ �����Ǳ� ���� �ٸ� ������ ���� ���� �̻�����
	}
}

class MyAddingThread extends Thread {
	SharedData d;

	MyAddingThread(String name, SharedData in) {
		super(name);
		d = in;
	}

	@Override
	public void run() {
		for (int i = 0; i < 100; i++)
			d.add();
	}
}

public class ThreadSync {

	public static void main(String[] args) {
		SharedData d = new SharedData();

		System.out.println(Thread.currentThread().getName());

		MyAddingThread t = new MyAddingThread("A", d);
		MyAddingThread t2 = new MyAddingThread("B", d);
		MyAddingThread t3 = new MyAddingThread("C", d);
		MyAddingThread t4 = new MyAddingThread("D", d);
		t.start();
		t2.start();
		t3.start();
		t4.start();
		
	}

}

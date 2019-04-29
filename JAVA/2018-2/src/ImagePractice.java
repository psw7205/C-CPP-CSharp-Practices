import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;

class ImagePracticePanel extends JPanel {

	BufferedImage img;

	ImagePracticePanel() {
		try {
			img = ImageIO.read(new File("1.png"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		// g.drawImage(img,20,20, null); // 20, 20 ��ǥ���� �̹��� �׸�
		// g.drawImage(img, 100, 100, 100, 100, null); // 100,100��ǥ���� 200 200 ũ�⸸ŭ �׸�
		// g.drawImage(img, 0, 0, getWidth(), getHeight(), null); // ȭ�� ���� ä���
		// g.drawImage(img, 100, 100, 300, 300, 0, 0, 200, 200, null); // �̹����� 0,0 ~
		// 400,400 ��ŭ �߶� �׸���

		int divX = 4;
		int divY = 4;
		int dw = img.getWidth() / divX;
		int dh = img.getHeight() / divY;
		int offset = 10;
		int num = divX * divY;
		int idx[] = new int[num];

		int drawIdx = 0;
		for (int i = 0; i < num; i++)
			idx[i] = i;

		for (int i = 0; i < num; i++) {
			int j = (int) (Math.random() * num);
			int tmp = idx[j];
			idx[j] = idx[i];
			idx[i] = tmp;
		}

		for (int i = 0; i < divX; i++) {
			for (int j = 0; j < divY; j++) {
				int dx = (dw + offset) * i;
				int dy = (dh + offset) * j;
				int sx = dw * (idx[drawIdx] / divY);
				int sy = dh * (idx[drawIdx] % divY);

				g.drawImage(img, dx, dy, dx + dw, dy + dh, sx, sy, sx + dw, sy + dh, null);

				drawIdx++;
			}
		}

	}
}

class MyThread extends Thread {
	String name;

	@Override
	public void run() {
		for (int i = 0; i < 100; i++) {
			System.out.println(name + i);
			for (int j = 0; j < 10000000; j++)
				; // �۾����� �÷� ��Ƽ�������� Ȯ���� �������� �ݺ���

		}
	}
}

public class ImagePractice extends JFrame implements Runnable {

	ImagePractice() {
		setTitle("Image Practic");
		setSize(700, 700);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		ImagePracticePanel p = new ImagePracticePanel();
		add(p);

		setVisible(true);
	}

	public static void main(String[] args) {
		ImagePractice f = new ImagePractice();

		MyThread t1 = new MyThread();
		t1.name = "t1 : ";

		MyThread t2 = new MyThread();
		t2.name = "t2 : ";

		Thread t3 = new Thread(f); // Runnable �������̽� ����
		Thread t4 = new Thread(new Runnable(){
			@Override
			public void run() {
				// ����
			}
		});
		
		t1.start(); // �۾��ڸ� ���ؿͼ� ���� ��Ŵ
		t2.start(); // run()�� ���� �θ��� �� �ȵ�, ���ο��� �Լ�ȣ���ϴ� ���̱⿡ ��Ƽ������ X
		t3.start();
		t4.start();
	}

	@Override
	public void run() {
		for (int i = 0; i < 100; i++) {
			System.out.println("t3 : " + i);
			for (int j = 0; j < 10000000; j++)
				;
		}

	}
}

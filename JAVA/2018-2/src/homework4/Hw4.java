package homework4;

import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

// ����� ǥ���� �г��Դϴ�
class Hw4ResultPanel extends JPanel {
	String result; // ������� ǥ���� ���ڿ��Դϴ�

	Hw4ResultPanel() {
		result = "0"; // �� ó�� 0���� �ʱ�ȭ�մϴ�
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D) g;

		int w = this.getWidth();
		int h = this.getHeight(); // �г��� ũ�⸦ ���Խ��ϴ�

		int tmpRatio = h / 10; // ȭ���� ũ�Ⱑ ���ϸ� ��Ʈ������, ������� ���� ���ؾ��ϱ⿡ ������ �����߽��ϴ�
		int fontSize = tmpRatio * 6;
		g2.setFont(new Font("Arial", Font.PLAIN, fontSize)); // ������ ũ���� ��Ʈ�� �����߽��ϴ�

		FontMetrics tmp = g2.getFontMetrics(); // ������ ������ ���� �۲��� ������ ���ɴϴ�

		int sx = w - tmpRatio; // ó�� ������ġ�� ������ ������ ��¦ ��������
		int sy = h / 2 + tmp.getAscent() / 2; // �߰����� �����մϴ�

		for (int i = 0; i < result.length(); i++)
			sx -= tmp.charWidth(result.charAt(i)); // �� ������ ���̸�ŭ �������� �������� �̵����� �׻� ������ ������ �ǵ��� �߽��ϴ�

		GradientPaint grayToDarkGray = new GradientPaint(0, 0, Color.GRAY, 0, h, Color.DARK_GRAY);
		g2.setPaint(grayToDarkGray); // Graphcis2DŬ������ �׶��̼� ����Դϴ�
		g2.fillRect(0, 0, w, h); // �г� ���θ� ä��ϴ�

		g2.setColor(Color.WHITE);
		g2.drawString(result, sx + 1, sy + 1); // �׸����Դϴ�
		g2.setColor(Color.BLACK);
		g2.drawString(result, sx, sy); // ���ڿ��� ����մϴ�
	}
}

class Hw4Button extends JButton {
	Hw4Button() {
		this.setName("14"); // ���� ���� ��ư�� �̸��� 14�� �ʱ�ȭ�߽��ϴ�
		// "" �׳� �������� �����غ����� �ؿ� Name�� int������ ��ȯ�ϴµ� ""���� ������ ���� 14�� �ʱ�ȭ�ϰ�
		// ActionListener���� ó���߽��ϴ�
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);

		String str = this.getName(); // �� ��ư�� �̸��� �����Խ��ϴ�
		int w = this.getWidth();
		int h = this.getHeight(); // ��ư�� ũ�⸦ �����Խ��ϴ�
		int offset = h / 10; // ��ư�� ����κ��� ��ư ������ 1/10���� �����߽��ϴ�

		int fontSize = offset * 7;
		g.setFont(new Font("Arial", Font.BOLD, fontSize)); // ��ư����Ʈ�� �����߽��ϴ�

		g.setColor(new Color(255, 200, 150));
		g.fillRoundRect(offset, offset, w - offset * 2, h - offset * 2, 10, 10); // ��ư �� �ձٸ𼭸��� �簢���� �����մϴ�

		g.setColor(Color.BLACK);

		switch (Integer.parseInt(str)) { // �̸��� ������ ��ȯ���� ��
		case 10: // 10�̸� clear�Դϴ�
			str = "C";
			g.setColor(Color.WHITE);
			g.drawString(str, w / 2 - offset * 2, h * 3 / 4 + 1);
			g.setColor(new Color(200, 100, 100));
			g.drawString(str, w / 2 - offset * 2, h * 3 / 4); // ���ڸ� �����ϰ�
			return; // �����մϴ�
		case 11: // �������� ��� �׳� +, -, = �� str���ڿ��� �ٲٰ� switch���� Ż���մϴ�
			str = "+";
			break;
		case 12:
			str = "-";
			break;
		case 13:
			str = "=";
			break;
		case 14: // ���ư 2���� ����Դϴ�
			str = "";
			break;

		default:
			break;
		}

		g.setColor(Color.WHITE);
		g.drawString(str, w / 2 - offset * 2 + 2, h * 3 / 4 + 2);
		g.setColor(new Color(100, 100, 100));
		g.drawString(str, w / 2 - offset * 2, h * 3 / 4);
		// ���ڹ�ư�� ó������ ��ư�̸��� ���ڿ��� �������� switch������ ��ȯ�Ǿ����Ƿ� �״�� ����մϴ�

	}
}

class Hw4Panel extends JPanel implements ActionListener {

	Hw4Button button[] = new Hw4Button[16]; // ��ư 16���Դϴ�
	Hw4ResultPanel resultPanel; // ����� ����� �г��Դϴ�

	int preResult; // ���������
	int result; // �����
	int flag; // ������� �ٲ� �÷���
	int operation; // ������ ���� 1, -1
	static final double ratio = 0.75; // ���� �������Դϴ�

	Hw4Panel() {
		this.setLayout(null); // ��ġ�����ڸ� �����մϴ�
		operation = 1;
		flag = 0;

		resultPanel = new Hw4ResultPanel();
		this.add(resultPanel); // ��� �г��� �߰��մϴ�

		for (int i = 0; i < 16; i++) {
			button[i] = new Hw4Button();
			button[i].addActionListener(this);
			this.add(button[i]);
		} // ��ư 16���� �׼Ǹ����ʸ� ����ϰ� �гο� �߰��մϴ�

		button[3].setName("10"); // clear
		button[7].setName("11"); // +
		button[11].setName("12"); // -
		button[12].setName("0"); // 0
		button[15].setName("13"); // =

		for (int i = 0; i < 3; i++) {
			button[i].setName("" + (i + 7));
			button[i + 4].setName("" + (i + 4));
			button[i + 8].setName("" + (i + 1));
		} // ��ư�� �̸����� �����մϴ�

	}

	@Override
	public void actionPerformed(ActionEvent e) {

		Hw4Button btn = (Hw4Button) e.getSource(); // ���� �׼��� ��ư�ۿ� �����Ƿ� ��������ȯ �� ����߽��ϴ�
		int tmp = Integer.parseInt(btn.getName()); // ��ư�� �̸��� ������ ��ȯ�մϴ�

		if (tmp == 14)
			return; // 14�� ��� ���� ��ư�Դϴ� �ƹ��� ���� �����մϴ�

		switch (tmp) {

		case 10: // clear �� ���
			result = 0;
			preResult = 0;
			flag = 0;
			operation = 1;
			break; // �ʱ�ȭ �մϴ�

		case 11: // +
		case 12: // -
		case 13: // =
			preResult += result * operation; // ��������� ���� ����� ���ϰ�
			result = 0; // ���� ����� ���� ǥ���ϱ����� 0���� �ʱ�ȭ�մϴ�

			if (tmp == 11)
				operation = 1;
			if (tmp == 12) // -�� ���
				operation = -1; // operation�� -1�� ������ ������ ���ϱ⸸ �ϴ��� ������ �ǵ��� �߽��ϴ�

			flag = 0; // ������� ����ϱ����� 0���� �����մϴ�
			break;

		default:
			result = result * 10 + tmp; // ���� ���� ���ڸ� ����Ʈ�ϰ� ���մϴ�
			flag = 1; // ���� ��� ���� ����� ����ϱ����� 1�� �����մϴ�
			break;
		}

		if (flag == 0)
			resultPanel.result = String.valueOf(preResult); // ����������� �����մϴ�
		else
			resultPanel.result = String.valueOf(result); // ���� �Է����� ����� �����մϴ�

		this.repaint();
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D) g;

		Point topLeftPoint = new Point(); // ������ �»�� ��ǥ
		Point centerPoint = new Point(); // ������ �߽���ǥ
		int w; // ȭ���� ���α���
		int h; // ȭ���� ���� ����
		int calcWidth; // ������ ���α���
		int calcHeigh; // ������ ���α���

		w = this.getWidth();
		h = this.getHeight();
		centerPoint.x = w / 2;
		centerPoint.y = h / 2; // ���� �г��� ũ��� �߽ɰ��� �����մϴ�

		if (w / ratio > h) { // ���κ����� �� �� ���
			calcHeigh = h;
			calcWidth = (int) (h * ratio);
		} else { // ���ΰ� �� ���츦 ������ ��������� ������ ���°� �����ǰ� �����߽��ϴ�
			calcWidth = w;
			calcHeigh = (int) (w / ratio);
		}

		topLeftPoint.x = centerPoint.x - calcWidth / 2;
		topLeftPoint.y = centerPoint.y - calcHeigh / 2; // ������ �»���� �����մϴ�

		g2.setColor(Color.BLACK);
		g2.fillRect(0, 0, w, h); // �г� ��ü ����� �������� ĥ�մϴ�

		GradientPaint gradient = new GradientPaint(0, 0, new Color(40, 70, 70), 0, this.getHeight(),
				new Color(150, 150, 150));
		g2.setPaint(gradient);
		// Graphics2D�� �׶��̼��� �̿���
		g.fillRect(topLeftPoint.x, topLeftPoint.y, calcWidth, calcHeigh);
		// ��� ����� ����� �г��� ����� ĥ�մϴ�

		int offset = calcHeigh / 50;
		resultPanel.setBounds(topLeftPoint.x + offset, topLeftPoint.y + offset, calcWidth - offset * 2,
				calcHeigh / 3 - offset * 2);
		// ��� ����г��� ������ �����մϴ�
		resultPanel.repaint();

		int buttonStartX = topLeftPoint.x;
		int buttonStartY = topLeftPoint.y + calcHeigh / 3;
		int buttonWidth = calcWidth / 4;
		int buttonHeigh = calcHeigh * 2 / 3 / 4;
		// ��ư�� ������ǥ, ũ�⸦ �����մϴ�

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				button[i * 4 + j].setBounds(buttonStartX + j * (buttonWidth + 1), buttonStartY + i * (buttonHeigh + 1),
						buttonWidth, buttonHeigh);
				// ��ư�� �����鸦 �����մϴ�
				button[i].repaint();
			}
		}

	}

}

public class Hw4 extends JFrame {

	Hw4() {
		this.setTitle("Hw4");
		this.setSize(500, 500);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.add(new Hw4Panel());
		this.setVisible(true);
	}

	public static void main(String[] args) {
		new Hw4();
	}

}
